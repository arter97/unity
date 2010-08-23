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

namespace Unity.Places
{
  public class DefaultRenderer : LayeredBin, Unity.Place.Renderer
  {
    static const float PADDING = 12.0f;
    static const int   SPACING = 0;

    private LayeredBin bin;
    private EmptySearchGroup search_empty;
    private EmptySectionGroup section_empty;

    private Ctk.ScrollView scroll;
    private Ctk.VBox box;
    private Dee.Model groups_model;
    private Dee.Model results_model;

    public DefaultRenderer ()
    {
      Object ();
    }

    construct
    {
      padding = { 0.0f, 0.0f, 0.0f, 0.0f };

      scroll = new Ctk.ScrollView ();
      add_actor (scroll);
      scroll.show ();

      box = new Ctk.VBox (SPACING);
      box.padding = { 0.0f, PADDING, 0.0f, PADDING};
      box.homogeneous = false;
      scroll.add_actor (box);
      box.show ();
    }

    /*
     * Private Methods
     */
    public void set_models (Dee.Model                   groups,
                            Dee.Model                   results,
                            Gee.HashMap<string, string> hints)
    {
      groups_model = groups;
      results_model = results;

      unowned Dee.ModelIter iter = groups.get_first_iter ();
      while (!groups.is_last (iter))
        {
          on_group_added (groups, iter);

          iter = groups.next (iter);
        }

      groups_model.row_added.connect (on_group_added);
      groups_model.row_removed.connect (on_group_removed);
    }

    private void update_views ()
    {
      int search_empty_opacity = 0;
      int section_empty_opacity = 0;
      int groups_box_opacity = 255;

      if (search_empty.active)
        {
          search_empty_opacity = 255;
          section_empty_opacity = 0;
          groups_box_opacity = 0;
        }
      else if (section_empty.active)
        {
          search_empty_opacity = 0;
          section_empty_opacity = 255;
          groups_box_opacity = 0;
        }
      
      search_empty.animate (Clutter.AnimationMode.EASE_IN_QUAD,
                            300,
                            "opacity", search_empty_opacity);
      section_empty.animate (Clutter.AnimationMode.EASE_IN_QUAD,
                            300,
                            "opacity", section_empty_opacity);
      scroll.animate (Clutter.AnimationMode.EASE_IN_QUAD,
                            300,
                            "opacity", groups_box_opacity);

    }

    private void on_group_added (Dee.Model model, Dee.ModelIter iter)
    {
      string renderer = model.get_string (iter, 0);

      if (renderer == "UnityEmptySearchRenderer")
        {
          search_empty = new EmptySearchGroup (model.get_position (iter),
                                            results_model);
          search_empty.opacity = 0;
          add_actor (search_empty);
          
          search_empty.activated.connect ((u, m) => { activated (u, m); } );
          search_empty.notify["active"].connect (update_views);

        }
      else if (renderer == "UnityEmptySectionRenderer")
        {
          section_empty = new EmptySectionGroup (model.get_position (iter),
                                              results_model);
          section_empty.opacity = 0;
          add_actor (section_empty);

          section_empty.notify["active"].connect (update_views);
        }
      else
        {
          var group = new DefaultRendererGroup (model.get_position (iter),
                                                model.get_string (iter, 0),
                                                model.get_string (iter, 1),
                                                model.get_string (iter, 2),
                                                results_model);
          group.activated.connect ((u, m) => { activated (u, m); } );
          group.set_data<unowned Dee.ModelIter> ("model-iter", iter);
          box.pack (group, false, true);
        }
    }

    private void on_group_removed (Dee.Model model, Dee.ModelIter iter)
    {
      GLib.List<Clutter.Actor> children = box.get_children ();
      foreach (Clutter.Actor actor in children)
        {
          unowned Dee.ModelIter i = (Dee.ModelIter)actor.get_data<Dee.ModelIter> ("model-iter");
          if (i == iter)
            {
              actor.destroy ();
              break;
            }
        }
    }
  }

  public class EmptySearchGroup : Ctk.Bin
  {
    public uint   group_id { get; construct set; }

    public Dee.Model results { get; construct set; }

    public signal void activated (string uri, string mimetype);

    public bool active { get; construct set;}

    private Ctk.VBox box;

    public EmptySearchGroup (uint group_id, Dee.Model results)
    {
      Object (group_id:group_id, results:results, active:false);
    }

    construct
    {
      var hbox = new Ctk.HBox (0);
      add_actor (hbox);
      hbox.show ();

      box = new Ctk.VBox (12);
      hbox.pack (box, false, false);
      box.show ();

      results.row_added.connect (on_result_added);
      results.row_removed.connect (on_result_removed);

      opacity = 0;
    }

