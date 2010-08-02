/* utils.c generated by valac, the Vala compiler
 * generated from utils.vala, do not modify */

/*
 * Copyright (C) 2009 Canonical Ltd
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

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>
#include <clutter/clutter.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>
#include <X11/Xregion.h>

#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))
#define _g_match_info_free0(var) ((var == NULL) ? NULL : (var = (g_match_info_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))



char* utils_strip_characters (const char* text, const char* replace_text, const char* match_regex, const char* replace_regex);
void utils_set_strut (GtkWindow* window, guint32 strut_size, guint32 strut_start, guint32 strut_end, guint32 top_size, guint32 top_start, guint32 top_end);
void utils_register_object_on_dbus (DBusGConnection* conn, const char* path, GObject* object);
Window utils_get_stage_window (ClutterStage* stage);
gboolean utils_save_snapshot (ClutterStage* stage, const char* filename, gint x, gint y, gint width, gint height);
gboolean utils_compare_snapshot (ClutterStage* stage, const char* filename, gint x, gint y, gint width, gint height, gboolean expected);
gboolean utils_utils_compare_images (const char* img1_path, const char* img2_path);
gboolean utils_window_is_decorated (guint32 xid);
void utils_window_set_decorations (guint32 xid, guint decorations);



char* utils_strip_characters (const char* text, const char* replace_text, const char* match_regex, const char* replace_regex) {
	char* result = NULL;
	GError * _inner_error_;
	char* ret;
	gboolean matching;
	GMatchInfo* info;
	g_return_val_if_fail (text != NULL, NULL);
	g_return_val_if_fail (replace_text != NULL, NULL);
	g_return_val_if_fail (match_regex != NULL, NULL);
	g_return_val_if_fail (replace_regex != NULL, NULL);
	_inner_error_ = NULL;
	ret = g_strdup ("");
	matching = FALSE;
	info = NULL;
	{
		GRegex* regex;
		GMatchInfo* _tmp4_;
		gboolean _tmp3_;
		GMatchInfo* _tmp2_ = NULL;
		regex = NULL;
		{
			GRegex* _tmp0_;
			GRegex* _tmp1_;
			_tmp0_ = g_regex_new (match_regex, G_REGEX_DOTALL | G_REGEX_OPTIMIZE, 0, &_inner_error_);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == G_REGEX_ERROR) {
					goto __catch2_g_regex_error;
				}
				_g_regex_unref0 (regex);
				_g_match_info_free0 (info);
				_g_free0 (ret);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return NULL;
			}
			regex = (_tmp1_ = _tmp0_, _g_regex_unref0 (regex), _tmp1_);
		}
		goto __finally2;
		__catch2_g_regex_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				g_warning ("utils.vala:43: Creating regular-expression failed: \"%s\"\n", e->message);
				_g_error_free0 (e);
			}
		}
		__finally2:
		if (_inner_error_ != NULL) {
			_g_regex_unref0 (regex);
			_g_match_info_free0 (info);
			_g_free0 (ret);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		matching = (_tmp3_ = g_regex_match (regex, text, 0, &_tmp2_), info = (_tmp4_ = _tmp2_, _g_match_info_free0 (info), _tmp4_), _tmp3_);
		_g_regex_unref0 (regex);
	}
	if (matching) {
		GRegex* regex;
		regex = NULL;
		{
			GRegex* _tmp5_;
			GRegex* _tmp6_;
			_tmp5_ = g_regex_new (replace_regex, G_REGEX_DOTALL | G_REGEX_OPTIMIZE, 0, &_inner_error_);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == G_REGEX_ERROR) {
					goto __catch3_g_regex_error;
				}
				_g_regex_unref0 (regex);
				_g_match_info_free0 (info);
				_g_free0 (ret);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return NULL;
			}
			regex = (_tmp6_ = _tmp5_, _g_regex_unref0 (regex), _tmp6_);
		}
		goto __finally3;
		__catch3_g_regex_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				g_warning ("utils.vala:62: Creating regular-expression failed: \"%s\"\n", e->message);
				_g_error_free0 (e);
			}
		}
		__finally3:
		if (_inner_error_ != NULL) {
			_g_regex_unref0 (regex);
			_g_match_info_free0 (info);
			_g_free0 (ret);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		{
			char* _tmp7_;
			char* _tmp8_;
			_tmp7_ = g_regex_replace (regex, text, (gssize) (-1), 0, replace_text, 0, &_inner_error_);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == G_REGEX_ERROR) {
					goto __catch4_g_regex_error;
				}
				_g_regex_unref0 (regex);
				_g_match_info_free0 (info);
				_g_free0 (ret);
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return NULL;
			}
			ret = (_tmp8_ = _tmp7_, _g_free0 (ret), _tmp8_);
		}
		goto __finally4;
		__catch4_g_regex_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				g_warning ("utils.vala:71: Replacing text failed: \"%s\"\n", e->message);
				_g_error_free0 (e);
			}
		}
		__finally4:
		if (_inner_error_ != NULL) {
			_g_regex_unref0 (regex);
			_g_match_info_free0 (info);
			_g_free0 (ret);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		_g_regex_unref0 (regex);
	} else {
		char* _tmp9_;
		ret = (_tmp9_ = g_strdup (text), _g_free0 (ret), _tmp9_);
	}
	result = ret;
	_g_match_info_free0 (info);
	return result;
}




