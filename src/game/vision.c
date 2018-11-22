/*
** vision.c for game in /home/arbona/tek1/MUL/wolf3d
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Jan  5 18:53:27 2017 Thomas ARBONA
** Last update Sat Jan 21 21:03:54 2017 Thomas ARBONA
*/
#include <math.h>
#include <time.h>
#include <SFML/Graphics.h>
#include "level/level.h"
#include "raycast.h"
#include "util.h"
#include "game/vision.h"
#include "game/time.h"
#include "game/event/event.h"
#include "game/raycasting.h"
#include "game/action/shot.h"
#include "game/sprite/sprite.h"
#include "view/view.h"
#include "view/draw/draw.h"
#include "view/texture/texture.h"
#include "my_draw_line.h"

float	correct_fisheye(float dist, float scan, float dir)
{
  return (dist * cos((dir - scan) * M_PI / 180.));
}

static void	get_weapon_pos(sfVector2f *pos,
			       t_eventlist *el,
			       t_texture *texture,
			       t_my_framebuffer *fbuff)
{
  t_frametime	*ftime;
  float		amp;
  float		speed;

  ftime = frametime_get();
  amp = (el->mouse_lclk && !el->dkey_z) ? 20. :
    (el->key_z) ? 45. :
    (el->dkey_z) ? 150. : 40.;
  speed = (el->key_z) ? 250. :
    (el->dkey_z) ? 120. : 1000.;
  pos->x = (float)fbuff->width / 2. +
    cos((float)ftime->start_dur / speed) * amp;
  pos->y = fbuff->height - texture->size.y +
    sin((float)ftime->start_dur / speed * 2) * (amp / 10.) + 40;
  pos->x += (action_is_shooting()) ? 20 :
    (action_was_shooting()) ? 10 : 0;
  pos->y += (action_is_shooting()) ? 20 :
    (action_was_shooting()) ? 10 : 0;
}

static void		draw_weapon_target()
{
  static sfVector2f	pos;
  static t_video	*video;
  static t_texture	*texture;
  static int		call = 0;

  if (call == 0)
    {
      texture = texture_get(8, 0);
      video = view_getvideo();
      pos.x = video->fbuff.width / 2 - texture->size.x / 2;
      pos.y = video->fbuff.height / 2 - texture->size.y / 1.5;
      call = 1;
    }
  draw_img(texture->img, &pos);
}

static void	handle_weapon(t_my_framebuffer *fbuff)
{
  t_texture	*texture;
  t_texture	*texture2;
  sfVector2f	pos;
  sfVector2f	pos2;
  t_eventlist	*el;

  el = event_getlist();
  texture = texture_get(1, 0);
  get_weapon_pos(&pos, el, texture, fbuff);
  if (action_is_shooting() || action_was_shooting())
    {
      pos2 = (sfVector2f){pos.x + 250, pos.y + 50};
      texture2 = texture_get(2, action_was_shooting());
      draw_rotate_img_game(texture2->img, &pos2, RAND(0, 360), 0.5);
    }
  if (el->dkey_z)
    {
      pos = (sfVector2f){pos.x - 100, pos.y + 350};
      draw_rotate_img_game(texture->img, &pos, -30, 0.5);
    }
  else
    {
      draw_img_game(texture->img, &pos, 0.5);
      draw_weapon_target();
    }
}

void			game_updatevision(t_video *vd)
{
  raycasting_make();
  sprite_handle();
  sfTexture_updateFromPixels(vd->texture, vd->fbuff.pixels,
			     vd->fbuff.width, vd->fbuff.height, 0, 0);
  sfTexture_updateFromPixels(vd->dist_text, vd->dist_fbuff.pixels,
  			     vd->fbuff.width, vd->fbuff.height, 0, 0);
  sfTexture_updateFromPixels(vd->side_text, vd->side_fbuff.pixels,
  			     vd->fbuff.width, vd->fbuff.height, 0, 0);
  sfShader_setTextureParameter(vd->shader, "dist", vd->dist_text);
  sfShader_setTextureParameter(vd->shader, "side", vd->side_text);
  sfShader_setFloat4Parameter(vd->shader, "lightColor", 226., 88., 34., 255.);
  sfShader_setFloat3Parameter(vd->shader, "lightPos", SQRT2D2, 0.0, SQRT2D2);
  sfShader_setFloatParameter(vd->shader, "shooting",
			     (float)(action_was_shooting() ||
				     action_is_shooting()));
  sfRenderWindow_drawSprite(vd->window, vd->sprite, &vd->state);
  handle_weapon(&vd->fbuff);
}
