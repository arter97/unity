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
 * Authored by: Rodrigo Moya <rodrigo.moya@canonical.com>
 */

#include <glib/gi18n.h>
#include "panel-indicator-accessible.h"
#include "panel-indicator-entry-accessible.h"

G_DEFINE_TYPE(PanelIndicatorAccessible, panel_indicator_accessible, ATK_TYPE_OBJECT)

#define GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), PANEL_TYPE_INDICATOR_ACCESSIBLE, PanelIndicatorAccessiblePrivate))

/* AtkObject methods */
static void       panel_indicator_accessible_initialize     (AtkObject *accessible, gpointer data);
static gint       panel_indicator_accessible_get_n_children (AtkObject *accessible);
static AtkObject *panel_indicator_accessible_ref_child      (AtkObject *accessible, gint i);

struct _PanelIndicatorAccessiblePrivate
{
  IndicatorObject *indicator;
  GSList *a11y_children;
};

static void
panel_indicator_accessible_finalize (GObject *object)
{
  PanelIndicatorAccessible *pia = PANEL_INDICATOR_ACCESSIBLE (object);

  if (pia->priv != NULL)
    {
      if (pia->priv->indicator != NULL)
        g_object_unref (G_OBJECT (pia->priv->indicator));

      while (pia->priv->a11y_children != NULL)
        {
	  AtkObject *accessible = ATK_OBJECT (pia->priv->a11y_children->data);

	  pia->priv->a11y_children = g_slist_remove (pia->priv->a11y_children, accessible);
	  g_object_unref (accessible);
	}
    }

  G_OBJECT_CLASS (panel_indicator_accessible_parent_class)->finalize (object);
}

static void
panel_indicator_accessible_class_init (PanelIndicatorAccessibleClass *klass)
{
  GObjectClass *object_class;
  AtkObjectClass *atk_class;

  /* GObject */
  object_class = G_OBJECT_CLASS (klass);
  object_class->finalize = panel_indicator_accessible_finalize;

  /* AtkObject */
  atk_class = ATK_OBJECT_CLASS (klass);
  atk_class->initialize = panel_indicator_accessible_initialize;
  atk_class->get_n_children = panel_indicator_accessible_get_n_children;
  atk_class->ref_child = panel_indicator_accessible_ref_child;

  g_type_class_add_private (object_class, sizeof (PanelIndicatorAccessiblePrivate));
}

static void
panel_indicator_accessible_init (PanelIndicatorAccessible *pia)
{
  pia->priv = GET_PRIVATE (pia);
  pia->priv->a11y_children = NULL;
}

AtkObject *
panel_indicator_accessible_new (IndicatorObject *indicator)
{
  PanelIndicatorAccessible *pia;

  pia = g_object_new (PANEL_TYPE_INDICATOR_ACCESSIBLE, NULL);
  atk_object_initialize (ATK_OBJECT (pia), indicator);

  return (AtkObject *) pia;
}

/* Implementation of AtkObject methods */

static void
panel_indicator_accessible_initialize (AtkObject *accessible, gpointer data)
{
  PanelIndicatorAccessible *pia;
  GList *entries, *l;

  g_return_if_fail (PANEL_IS_INDICATOR_ACCESSIBLE (accessible));

  ATK_OBJECT_CLASS (panel_indicator_accessible_parent_class)->initialize (accessible, data);

  pia = PANEL_INDICATOR_ACCESSIBLE (accessible);
  pia->priv->indicator = g_object_ref (data);
  atk_object_set_name (accessible, _("An indicator")); /* FIXME */
  atk_object_set_role (accessible, ATK_ROLE_PANEL);

  /* Retrieve all entries and create their accessible objects */
  entries = indicator_object_get_entries (pia->priv->indicator);
  for (l = entries; l != NULL; l = l->next)
    {
      AtkObject *accessible;

      accessible = panel_indicator_entry_accessible_new ((IndicatorObjectEntry *) l->data);
      pia->priv->a11y_children = g_slist_append (pia->priv->a11y_children, accessible);
    }

  g_list_free (entries);
}

static gint
panel_indicator_accessible_get_n_children (AtkObject *accessible)
{
  PanelIndicatorAccessible *pia = PANEL_INDICATOR_ACCESSIBLE (accessible);

  g_return_val_if_fail (PANEL_IS_INDICATOR_ACCESSIBLE (pia), 0);

  return g_slist_length (pia->priv->a11y_children);
}

static AtkObject *
panel_indicator_accessible_ref_child (AtkObject *accessible, gint i)
{
  PanelIndicatorAccessible *pia = PANEL_INDICATOR_ACCESSIBLE (accessible);

  g_return_val_if_fail (PANEL_IS_INDICATOR_ACCESSIBLE (pia), NULL);

  return g_object_ref (g_slist_nth_data (pia->priv->a11y_children, i));
}
