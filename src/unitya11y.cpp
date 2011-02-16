/*
 * Copyright (C) 2011 Canonical Ltd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Alejandro Piñeiro Iglesias <apinheiro@igalia.com>
 */

#include <glib.h>
#include <gio/gio.h>
#include <gmodule.h>
#include <stdio.h>

#include "unitya11y.h"
#include "unity-util-accessible.h"

/* nux accessible objects */
#include "nux-view-accessible.h"
#include "nux-base-window-accessible.h"
#include "nux-layout-accessible.h"

/* unity accessible objects */
#include "Launcher.h"
#include "LauncherIcon.h"
#include "unity-launcher-accessible.h"
#include "unity-launcher-icon-accessible.h"

static GHashTable *accessible_table = NULL;
/* FIXME: remove accessible objects when not required anymore */

static gboolean a11y_initialized = FALSE;

static void
unity_a11y_restore_environment (void)
{
  g_unsetenv ("NO_AT_BRIDGE");
  g_unsetenv ("NO_GAIL");
}

static void
load_unity_atk_util ()
{
  g_type_class_unref (g_type_class_ref (UNITY_TYPE_UTIL_ACCESSIBLE));
}

#define INIT_METHOD "gnome_accessibility_module_init"
#define DESKTOP_SCHEMA "org.gnome.desktop.interface"
#define ACCESSIBILITY_ENABLED_KEY "accessibility"
#define AT_SPI_SCHEMA "org.a11y.atspi"
#define ATK_BRIDGE_LOCATION_KEY "atk-bridge-location"

static gboolean
has_gsettings_schema (const gchar *schema)
{
  const char * const *list_schemas = NULL;
  gboolean found = FALSE;
  int i = 0;

  /* we need to check if AT_SPI_SCHEMA is present as g_setting_new
     could abort if the schema is not here*/
  list_schemas = g_settings_list_schemas ();
  for (i = 0; list_schemas [i]; i++)
    {
      if (!g_strcmp0 (list_schemas[i], schema))
        {
          found = TRUE;
          break;
        }
    }

  return found;
}

static gboolean
should_enable_a11y (void)
{
  GSettings *desktop_settings = NULL;
  gboolean value = FALSE;

  if (!has_gsettings_schema (DESKTOP_SCHEMA))
    return FALSE;
   
  desktop_settings = g_settings_new (DESKTOP_SCHEMA);
  value = g_settings_get_boolean (desktop_settings, ACCESSIBILITY_ENABLED_KEY);

  g_object_unref (desktop_settings);

  return value;
}

static gchar*
get_atk_bridge_path (void)
{
  GSettings *atspi_settings = NULL;
  char *value = NULL;

  if (!has_gsettings_schema (AT_SPI_SCHEMA))
    return NULL;

  atspi_settings = g_settings_new (AT_SPI_SCHEMA);
  value = g_settings_get_string (atspi_settings, ATK_BRIDGE_LOCATION_KEY);

  g_object_unref (atspi_settings);

  return value;
}

static gboolean
a11y_invoke_module (const char *module_path)
{
  GModule    *handle;
  void      (*invoke_fn) (void);

  if (!module_path)
    {
      g_warning ("Accessibility: invalid module path (NULL)");

      return FALSE;
    }

  if (!(handle = g_module_open (module_path, (GModuleFlags)0)))
    {
      g_warning ("Accessibility: failed to load module '%s': '%s'",
                 module_path, g_module_error ());

      return FALSE;
    }

  if (!g_module_symbol (handle, INIT_METHOD, (gpointer *)&invoke_fn))
    {
      g_warning ("Accessibility: error library '%s' does not include "
                 "method '%s' required for accessibility support",
                 module_path, INIT_METHOD);
      g_module_close (handle);

      return FALSE;
    }

  invoke_fn ();

  return TRUE;
}


/*
 * This unit test checks if the destroy management is working:
 *
 * - If the state of a accessibility object is properly updated after
 *   the object destruction
 *
 */
