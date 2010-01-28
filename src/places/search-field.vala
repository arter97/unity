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
 * Authored by Jay Taoko <jay.taoko@canonical.com>
 *
 */
 
namespace Unity.Places.SearchField
{

  const string SEARCH_ICON = Unity.PKGDATADIR + "/search_icon.png";
  const string CLEAR_ICON = Unity.PKGDATADIR + "/favourites.png";

  public class View : Ctk.Box
  {
    private Ctk.Image search_icon;
    private Ctk.Image clear_icon;
    private Ctk.Text text_field;
    private CairoDrawing.RectangleBox rect_box;

    public override void allocate (Clutter.ActorBox        box,
                                   Clutter.AllocationFlags flags)
    {
      Clutter.ActorBox child_box = { 0.0f, 0.0f, 0.0f, 0.0f };
      float width = box.x2 - box.x1;
      base.allocate (box, flags);

      if (this.rect_box.Width != 200)
        {
          this.rect_box.CreateRectangleBox ( 200, 22);
        }

      child_box.x1 = 0;
      child_box.x2 = 200;
      child_box.y1 = 0;
      child_box.y2 = 22;
      this.rect_box.allocate (child_box, flags);

      child_box.x1 = 0;
      child_box.x2 = 22;
      child_box.y1 = 0;
      child_box.y2 = 22;
      search_icon.allocate (child_box, flags);

      child_box.x1 = child_box.x2 + 3;
      child_box.x2 = child_box.x1 + width -2*22 -6;
      child_box.y1 = 4;
      child_box.y2 = 22;
      text_field.allocate (child_box, flags);

      child_box.x1 = child_box.x2 + 3;
      child_box.x2 = child_box.x1 + 22;
      child_box.y1 = 0;
      child_box.y2 = 22;
      clear_icon.allocate (child_box, flags);
    }

    public View ()
    {
      search_icon = new Ctk.Image.from_filename (22, SEARCH_ICON);
      clear_icon = new Ctk.Image.from_filename (22, CLEAR_ICON);
      text_field = new Ctk.Text ("Search");
      rect_box = new CairoDrawing.RectangleBox ();

      this.add_actor (rect_box);
      this.add_actor (search_icon);
      this.add_actor (text_field);
      this.add_actor (clear_icon);

      text_field.set_reactive (true);
      text_field.set_editable (true);
      text_field.set_activatable (true);
      this.show_all ();
    }

    construct
    {
    }

    public override void map ()
    {
      base.map ();
    }

    public override void unmap ()
    {
      base.unmap ();
    }

    public override void paint ()
    {
     base.paint ();
    }

  }
}

