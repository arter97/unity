/*
 *      icon-postprocessor.vala
 *      Copyright (C) 2010 Canonical Ltd
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 *
 *
 *      Authored by Gordon Allott <gord.allott@canonical.com>
 */
using Cairo;

namespace Unity
{
  /* General colour theory utility functions, could maybe be somewhere else
   * but i guess its fine in here for now - as long as its in the Unity namespace
   * it does not really matter
   */
  /* converts from rgb to hsv colour space */
  public static void rgb_to_hsv (float r, float g, float b,
                                 out float hue, out float sat, out float val)
  {
    float min, max;
    if (r > g)
      max = (r > b) ? r : b;
    else
      max = (g > b) ? g : b;
    if (r < g)
      min = (r < b) ? r : b;
    else
      min = (g < b) ? g : b;

    val = max;

    float delta = max - min;
    if (delta > 0.000001)
      {
        sat = delta / max;
        hue = 0.0f;
        if (r == max)
          {
            hue = (g - b) / delta;
            if (hue < 0.0f)
              hue += 6.0f;
          }
        else if (g == max)
          {
            hue = 2.0f + (b - r) / delta;
          }
        else if (b == max)
          {
            hue = 4.0f + (r - g) / delta;
          }
        hue /= 6.0f;
      }
    else
      {
        sat = 0.0f;
        hue = 0.0f;
      }
  }

  public static void hsv_to_rgb (float hue, float sat, float val,
                                 out float r, out float g, out float b)
  {
    int    i;
    float f, w, q, t;

    if (sat == 0.0)
      {
       r = g = b = val;
      }
    else
     {
       if (hue == 1.0)
          hue = 0.0f;

       hue *= 6.0f;

       i = (int) hue;
       f = hue - i;
       w = val * (1.0f - sat);
       q = val * (1.0f - (sat * f));
       t = val * (1.0f - (sat * (1.0f - f)));

       switch (i)
       {
         case 0:
           r = val;
           g = t;
           b = w;
           break;
         case 1:
           r = q;
           g = val;
           b = w;
           break;
         case 2:
           r = w;
           g = val;
           b = t;
           break;
         case 3:
           r = w;
           g = q;
           b = val;
           break;
         case 4:
           r = t;
           g = w;
           b = val;
           break;
         case 5:
           r = val;
           g = w;
           b = q;
           break;
       }
     }
  }

  public static void get_average_color (Gdk.Pixbuf source, out uint red, out uint green, out uint blue)
  {
    int num_channels = source.get_n_channels ();
    int width = source.get_width ();
    int height = source.get_height ();
    int rowstride = source.get_rowstride ();
    float r, g, b, a, hue, sat, val;
    unowned uchar[] pixels = source.get_pixels ();
    if (source.get_colorspace () != Gdk.Colorspace.RGB ||
        source.get_bits_per_sample () != 8 ||
        !source.get_has_alpha () ||
        num_channels != 4)
      {
        // we can't deal with this pixbuf =\
        red = 255;
        green = 255;
        blue = 255;
        return;
      }

    double r_total, g_total, b_total;
    r_total = g_total = b_total = 0.0;

    int i = 0;
    for (int y = 0; y < height; y++)
    {
      for (int x = 0; x < width; x++)
      {
        int pix_index = i + (x*4);
        r = pixels[pix_index + 0] / 256.0f;
        g = pixels[pix_index + 1] / 256.0f;
        b = pixels[pix_index + 2] / 256.0f;
        a = pixels[pix_index + 3] / 256.0f;

        if (a < 1.0 / 256.0)
          continue;

        rgb_to_hsv (r, g, b, out hue, out sat, out val);
        // we now have the saturation and value! wewt.
        r_total += (r * sat) * a;
        g_total += (g * sat) * a;
        b_total += (b * sat) * a;
      }
      i = y * (width * 4) + rowstride;
    }
    // okay we should now have a large value in our totals
    r_total = r_total / (width * height);
    g_total = g_total / (width * height);
    b_total = b_total / (width * height);

    // get a new super saturated value based on our totals
    rgb_to_hsv ((float)r_total, (float)g_total, (float)b_total, out hue, out sat, out val);
    hsv_to_rgb (hue, Math.fminf (sat + 0.6f, 1.0f), 0.5f, out r, out g, out b);

    red = (uint)(r * 255);
    green = (uint)(g * 255);
    blue = (uint)(b * 255);
  }

  /* just a layered actor that layers the different components of our
   * icon on top of each other
   */
  private static Clutter.Texture? unity_icon_bg_layer; //background
  private static Clutter.Texture? unity_icon_fg_layer; //foreground
  private static Clutter.Texture? unity_icon_mk_layer; //mask

  public class UnityIcon : Ctk.Actor
  {
    public Clutter.Texture? icon {get; construct;}
    public Clutter.Texture? bg_color {get; construct;}

    private Cogl.Material bg_mat;
    private Cogl.Material fg_mat;
    private Cogl.Material icon_material;
    private Cogl.Material bgcol_material;


    public UnityIcon (Clutter.Texture? icon, Clutter.Texture? bg_tex)
    {
      Object (icon: icon, bg_color: bg_tex);
    }