static gboolean
a11y_unit_test_destroy_management (void)
{
  QuicklistView *quicklist = NULL;
  AtkObject *accessible = NULL;
  nux::Object *base_object = NULL;
  AtkStateSet *state_set = NULL;

  quicklist = new QuicklistView ();
  quicklist->SinkReference ();
  accessible = unity_a11y_get_accessible (quicklist);

  base_object = nux_object_accessible_get_object (NUX_OBJECT_ACCESSIBLE (accessible));
  if (base_object != quicklist)
    {
      g_debug ("[a11y] destroy management unit test: base object"
               " different to the original one");
      return FALSE;
    }

  if (quicklist->UnReference () == false)
    {
      g_debug ("[a11y] destroy management unit test: base object not destroyed");
      return FALSE;
    }

  base_object = nux_object_accessible_get_object (NUX_OBJECT_ACCESSIBLE (accessible));
  if (base_object != NULL)
    {
      g_debug ("[a11y] destroy management unit test: base object"
               " not NULL after base object destruction");
      return FALSE;
    }

  state_set = atk_object_ref_state_set (accessible);
  if (!atk_state_set_contains_state (state_set, ATK_STATE_DEFUNCT))
    {
      g_debug ("[a11y] destroy management unit test: accessible object"
               " doesn't include DEFUNCT state");
      return FALSE;
    }

  g_object_unref (state_set);
  g_object_unref (accessible);

  return TRUE;
}

/**
 * This unit test checks if the hash table destroy management is working:
 *
 * - If the hash table removes properly the accessible object once it
 *   is destroyed.
 */
static gboolean
a11y_unit_test_hash_table_destroy_management (void)
{
  QuicklistView *quicklist = NULL;
  AtkObject *accessible = NULL;
  guint prev_hash_size = 0;
  guint hash_size = 0;

  /* test the hash table management with the accessible destroy */

  prev_hash_size = g_hash_table_size (accessible_table);

  quicklist = new QuicklistView ();
  quicklist->SinkReference ();
  accessible = unity_a11y_get_accessible (quicklist);

  if (accessible == NULL)
    {
      g_debug ("[a11y] hash table destroy management unit test: error creating"
               " the accessible object (accessible == NULL)");
      return FALSE;
    }

  hash_size = g_hash_table_size (accessible_table);

  if ((hash_size - prev_hash_size) != 1 )
    {
      g_debug ("[a11y] hash table destroy management unit test: accessible object"
               " not added to the hash table after his creation");
      return FALSE;
    }

  prev_hash_size = g_hash_table_size (accessible_table);

  g_object_unref (accessible);

  hash_size = g_hash_table_size (accessible_table);

  if ((prev_hash_size - hash_size) != 1 )
    {
      g_debug ("[a11y] hash table destroy management unit test: accessible object"
               " not removed from the hash table after his destruction");
      return FALSE;
    }

  quicklist->UnReference ();

  /* Test the hash table management after the object destroy */

  prev_hash_size = g_hash_table_size (accessible_table);

  quicklist = new QuicklistView ();
  quicklist->SinkReference ();
  accessible = unity_a11y_get_accessible (quicklist);

  if (accessible == NULL)
    {
      g_debug ("[a11y] hash table destroy management unit test: error creating"
               " the accessible object (accessible == NULL)");
      return FALSE;
    }

  hash_size = g_hash_table_size (accessible_table);

  if ((hash_size - prev_hash_size) != 1 )
    {
      g_debug ("[a11y] hash table destroy management unit test: accessible object"
               " not added to the hash table after his creation");
      return FALSE;
    }

  prev_hash_size = g_hash_table_size (accessible_table);

  if (quicklist->UnReference () == false)
    {
      g_debug ("[a11y] hash table destroy management unit test: base object not destroyed");
      return FALSE;
    }

  hash_size = g_hash_table_size (accessible_table);

  if ((prev_hash_size - hash_size) != 1 )
    {
      g_debug ("[a11y] hash table destroy management unit test: accessible object"
               " not removed from the hash table after base object destruction");
      return FALSE;
    }

  return TRUE;
}

void
unity_run_a11y_unit_tests (void)
{
  if (a11y_unit_test_destroy_management ())
    g_debug ("[a11y] destroy management unit test: SUCCESS");
  else
    g_debug ("[a11y] destroy management unit test: FAIL");

  if (a11y_unit_test_hash_table_destroy_management ())
    g_debug ("[a11y] hash table destroy management unit test: SUCCESS");
  else
    g_debug ("[a11y] hash table destroy management unit test: FAIL");
}


/********************************************************************************/
/*
 * In order to avoid the atk-bridge loading and the GAIL
 * initialization during the gtk_init, it is required to set some
 * environment vars.
 *
 */
void
unity_a11y_preset_environment (void)
{
  g_setenv ("NO_AT_BRIDGE", "1", TRUE);
  g_setenv ("NO_GAIL", "1", TRUE);
}

/*
 * Initializes the accessibility (ATK) support on Unity
 *
 * It loads the atk-bridge if required. It checks:
 *  * If the proper gsettings keys are set
 *  * Loads the proper AtkUtil implementation
 */
