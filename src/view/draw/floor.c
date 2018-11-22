/*
** floor.c for draw in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sat Jan  7 19:58:37 2017 Thomas ARBONA
** Last update Sun Jan 15 23:12:32 2017 Thomas ARBONA
*/
#include <SFML/System/Vector2.h>
#include "view/view.h"
#include "view/texture/texture.h"
#include "view/framebuffer.h"
#include "game/vision.h"
#include "view/shader.h"
#include "util.h"
#include "raycast.h"
#include "my_put_pixel.h"

sfVector2f	get_floor_wall(t_raydata *raydata)
{
  sfVector2f	floor_wall;

  if (raydata->side == SIDE_RIGHT)
    {
      floor_wall.x = LOWINT(raydata->inter.x);
      floor_wall.y = LOWINT(raydata->inter.y) + raydata->prop;
    }
  else if (raydata->side == SIDE_LEFT)
    {
      floor_wall.x = LOWINT(raydata->inter.x) + 1.;
      floor_wall.y = LOWINT(raydata->inter.y) + raydata->prop;
    }
  else if (raydata->side == SIDE_DOWN)
    {
      floor_wall.x = LOWINT(raydata->inter.x) + raydata->prop;
      floor_wall.y = LOWINT(raydata->inter.y);
    }
  else
    {
      floor_wall.x = LOWINT(raydata->inter.x) + raydata->prop;
      floor_wall.y = LOWINT(raydata->inter.y) + 1.;
    }
  return (floor_wall);
}

static void	draw_floor_pxl(t_my_framebuffer *fbuff,
			       sfVector2i *from,
			       sfVector2f *curr_floor,
			       float curr_dist)
{
  t_block	*block;

  block = map_getf(curr_floor->x, curr_floor->y);
  my_put_pixel(fbuff, from->x, from->y,
	       texture_getclr_prop(block->floor, 0, curr_floor));
  my_put_pixel(fbuff, from->x, fbuff->height - from->y,
	       texture_getclr_prop(block->ceil, 0, curr_floor));
  set_shaderbuff(from->x, from->y, curr_dist, SIDE_FLOOR);
}

void		draw_floor_line(t_raydata *raydata,
				t_my_framebuffer *fbuff,
				int index,
				float wall_dist)
{
  t_level	*level;
  sfVector2i	from;
  sfVector2f	flr_wll;
  sfVector2f	curr_floor;
  float		curr_dist;
  float		weight;
  float		wall_end;
  float		wall_height;

  level = level_get();
  from.x = index;
  flr_wll = get_floor_wall(raydata);
  wall_height = (fbuff->height / (raydata->dist * VIEW_RATIO)) * VIEW_RATIO;
  wall_end = fbuff->height - ((fbuff->height - (int)wall_height) / 2);
  if (wall_end < 0 || wall_end >= fbuff->height)
    wall_end = fbuff->height - 1;
  from.y = wall_end + 1;
  while (from.y++ != fbuff->height)
    {
      curr_dist = fbuff->height / (2. * from.y - fbuff->height);
      weight = curr_dist / wall_dist;
      curr_floor.x = weight * flr_wll.x + (1. - weight) * level->player.pos.x;
      curr_floor.y = weight * flr_wll.y + (1. - weight) * level->player.pos.y;
      draw_floor_pxl(fbuff, &from, &curr_floor, curr_dist);
    }
}

void		draw_floor(int index,
			   t_raydata *raydata,
			   t_my_framebuffer *fbuff)
{
  float		wall_dist;

  wall_dist = raydata->dist * VIEW_RATIO;
  draw_floor_line(raydata, fbuff, index, wall_dist);
}
