/*
** handle.c for sprite in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Fri Jan 13 19:30:03 2017 Thomas ARBONA
** Last update Wed Mar  8 11:10:01 2017 Thomas ARBONA
** Last update Mon Jan 23 21:07:07 2017 Thomas ARBONA
*/
#include <math.h>
#include <stdlib.h>
#include "game/vision.h"
#include "game/zbuffer.h"
#include "game/action/action.h"
#include "game/sprite/sprite.h"
#include "view/texture/texture.h"
#include "view/shader.h"
#include "level/level.h"
#include "view/view.h"
#include "view/draw/draw.h"
#include "my_put_pixel.h"

static int	get_sprtscrn_x(t_video *video, float angle_tmp, float angle)
{
  return ((int)((float)video->fbuff.width -
		(((angle_tmp - angle) +
		  ((angle_tmp > 270 && angle < 90) ? -360 :
		   (angle > 270 && angle_tmp < 90) ? 360 : 0)) *
		 (video->fbuff.width / (float)VISION_FOV) +
		 (video->fbuff.width / 2.))));
}

static int	isin_target(t_sprite *sprite,
			    int sprt_scrn,
			    int sprt_size,
			    t_video *video)
{
  return (sprt_scrn >= video->fbuff.width / 2 - sprt_size / 4 &&
	  sprt_scrn <= video->fbuff.width / 2 + sprt_size / 4 &&
	  sprite->dist < zbuffer_getdist(video->fbuff.width / 2) &&
	  sprite->state < 4);
}

void		sprite_compute_dist(t_sprites *list, sfVector2f *player_pos)
{
  t_sprites	*curr;

  curr = list;
  while (curr != NULL)
    {
      curr->sprite->dist =
	sqrt((player_pos->x - curr->sprite->pos.x) *
	     (player_pos->x - curr->sprite->pos.x) +
	     (player_pos->y - curr->sprite->pos.y) *
	     (player_pos->y - curr->sprite->pos.y));
      curr = curr->next;
    }
}

void		sprite_draweach(t_sprites **list,
				float angle,
				t_level *level,
				t_video *video)
{
  sfVector2f	inc;
  sfVector2i	sprt_scrn;
  sfVector2i	sprt_size;
  t_sprites	*curr;
  float		angle_tmp;

  curr = *list;
  level->player.mob_target = -1;
  while (curr != NULL)
    {
      if (curr->sprite->type == SPRT_MUN && curr->sprite->dist < DROP_DIST)
	{
	  action_drop(curr->sprite);
	  curr = sprite_destroy(curr->sprite->id);
	  continue;
	}
      inc.x = curr->sprite->pos.x - level->player.pos.x;
      inc.y = curr->sprite->pos.y - level->player.pos.y;
      angle_tmp = atan2(inc.y, inc.x) * (180. / M_PI);
      if (angle_tmp < 0)
	angle_tmp += 360;
      sprt_scrn.x = get_sprtscrn_x(video, angle_tmp, angle);
      sprt_size.y = abs(video->fbuff.height / curr->sprite->dist);
      sprt_size.x = abs(video->fbuff.height / curr->sprite->dist);
      if (curr->sprite->type == SPRT_MOB &&
	  isin_target(curr->sprite, sprt_scrn.x, sprt_size.x, video))
	level->player.mob_target = curr->sprite->id;
      draw_sprite(curr, &sprt_size, &sprt_scrn);
      curr = curr->next;
    }
}

void		sprite_handle()
{
  t_level	*level;
  t_video	*video;
  t_sprites	**list;
  float		angle;

  list = sprite_getall();
  if (*list == NULL)
    return;
  level = level_get();
  video = view_getvideo();
  angle = level->player.dir;
  while (angle < 0)
    angle += 360;
  while (angle >= 360)
    angle -= 360;
  sprite_compute_dist(*list, &level->player.pos);
  sprite_sort();
  sprite_draweach(list, angle, level, video);
}