    construct
    {
      if (!(unity_icon_bg_layer is Clutter.Texture))
        {
          unity_icon_bg_layer = new ThemeImage ("prism_icon_background");
          unity_icon_fg_layer = new ThemeImage ("prism_icon_foreground");
          unity_icon_mk_layer = new ThemeImage ("prism_icon_mask");
        }

      if (this.icon is Clutter.Texture)
        {
          this.icon.set_parent (this);
          var icon_mat = new Cogl.Material ();
          Cogl.Texture icon_tex = (Cogl.Texture)(this.icon.get_cogl_texture ());
          Cogl.Texture mask_tex = (Cogl.Texture)(unity_icon_mk_layer.get_cogl_texture ());
          icon_mat.set_layer (0, icon_tex);
          icon_mat.set_layer (1, mask_tex);
          this.icon_material = icon_mat;
        }
      if (this.bg_color is Clutter.Texture)
        {
          this.bg_color.set_parent (this);
          this.bgcol_material = new Cogl.Material ();
          Cogl.Texture color = (Cogl.Texture)(this.bg_color.get_cogl_texture ());
          Cogl.Texture mask_tex = (Cogl.Texture)(unity_icon_mk_layer.get_cogl_texture ());
          this.bgcol_material.set_layer (0, color);
          this.bgcol_material.set_layer_filters (1, Cogl.MaterialFilter.NEAREST, Cogl.MaterialFilter.NEAREST);
          this.bgcol_material.set_layer (1, mask_tex);
        }

        var mat = new Cogl.Material ();
        Cogl.Texture tex = (Cogl.Texture)(unity_icon_bg_layer.get_cogl_texture ());
        mat.set_layer (0, tex);
        this.bg_mat = mat;

        mat = new Cogl.Material ();
        tex = (Cogl.Texture)(unity_icon_fg_layer.get_cogl_texture ());
        mat.set_layer (0, tex);
        this.fg_mat = mat;
    }

    public override void get_preferred_width (float for_height,
                                              out float minimum_width,
                                              out float natural_width)
    {
      natural_width = minimum_width = 48;
    }

    public override void get_preferred_height (float for_width,
                                               out float minimum_height,
                                               out float natural_height)
    {
      natural_height = minimum_height = 48;
    }

    public override void allocate (Clutter.ActorBox box, Clutter.AllocationFlags flags)
    {
      base.allocate (box, flags);
      if (this.icon is Clutter.Texture)
        this.icon.allocate (box, flags);
      if (this.bg_color is Clutter.Texture)
        this.bg_color.allocate (box, flags);
    }

    public override void pick (Clutter.Color color)
    {
      this.set_effects_painting (true);
      var mat = new Cogl.Material ();
      mat.set_color4ub (color.red, color.green, color.blue, color.alpha);
      Cogl.rectangle (0, 0, 48, 48);
      base.pick (color);
      this.set_effects_painting (false);
    }

    /* The closest most horrible thing you will ever see in vala. its basically
     * C code... - oh well it works
     */
    public static void paint_real (Clutter.Actor actor)
    {
      UnityIcon self = actor as UnityIcon;

      Clutter.ActorBox box = Clutter.ActorBox ();
      self.get_stored_allocation (out box);

      /* we draw everything with cogl because Clutter.Texture seems to be made
       * of dumb. also it likes to double allocate everything
       */
      uchar opacity = self.get_paint_opacity ();

      self.bg_mat.set_color4ub (opacity, opacity, opacity, opacity);
      self.bgcol_material.set_color4ub (opacity, opacity, opacity, opacity);
      self.icon_material.set_color4ub (opacity, opacity, opacity, opacity);
      self.fg_mat.set_color4ub (opacity, opacity, opacity, opacity);

      Cogl.set_source (self.bg_mat);
      Cogl.rectangle (box.x1, box.y1, box.x2, box.y2);

      if (self.bg_color is Clutter.Texture)
        {
          Cogl.set_source (self.bgcol_material);
          Cogl.rectangle (box.x1, box.y1, box.x2, box.y2);
        }
      if (self.icon is Clutter.Texture)
        {
          int width, height;
          float xpad, ypad;
          self.icon.get_base_size (out width, out height);

          xpad = (box.get_width () - width) / 2.0f;
          ypad = (box.get_height () - height) / 2.0f;

          Cogl.set_source (self.icon_material);
          Cogl.rectangle (xpad, ypad, box.x2 - xpad, box.y2 - ypad);
        }

      Cogl.set_source (self.fg_mat);
      Cogl.rectangle (box.x1, box.y1, box.x2, box.y2);
    }

    public override void paint ()
    {
      /* we need a beter way of doing this effects stuff in vala, its horrible
       * to do, must have a think...
       */
      unowned SList<Ctk.Effect> effects = this.get_effects ();
      if (!this.get_effects_painting () && effects != null)
        {
          unowned SList<Ctk.Effect> e;
          this.set_effects_painting (true);
          for (e = effects; e != null; e = e.next)
            {
              Ctk.Effect effect = e.data;
              bool last_effect = (e.next != null) ? false : true;
              effect.paint (this.paint_real, last_effect);
            }

          this.set_effects_painting (false);
        }
      else
        {
          this.paint_real (this);
        }
    }

    public override void map ()
    {
      base.map ();
      this.icon.map ();
    }

    public override void unmap ()
    {
      base.unmap ();
      this.icon.unmap ();
    }
  }
}