    private void on_result_added (Dee.ModelIter iter)
    {
      if (!interesting (iter))
        return;
      
      string mes = results.get_string (iter, 4);

      var button = new Ctk.Button (Ctk.Orientation.HORIZONTAL);
      button.padding = { 12.0f, 12.0f, 12.0f, 12.0f };
      var text = new Ctk.Text ("");
      text.set_markup ("<big>" + mes + "</big>");
      button.add_actor (text);

      box.pack (button, false, false);

      if (box.get_children ().length () >= 2)
        {
          var bg = new StripeTexture (null);
          button.set_background (bg);

          string uri = results.get_string (iter, 0);
          string mimetype = results.get_string (iter, 3);

          button.clicked.connect (() => { activated (uri, mimetype); });
        }

      active = true;
    }

    private void on_result_removed (Dee.ModelIter iter)
    {
      if (!interesting (iter))
        return;

      active = false;
      
      var children = box.get_children ();
      foreach (Clutter.Actor child in children)
        {
          box.remove_actor (child);
        }
    }

    private bool interesting (Dee.ModelIter iter)
    {
      return (results.get_uint (iter, 2) == group_id);
    }
  }


  public class EmptySectionGroup : Ctk.Bin
  {
    public uint   group_id { get; construct set; }

    private Ctk.Text text;
    public Dee.Model results { get; construct set; }

    public signal void activated (string uri, string mimetype);
    public bool active { get; construct set; }

    public EmptySectionGroup (uint group_id, Dee.Model results)
    {
      Object (group_id:group_id, results:results, active:false);
    }

    construct
    {
      text = new Ctk.Text ("");

      add_actor (text);
      text.show ();

      results.row_added.connect (on_result_added);
      results.row_removed.connect (on_result_removed);

      opacity = 0;

      var bg = new CairoCanvas (paint_bg);
      set_background (bg);
      bg.show ();
    }

    private override void allocate (Clutter.ActorBox box,
                                    Clutter.AllocationFlags flags)
    {
      base.allocate (box, flags);

      Clutter.ActorBox child_box = Clutter.ActorBox ();
      float twidth;
      float theight;
      text.get_preferred_size (out twidth, out theight, null, null);

      child_box.x1 = ((box.x2 - box.x1)/2.0f) - (twidth/2.0f);
      child_box.x2 = child_box.x1 + twidth;
      child_box.y1 = ((box.y2 - box.y1)/2.0f) - (theight/2.0f);
      child_box.y2 = child_box.y1 + theight;
      text.allocate (child_box, flags);
    }

    private void on_result_added (Dee.ModelIter iter)
    {
      if (!interesting (iter))
        return;
      
      string mes = results.get_string (iter, 4);
      text.set_markup ("<big>" + mes + "</big>");

      active = true;
    }

    private void on_result_removed (Dee.ModelIter iter)
    {
      if (!interesting (iter))
        return;

      active = false;
    }

    private override void get_preferred_height (float for_width,
                                       out float mheight,
                                       out float nheight)
    {
      mheight = 2000;
      nheight = 2000;
    }

    private bool interesting (Dee.ModelIter iter)
    {
      return (results.get_uint (iter, 2) == group_id);
    }

    private void paint_bg (Cairo.Context cr, int width, int height)
    {
      cr.set_operator (Cairo.Operator.CLEAR);
      cr.paint ();

      cr.set_operator (Cairo.Operator.OVER);
      cr.translate (0.5, 0.5);
      cr.set_line_width (1.5);

      var radius = 7;
      float twidth, theight;
      text.get_preferred_size (out twidth, out theight, null, null);

      var padding = 35;
      var x = (width/2) - ((int)twidth/2) - padding;
      var y = (height/2) - ((int)theight/2) - padding;
      var w = (int)twidth + (padding * 2);
      var h = (int)theight + (padding *2);

      cr.move_to (x, y + radius);
      cr.curve_to (x, y,
                   x, y,
                   x + radius, y);
      cr.line_to (x + w - radius, y);
      cr.curve_to (x + w, y,
                   x + w, y,
                   x + w, y + radius);
      cr.line_to (x + w, y + h - radius);
      cr.curve_to (x + w, y + h,
                   x + w, y + h,
                   x + w - radius, y + h);
      cr.line_to (x + radius, y + h);
      cr.curve_to (x, y + h,
                   x, y + h,
                   x, y + h - radius);
      cr.close_path ();

      cr.set_source_rgba (1.0f, 1.0f, 1.0f, 0.4f);
      cr.fill_preserve ();

      cr.set_source_rgba (1.0f, 1.0f, 1.0f, 0.8f);
      cr.stroke ();
    }
  }
}