void
unity_a11y_init (void)
{
  gchar *bridge_path = NULL;

  g_debug ("Unity accessibility initialization");

  unity_a11y_restore_environment ();

  if (!should_enable_a11y ())
    return;

  load_unity_atk_util ();

  bridge_path = get_atk_bridge_path ();

  if (a11y_invoke_module (bridge_path))
    {
      g_debug ("Unity accessibility started, using bridge on %s",
               bridge_path);
      a11y_initialized = TRUE;
    }

  g_free (bridge_path);
}

/*
 * Finalize the related issues related with the accessibility.
 *
 * It mainly clean the resources related with the accessibility
 */
void
unity_a11y_finalize (void)
{
  if (accessible_table != NULL)
    {
      g_hash_table_unref (accessible_table);
      accessible_table = NULL;
    }
  a11y_initialized = FALSE;
}


/*
 * Creates the accessible object for a nux::Area object
 *
 * Method factory, equivalent to
 * atk_object_factory_creeate_accessible, but required because
 * AtkObjectFactory gives only support for GObject classes.
 *
 * FIXME: this should be a temporal method. The best way to implement
 * that would be add a ->get_accessible method on the nux::View
 * subclasses itself.
 *
 * WARNING: as a reason the previous comment it is true. Take into
 * account that you should be careful with the order you add those
 * defines. The order will be from more specific classes to more
 * abstracted classes.
 *
 */

static AtkObject *
unity_a11y_create_accessible (nux::Object *object)
{
  /* UNITY classes*/
  if (object->Type().IsDerivedFromType (Launcher::StaticObjectType))
    return unity_launcher_accessible_new (object);

  if (object->Type().IsDerivedFromType (LauncherIcon::StaticObjectType))
    return unity_launcher_icon_accessible_new (object);

  /* NUX classes  */
  if (object->Type().IsDerivedFromType (nux::BaseWindow::StaticObjectType))
    return nux_base_window_accessible_new (object);

  if (object->Type().IsDerivedFromType (nux::View::StaticObjectType))
    return nux_view_accessible_new (object);

  if (object->Type().IsDerivedFromType (nux::Layout::StaticObjectType))
    return nux_layout_accessible_new (object);

  if (object->Type().IsDerivedFromType (nux::Area::StaticObjectType))
    return nux_area_accessible_new (object);

  return nux_object_accessible_new (object);
}

static void
on_object_destroy_cb (nux::Object *base_object,
                      AtkObject *accessible_object)
{
  /* NOTE: the pair key:value (base_object:accessible_object) could be
     already removed on on_accessible_destroy_cb. That just mean that
     g_hash_table_remove would return FALSE. We don't add a
     debug/warning message to avoid being too verbose */

  g_hash_table_remove (accessible_table, base_object);
}

static void
on_accessible_destroy_cb (gpointer data,
                          GObject *where_the_object_was)
{
  /* NOTE: the pair key:value (base_object:accessible_object) could be
     already removed on on_object_destroy_cb. That just mean that
     g_hash_table_remove would return FALSE. We don't add a
     debug/warning message to avoid being too verbose */

  g_hash_table_remove (accessible_table, data);
}

/*
 * Returns the accessible object of a nux::View object
 *
 * This method tries to:
 *   * Check if area has already a accessibility object
 *   * If this is the case, returns that
 *   * If not, creates it and return the object
 *
 * FIXME: this should be a temporal method. The best way to implement
 * that would be add a ->get_accessible method on the nux::View
 * subclasses itself.
 *
 */
AtkObject *
unity_a11y_get_accessible (nux::Object *object)
{
  AtkObject *accessible_object = NULL;

  g_return_val_if_fail (object != NULL, NULL);

  if (accessible_table == NULL)
    {
      accessible_table = g_hash_table_new (g_direct_hash, g_direct_equal);
    }

  accessible_object = ATK_OBJECT (g_hash_table_lookup (accessible_table, object));
  if (accessible_object == NULL)
    {
      accessible_object = unity_a11y_create_accessible (object);

      g_hash_table_insert (accessible_table, object, accessible_object);

      /* there are two reasons the object should be removed from the
       * table: base object destroyed, or accessible object
       * destroyed
       */
      g_object_weak_ref (G_OBJECT (accessible_object),
                         on_accessible_destroy_cb,
                         object);

      object->OnDestroyed.connect (sigc::bind(sigc::ptr_fun (on_object_destroy_cb),
                                              object, accessible_object));
    }

  return accessible_object;
}

/*
 * Returns if the accessibility support is properly initialized
 */
gboolean unity_a11y_initialized (void)
{
  return a11y_initialized;
}
