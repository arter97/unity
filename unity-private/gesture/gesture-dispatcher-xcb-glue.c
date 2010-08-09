/*
 * Copyright (C) 2010 Canonical Ltd
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
 * Authored by Neil Jagdish Patel <neil.patel@canonical.com>
 *
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xcb/xcb.h>
#include <xcb/xcb_icccm.h>
#include <X11/X.h>

#include <glib.h>

#include <grail-types.h>

#include "gesture.h"

#define XCB_DISPATCHER_TIMEOUT 500

typedef struct
{
  GSource source;


  xcb_connection_t    *connection;
  xcb_generic_event_t *event;

} XCBSource;

static gboolean source_prepare (GSource     *source, gint *timeout);
static gboolean source_check   (GSource     *source);
static gboolean source_dispatch(GSource     *source,
                                GSourceFunc  callback,
                                gpointer     user_data);
static void     source_finalize(GSource     *source);

static gint     set_mask (xcb_connection_t *connection,
                          xcb_window_t      window,
                          uint16_t          device_id,
                          uint16_t          mask_len,
                          uint32_t         *mask);

static GSourceFuncs XCBFuncs = {
  &source_prepare,
  &source_check,
  &source_dispatch,
  &source_finalize,
  0,
  0
};

void
unity_gesture_xcb_dispatcher_glue_init ()
{
  g_debug ("%s", G_STRFUNC);
  xcb_connection_t *connection;
  XCBSource        *source;
  uint16_t          mask_len = 1;
  uint32_t         *mask;

  connection = xcb_connect (NULL, NULL);

  mask = malloc(sizeof(uint32_t) * mask_len);
  *mask = 0xeeee;
  if (set_mask (connection, 0, 0, mask_len, mask))
    {
      g_warning ("Unable to initialize gesture dispatcher xcb");
      return;
    }

  source = (XCBSource*)g_source_new (&XCBFuncs, sizeof(XCBSource));
  source->connection = connection;
  g_source_attach (&source->source, NULL);
}

void
unity_gesture_xcb_dispatcher_glue_finish ()
{
  g_debug ("%s", G_STRFUNC);
}

void
unity_gesture_xcb_dispatcher_glue_main_iteration (XCBSource *source)
{
  g_debug ("%s", G_STRFUNC);
  const xcb_query_extension_reply_t *extension_info;
  xcb_connection_t *connection = source->connection;
  
	extension_info = xcb_get_extension_data(connection, &xcb_gesture_id);

  if (source->event != NULL)
    {
      xcb_generic_event_t *event;
      xcb_gesture_notify_event_t *gesture_event;
      float *properties;
      int i;

      event = source->event;
      if (!event) {
        fprintf(stderr,
          "Warning: I/O error while waiting for event\n");
        return;
      }

      if (event->response_type != GenericEvent) {
        fprintf(stderr,
          "Warning: Received non-generic event type: "
          "%d\n", event->response_type);
        return;
      }

      gesture_event = (xcb_gesture_notify_event_t *)event;

      if (gesture_event->extension != extension_info->major_opcode) {
        fprintf(stderr,
          "Warning: Received non-gesture extension "
          "event: %d\n", gesture_event->extension);
        return;
      }

                  if (gesture_event->event_type != XCB_GESTURE_NOTIFY) {
        fprintf(stderr,
          "Warning: Received unrecognized gesture event "
          "type: %d\n", gesture_event->event_type);
        return;
      }

      printf("Gesture ID:\t\t%hu\n", gesture_event->gesture_id);

      printf("\tGesture Type:\t%d: ", gesture_event->gesture_type);
      switch (gesture_event->gesture_type) {
        case GRAIL_TYPE_POINTER:
          printf("Pointer (Reserved)\n");
          break;
        case GRAIL_TYPE_PAN:
          printf("Pan (Two-Finger Pan)\n");
          break;
        case GRAIL_TYPE_PINCH:
          printf("Pinch (Two-Finger Pinch)\n");
          break;
        case GRAIL_TYPE_ROTATE:
          printf("Rotate (Two-Finger Rotate)\n");
          break;
        case GRAIL_TYPE_COMBO2:
          printf("Combo-2 (Two-Finger Combination)\n");
          break;
        case GRAIL_TYPE_SWIPE:
          printf("Swipe (Three-Finger Pan)\n");
          break;
        case GRAIL_TYPE_SCALE:
          printf("Scale (Three-Finger Pinch)\n");
          break;
        case GRAIL_TYPE_TURN:
          printf("Turn (Three-Finger Rotate)\n");
          break;
        case GRAIL_TYPE_COMBO3:
          printf("Combo-3 (Three-Finger Combination)\n");
          break;
        case GRAIL_TYPE_BRUSH:
          printf("Brush (Four-Finger Pan)\n");
          break;
        case GRAIL_TYPE_PICK:
          printf("Pick (Four-Finger Pinch)\n");
          break;
        case GRAIL_TYPE_WHIRL:
          printf("Whirl (Four-Finger Rotate)\n");
          break;
        case GRAIL_TYPE_COMBO4:
          printf("Combo-4 (Four-Finger Combination)\n");
          break;
        case GRAIL_TYPE_HAND:
          printf("Hand (Five-Finger Pan)\n");
          break;
        case GRAIL_TYPE_GRAB:
          printf("Grab (Five-Finger Pinch)\n");
          break;
        case GRAIL_TYPE_REVOLVE:
          printf("Revolve (Five-Finger Rotate)\n");
          break;
        case GRAIL_TYPE_COMBO5:
          printf("Combo-5 (Five-Finger Combination)\n");
          break;
        case GRAIL_TYPE_TAP1:
          printf("Tap-1 (One-Finger Tap)\n");
          break;
        case GRAIL_TYPE_TAP2:
          printf("Tap-2 (Two-Finger Tap)\n");
          break;
        case GRAIL_TYPE_TAP3:
          printf("Tap-3 (Three-Finger Tap)\n");
          break;
        case GRAIL_TYPE_TAP4:
          printf("Tap-4 (Four-Finger Tap)\n");
          break;
        case GRAIL_TYPE_TAP5:
          printf("Tap-5 (Five-Finger Tap)\n");
          break;
        default:
          printf("Unknown\n");
          break;
      }

      printf("\tDevice ID:\t%hu\n", gesture_event->device_id);
      printf("\tTimestamp:\t%u\n", gesture_event->time);

      printf("\tRoot Window:\t0x%x: (root window)\n",
             gesture_event->root);

      printf("\tEvent Window:\t0x%x: ", gesture_event->event);
      printf("\tChild Window:\t0x%x: ", gesture_event->child);
      printf("\tFocus X:\t%f\n", gesture_event->focus_x);
      printf("\tFocus Y:\t%f\n", gesture_event->focus_y);
      printf("\tStatus:\t\t%hu\n", gesture_event->status);
      printf("\tNum Props:\t%hu\n", gesture_event->num_props);

      properties = (float *)(gesture_event + 1);

      for (i = 0; i < gesture_event->num_props; i++) {
        printf("\t\tProperty %u:\t%f\n", i, properties[i]);
      }

      printf("\n");
    } 
}

static gboolean
source_prepare (GSource     *source, gint *timeout)
{
  XCBSource *s = (XCBSource *)source;
  //const xcb_query_extension_reply_t *extention_info;

  *timeout = XCB_DISPATCHER_TIMEOUT;

  //extension_info = xcb_get_extension_data (s->connection, &xcb_gesture_id);

  s->event = xcb_poll_for_event (s->connection);
  
  return s->event == NULL ? FALSE : TRUE;
}

static gboolean
source_check   (GSource     *source)
{
  return ((XCBSource*)source)->event == NULL ? FALSE : TRUE;
}

static gboolean
source_dispatch(GSource     *source,
                GSourceFunc  callback,
                gpointer     user_data)
{
  unity_gesture_xcb_dispatcher_glue_main_iteration ((XCBSource*)source);
  return TRUE;
}

static void
source_finalize (GSource *source)
{

}

static int set_mask_on_window(xcb_connection_t *connection, xcb_window_t window,
			      uint16_t device_id, uint16_t mask_len,
			      uint32_t *mask) {
	xcb_generic_error_t *error;
	xcb_void_cookie_t select_cookie;
	xcb_gesture_get_selected_events_cookie_t events_cookie;
	xcb_gesture_get_selected_events_reply_t *events_reply;
	xcb_gesture_event_mask_iterator_t events_iterator;
	int masks_len_reply;
	int mask_len_reply;
	uint32_t *mask_reply;

	select_cookie = xcb_gesture_select_events_checked(connection, window,
							  device_id, mask_len,
							  mask);
	error = xcb_request_check(connection, select_cookie);
	if (error) {
		fprintf(stderr,
			"Error: Failed to select events on window 0x%x\n",
			window);
		return -1;
	}

	events_cookie = xcb_gesture_get_selected_events(connection, window);
	events_reply = xcb_gesture_get_selected_events_reply(connection,
							     events_cookie,
							     &error);
	if (!events_reply) {
		fprintf(stderr,
			"Error: Failed to receive selected events reply on "
			"window 0x%x\n", window);
		return -1;
	}

	masks_len_reply =
		xcb_gesture_get_selected_events_masks_length(events_reply);
	if (masks_len_reply != 1) {
		fprintf(stderr,
			"Error: Wrong selected masks length returned: %d\n",
			masks_len_reply);
		return -1;
	}

	events_iterator =
		xcb_gesture_get_selected_events_masks_iterator(events_reply);
	if (events_iterator.data->device_id != device_id) {
		fprintf(stderr,
			"Error: Incorrect device id returned by server: %d\n",
			events_iterator.data->device_id);
		return -1;
	}

	mask_len_reply =
		xcb_gesture_event_mask_mask_data_length(events_iterator.data);
	if (mask_len_reply != mask_len) {
		fprintf(stderr,
			"Error: Incorrect mask length returned by server: %d\n",
			mask_len_reply);
		return -1;
	}

	mask_reply = xcb_gesture_event_mask_mask_data(events_iterator.data);
	if (memcmp(mask, mask_reply, mask_len * 4) != 0) {
		fprintf(stderr, "Error: Incorrect mask returned by server\n");
		return -1;
	}

	free(events_reply);

	return 0;
}

static int set_mask_on_subwindows(xcb_connection_t *connection,
				  xcb_window_t window, uint16_t device_id,
				  uint16_t mask_len, uint32_t *mask) {
	xcb_generic_error_t *error;
	xcb_query_tree_cookie_t tree_cookie;
	xcb_query_tree_reply_t *tree_reply;
	xcb_window_t *children;
	int num_children;
	int i;

	if (set_mask_on_window(connection, window, device_id, mask_len, mask))
		return -1;

	tree_cookie = xcb_query_tree(connection, window);
	tree_reply = xcb_query_tree_reply(connection, tree_cookie, &error);
	if (!tree_reply) {
		fprintf(stderr, "Error: Failed to query tree for window 0x%x\n",
		window);
		return -1;
	}

	num_children = xcb_query_tree_children_length(tree_reply);
	if (num_children <= 0)
		return 0;

	children = xcb_query_tree_children(tree_reply);
	if (!children) {
		fprintf(stderr,
			"Error: Failed to retrieve children of window 0x%x\n",
			window);
		return -1;
	}

	for (i = 0; i < num_children; i++)
		if (set_mask_on_subwindows(connection, children[i], device_id,
					   mask_len, mask))
			return -1;
	
	free(tree_reply);

	return 0;
}

static int set_mask(xcb_connection_t *connection, xcb_window_t window,
		    uint16_t device_id, uint16_t mask_len, uint32_t *mask) {
	xcb_generic_error_t *error;
	xcb_gesture_query_version_cookie_t version_cookie;
	xcb_gesture_query_version_reply_t *version_reply;

	version_cookie = xcb_gesture_query_version(connection, 0, 5);
	version_reply = xcb_gesture_query_version_reply(connection,
							version_cookie, &error);
	if (!version_reply) {
		fprintf(stderr,
			"Error: Failed to receive gesture version reply\n");
		return -1;
	}

	if (version_reply->major_version != 0 &&
	    version_reply->minor_version != 5) {
		fprintf(stderr,
			"Error: Server supports unrecognized version: %d.%d\n",
			version_reply->major_version,
			version_reply->minor_version);
		return -1;
	}

	free(version_reply);

	if (window != 0) {
		if (set_mask_on_window(connection, window, device_id, mask_len,
				       mask))
			return -1;
	}
	else {
		const xcb_setup_t *setup;
		xcb_screen_iterator_t screen;

		setup = xcb_get_setup(connection);
		if (!setup) {
			fprintf(stderr, "Error: Failed to get xcb setup\n");
			return -1;
		}

		for (screen = xcb_setup_roots_iterator(setup); screen.rem;
		     xcb_screen_next(&screen))
			if (set_mask_on_subwindows(connection,
			    screen.data->root, device_id, mask_len, mask))
				return -1;
	}

	return 0;
}
