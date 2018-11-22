/*
** wall.c for view in /home/arbona/tek1/MUL/wolf3d
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Jan  5 21:11:34 2017 Thomas ARBONA
** Last update Wed Jan 18 15:23:08 2017 Thomas ARBONA
*/
#include <SFML/System/Vector2.h>
#include "view/view.h"
#include "view/framebuffer.h"
#include "view/texture/texture.h"
#include "view/shader.h"
#include "view/draw/draw.h"
#include "game/vision.h"
#include "game/zbuffer.h"
#include "game/raycasting.h"
#include "level/level.h"
#include "my_put_pixel.h"
#include "raycast.h"
#include "util.h"

static void     init_vector(t_drw_wall *dw,
			    t_fromto *fromto,
			    t_raydata *raydata)
{
  dw->vector.x = ABS(fromto->to.x - fromto->from.x);
  dw->vector.y = ABS(fromto->to.y - fromto->from.y);
  dw->step.x = (fromto->from.x < fromto->to.x) ? 1 : -1;
  dw->step.y = (fromto->from.y < fromto->to.y) ? 1 : -1;
  dw->err.x = ((dw->vector.x > dw->vector.y)
	       ? dw->vector.x : -dw->vector.y) / 2;
  dw->text_y = 0;
  dw->start = fromto->from.y;
  dw->texture = texture_get(raydata->case_id, 0);
  dw->fromto = *fromto;
  zbuffer_setdist(fromto->from.x, raydata->dist);
}

static void	handle_damage(sfColor *color,
			      t_raydata *rdata,
			      int start,
			      sfVector2i y)
{
  t_block	*block;
  t_texture	*rift;
  sfColor	rift_clr;
  float		text_y;

  block = map_getf(rdata->inter.x, rdata->inter.y);
  if (block && block->breakable && block->state != 0)
    {
      rift = texture_get(0, block->state - 1);
      text_y = ((float)start - (float)y.x) *
	(float)rift->size.y / ((float)start - (float)y.y);
      rift_clr =
	sfImage_getPixel(rift->img,
			 (int)(rift->size.x * rdata->prop),
			 (int)text_y);
      if (rift_clr.a != 0)
	{
	  rift_clr.a = 180;
	  color_filter(color, &rift_clr);
	}
    }
}

static void	draw_wall_pxl(t_my_framebuffer *fbuff,
			      t_drw_wall *dw,
			      t_raydata *raydata,
			      int last_pxl)
{
  sfColor	color;

  if (dw->fromto.from.y <= 0)
    return;
  color = sfImage_getPixel(dw->texture->img,
			   (int)(dw->texture->size.x * raydata->prop),
			   (int)dw->text_y);
  if (!last_pxl)
    {
      handle_damage(&color, raydata, dw->start,
		    (sfVector2i){dw->fromto.from.y, dw->fromto.to.y});
    }
  my_put_pixel(fbuff, dw->fromto.from.x, dw->fromto.from.y, color);
  set_shaderbuff(dw->fromto.from.x, dw->fromto.from.y,
		 raydata->dist, raydata->side);
}

static void	draw_wall_line(t_my_framebuffer *fbuff,
			       t_fromto *fromto,
			       t_raydata *raydata)
{
  t_drw_wall	dw;

  init_vector(&dw, fromto, raydata);
  while ((dw.fromto.from.x != dw.fromto.to.x ||
	  dw.fromto.from.y != dw.fromto.to.y) &&
	 dw.fromto.from.y < fbuff->height)
    {
      draw_wall_pxl(fbuff, &dw, raydata, 0);
      dw.err.y = dw.err.x;
      if (dw.err.y < dw.vector.y && dw.fromto.from.y != dw.fromto.to.y)
	{
	  dw.err.x += dw.vector.x;
	  dw.fromto.from.y += dw.step.y;
	}
      if (dw.err.y > -dw.vector.x && dw.fromto.from.x != dw.fromto.to.x)
	{
	  dw.err.x -= dw.vector.y;
	  dw.fromto.from.x += dw.step.x;
	}
      if (dw.fromto.from.x != dw.fromto.to.x || dw.fromto.from.y != dw.fromto.to.y)
	dw.text_y = ((float)dw.start - (float)dw.fromto.from.y) *
	  (float)dw.texture->size.y / ((float)dw.start - (float)dw.fromto.to.y);
    }
  draw_wall_pxl(fbuff, &dw, raydata, 1);
}

void		draw_wall(int index, t_raydata *raydata, t_my_framebuffer *fbuff)
{
  float         wall_height;
  t_fromto	fromto;

  if (raydata->dist == 0)
    return;
  wall_height = (fbuff->height / (raydata->dist * VIEW_RATIO)) * VIEW_RATIO;
  fromto.from.x = index;
  fromto.from.y = (fbuff->height - (int)wall_height) / 2;
  fromto.to.x = index;
  fromto.to.y = fbuff->height - fromto.from.y;
  draw_wall_line(fbuff, &fromto, raydata);
}
