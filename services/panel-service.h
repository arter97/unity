#ifndef _PANEL_SERVICE_H_
#define _PANEL_SERVICE_H_

#include <glib-object.h>

G_BEGIN_DECLS

#define PANEL_TYPE_SERVICE (panel_service_get_type ())

#define PANEL_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj),\
	PANEL_TYPE_SERVICE, PanelService))

#define PANEL_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass),\
	PANEL_TYPE_SERVICE, PanelServiceClass))

#define PANEL_IS_SERVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj),\
	PANEL_TYPE_SERVICE))

#define PANEL_IS_SERVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),\
	PANEL_TYPE_SERVICE))

#define PANEL_SERVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj),\
	PANEL_TYPE_SERVICE, PanelServiceClass))

typedef struct _PanelService        PanelService;
typedef struct _PanelServiceClass   PanelServiceClass;
typedef struct _PanelServicePrivate PanelServicePrivate;

struct _PanelService
{
  GObject              parent;

  PanelServicePrivate *priv;
};

struct _PanelServiceClass
{
  GObjectClass   parent_class;

  /*< private >*/
  void (*_view_padding1) (void);
  void (*_view_padding2) (void);
  void (*_view_padding3) (void);
  void (*_view_padding4) (void);
  void (*_view_padding5) (void);
  void (*_view_padding6) (void);
};

GType          panel_service_get_type      (void) G_GNUC_CONST;

PanelService * panel_service_get_default   ();

GVariant     * panel_service_sync          (PanelService *self);

GVariant     * panel_service_sync_one      (PanelService *self,
                                            const gchar  *indicator_id);

void           panel_service_show_entry    (PanelService *self,
                                            const gchar  *entry_id,
                                            guint32       timestamp,
                                            gint32        x,
                                            gint32        y,
                                            gint32        button);


G_END_DECLS

#endif /* _PANEL_SERVICE_H_ */
