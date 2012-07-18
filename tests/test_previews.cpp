// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
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
 * Authored by: Marco Trevisan (Treviño) <3v1n0@ubuntu.com>
 */

#include <list>
#include <algorithm>
#include <gmock/gmock.h>
#include <gio/gio.h>
#include <UnityCore/Variant.h>
#include <UnityCore/Preview.h>
#include <UnityCore/ApplicationPreview.h>
#include <UnityCore/MoviePreview.h>
#include <UnityCore/MusicPreview.h>
#include <UnityCore/SeriesPreview.h>
#include <unity-protocol.h>

using namespace std;
using namespace testing;
using namespace unity;
using namespace unity::glib;
using namespace unity::dash;

namespace
{

bool IsVariant(Variant const& variant)
{
  return g_variant_get_type_string(variant) != NULL;
}

TEST(TestPreviews, DeserializeGeneric)
{
  Object<GIcon> icon(g_icon_new_for_string("accessories", NULL));
  Object<UnityProtocolPreview> proto_obj(UNITY_PROTOCOL_PREVIEW(unity_protocol_generic_preview_new()));
  unity_protocol_preview_set_title(proto_obj, "Title");
  unity_protocol_preview_set_subtitle(proto_obj, "Subtitle");
  unity_protocol_preview_set_description(proto_obj, "Description");
  unity_protocol_preview_set_thumbnail(proto_obj, icon);

  Variant v(dee_serializable_serialize(DEE_SERIALIZABLE(proto_obj.RawPtr())),
            glib::StealRef());
  EXPECT_TRUE(IsVariant(v));

  Preview::Ptr preview = Preview::PreviewForVariant(v);
  EXPECT_TRUE(preview != nullptr);

  EXPECT_EQ(preview->renderer_name, "preview-generic");
  EXPECT_EQ(preview->title, "Title");
  EXPECT_EQ(preview->subtitle, "Subtitle");
  EXPECT_EQ(preview->description, "Description");
  EXPECT_TRUE(g_icon_equal(preview->image(), icon) != FALSE);
}

TEST(TestPreviews, DeserializeGenericWithMeta)
{
  Object<GIcon> icon(g_icon_new_for_string("accessories", NULL));
  Object<UnityProtocolPreview> proto_obj(UNITY_PROTOCOL_PREVIEW(unity_protocol_generic_preview_new()));
  unity_protocol_preview_set_title(proto_obj, "Title");
  unity_protocol_preview_set_subtitle(proto_obj, "Subtitle");
  unity_protocol_preview_set_description(proto_obj, "Description");
  unity_protocol_preview_set_thumbnail(proto_obj, icon);
  unity_protocol_preview_add_action(proto_obj, "action1", "Action #1", NULL, 0);
  unity_protocol_preview_add_action(proto_obj, "action2", "Action #2", NULL, 0);
  unity_protocol_preview_add_info_hint(proto_obj, "hint1", "Hint 1", NULL, g_variant_new("i", 34));
  unity_protocol_preview_add_info_hint(proto_obj, "hint2", "Hint 2", NULL, g_variant_new("s", "string hint"));

  Variant v(dee_serializable_serialize(DEE_SERIALIZABLE(proto_obj.RawPtr())),
            glib::StealRef());
  EXPECT_TRUE(IsVariant(v));

  Preview::Ptr preview = Preview::PreviewForVariant(v);
  EXPECT_TRUE(preview != nullptr);

  EXPECT_EQ(preview->renderer_name, "preview-generic");
  EXPECT_EQ(preview->title, "Title");
  EXPECT_EQ(preview->subtitle, "Subtitle");
  EXPECT_EQ(preview->description, "Description");
  EXPECT_TRUE(g_icon_equal(preview->image(), icon) != FALSE);

  auto actions = preview->GetActions();
  auto info_hints = preview->GetInfoHints();

  EXPECT_EQ(actions.size(), 2);

  auto action1 = actions[0];
  EXPECT_EQ(action1->id, "action1");
  EXPECT_EQ(action1->display_name, "Action #1");
  EXPECT_EQ(action1->icon_hint, "");
  EXPECT_EQ(action1->layout_hint, 0);

  auto action2 = actions[1];
  EXPECT_EQ(action2->id, "action2");
  EXPECT_EQ(action2->display_name, "Action #2");
  EXPECT_EQ(action2->icon_hint, "");

  EXPECT_EQ(info_hints.size(), 2);
  auto hint1 = info_hints[0];
  EXPECT_EQ(hint1->id, "hint1");
  EXPECT_EQ(hint1->display_name, "Hint 1");
  EXPECT_EQ(hint1->icon_hint, "");
  EXPECT_EQ(hint1->value.GetInt(), 34);
  auto hint2 = info_hints[1];
  EXPECT_EQ(hint2->id, "hint2");
  EXPECT_EQ(hint2->display_name, "Hint 2");
  EXPECT_EQ(hint2->icon_hint, "");
  EXPECT_EQ(hint2->value.GetString(), "string hint");
}

TEST(TestPreviews, DeserializeApplication)
{
  Object<GIcon> icon(g_icon_new_for_string("application", NULL));
  Object<UnityProtocolPreview> proto_obj(UNITY_PROTOCOL_PREVIEW(unity_protocol_application_preview_new()));
  unity_protocol_preview_set_title(proto_obj, "Title");
  unity_protocol_preview_set_subtitle(proto_obj, "Subtitle");
  unity_protocol_preview_set_description(proto_obj, "Description");
  unity_protocol_preview_set_thumbnail(proto_obj, icon);
  auto app_proto_obj = glib::object_cast<UnityProtocolApplicationPreview>(proto_obj);
  unity_protocol_application_preview_set_last_update(app_proto_obj, "2012/06/13");
  unity_protocol_application_preview_set_copyright(app_proto_obj, "(c) Canonical");
  unity_protocol_application_preview_set_license(app_proto_obj, "GPLv3");
  unity_protocol_application_preview_set_app_icon(app_proto_obj, icon);
  unity_protocol_application_preview_set_rating(app_proto_obj, 4.0);
  unity_protocol_application_preview_set_num_ratings(app_proto_obj, 12);

  Variant v(dee_serializable_serialize(DEE_SERIALIZABLE(proto_obj.RawPtr())),
            glib::StealRef());
  EXPECT_TRUE(IsVariant(v));

  Preview::Ptr base_preview = Preview::PreviewForVariant(v);
  ApplicationPreview::Ptr preview = std::dynamic_pointer_cast<ApplicationPreview>(base_preview);
  EXPECT_TRUE(preview != nullptr);

  EXPECT_EQ(preview->renderer_name, "preview-application");
  EXPECT_EQ(preview->title, "Title");
  EXPECT_EQ(preview->subtitle, "Subtitle");
  EXPECT_EQ(preview->description, "Description");
  EXPECT_TRUE(g_icon_equal(preview->image(), icon) != FALSE);
  EXPECT_EQ(preview->last_update, "2012/06/13");
  EXPECT_EQ(preview->copyright, "(c) Canonical");
  EXPECT_EQ(preview->license, "GPLv3");
  EXPECT_TRUE(g_icon_equal(preview->app_icon(), icon) != FALSE);
  EXPECT_EQ(preview->rating, 4.0);
  EXPECT_EQ(preview->num_ratings, static_cast<unsigned>(12));
}

TEST(TestPreviews, DeserializeMovie)
{
  Object<GIcon> icon(g_icon_new_for_string("movie", NULL));
  Object<UnityProtocolPreview> proto_obj(UNITY_PROTOCOL_PREVIEW(unity_protocol_movie_preview_new()));
  unity_protocol_preview_set_title(proto_obj, "Title");
  unity_protocol_preview_set_subtitle(proto_obj, "Subtitle");
  unity_protocol_preview_set_description(proto_obj, "Description");
  unity_protocol_preview_set_thumbnail(proto_obj, icon);
  auto movie_proto_obj = glib::object_cast<UnityProtocolMoviePreview>(proto_obj);
  unity_protocol_movie_preview_set_year(movie_proto_obj, "2012");
  unity_protocol_movie_preview_set_rating(movie_proto_obj, 4.0);
  unity_protocol_movie_preview_set_num_ratings(movie_proto_obj, 12);

  Variant v(dee_serializable_serialize(DEE_SERIALIZABLE(proto_obj.RawPtr())),
            glib::StealRef());
  EXPECT_TRUE(IsVariant(v));

  Preview::Ptr base_preview = Preview::PreviewForVariant(v);
  MoviePreview::Ptr preview = std::dynamic_pointer_cast<MoviePreview>(base_preview);
  EXPECT_TRUE(preview != nullptr);

  EXPECT_EQ(preview->renderer_name, "preview-movie");
  EXPECT_EQ(preview->title, "Title");
  EXPECT_EQ(preview->subtitle, "Subtitle");
  EXPECT_EQ(preview->description, "Description");
  EXPECT_TRUE(g_icon_equal(preview->image(), icon) != FALSE);
  EXPECT_EQ(preview->year, "2012");
  EXPECT_EQ(preview->rating, 4.0);
  EXPECT_EQ(preview->num_ratings, static_cast<unsigned int>(12));
}

TEST(TestPreviews, DeserializeMusic)
{
  Object<GIcon> icon(g_icon_new_for_string("music", NULL));
  Object<UnityProtocolPreview> proto_obj(UNITY_PROTOCOL_PREVIEW(unity_protocol_music_preview_new()));
  unity_protocol_preview_set_title(proto_obj, "Title");
  unity_protocol_preview_set_subtitle(proto_obj, "Subtitle");
  unity_protocol_preview_set_description(proto_obj, "Description");
  unity_protocol_preview_set_thumbnail(proto_obj, icon);
  auto music_proto_obj = glib::object_cast<UnityProtocolMusicPreview>(proto_obj);

  Variant v(dee_serializable_serialize(DEE_SERIALIZABLE(proto_obj.RawPtr())),
            glib::StealRef());
  EXPECT_TRUE(IsVariant(v));

  Preview::Ptr base_preview = Preview::PreviewForVariant(v);
  MusicPreview::Ptr preview = std::dynamic_pointer_cast<MusicPreview>(base_preview);
  EXPECT_TRUE(preview != nullptr);

  EXPECT_EQ(preview->renderer_name, "preview-music");
  EXPECT_EQ(preview->title, "Title");
  EXPECT_EQ(preview->subtitle, "Subtitle");
  EXPECT_EQ(preview->description, "Description");
  EXPECT_TRUE(g_icon_equal(preview->image(), icon) != FALSE);
}

TEST(TestPreviews, DeserializeSeries)
{
  Object<UnityProtocolPreview> proto_obj(UNITY_PROTOCOL_PREVIEW(unity_protocol_series_preview_new()));
  auto series_proto_obj = glib::object_cast<UnityProtocolSeriesPreview>(proto_obj);
  unity_protocol_series_preview_add_series_item(
      series_proto_obj, "#1", "scheme://path/0", NULL);
  unity_protocol_series_preview_add_series_item(
      series_proto_obj, "#2", "scheme://path/1", NULL);
  unity_protocol_series_preview_set_selected_item(series_proto_obj, 1);

  Object<GIcon> icon(g_icon_new_for_string("accessories", NULL));
  Object<UnityProtocolPreview> child_proto_obj(UNITY_PROTOCOL_PREVIEW(unity_protocol_generic_preview_new()));
  unity_protocol_preview_set_title(child_proto_obj, "Title");
  unity_protocol_preview_set_subtitle(child_proto_obj, "Subtitle");
  unity_protocol_preview_set_description(child_proto_obj, "Description");
  unity_protocol_preview_set_thumbnail(child_proto_obj, icon);

  unity_protocol_series_preview_set_child_preview(series_proto_obj,
      child_proto_obj);

  Variant v(dee_serializable_serialize(DEE_SERIALIZABLE(proto_obj.RawPtr())),
            glib::StealRef());
  EXPECT_TRUE(IsVariant(v));

  Preview::Ptr base_preview = Preview::PreviewForVariant(v);
  SeriesPreview::Ptr preview = std::dynamic_pointer_cast<SeriesPreview>(base_preview);
  EXPECT_TRUE(preview != nullptr);

  EXPECT_EQ(preview->renderer_name, "preview-series");

  auto items = preview->GetItems();
  EXPECT_EQ(items.size(), 2);

  auto item1 = preview->GetItems()[1];
  EXPECT_EQ(item1->uri, "scheme://path/1");
  EXPECT_EQ(item1->title, "#2");

  auto child_preview = preview->GetChildPreview();
  EXPECT_EQ(child_preview->renderer_name, "preview-generic");
  EXPECT_EQ(child_preview->title, "Title");
  EXPECT_EQ(child_preview->subtitle, "Subtitle");
  EXPECT_EQ(child_preview->description, "Description");
  EXPECT_TRUE(g_icon_equal(child_preview->image(), icon) != FALSE);
}

} // Namespace
