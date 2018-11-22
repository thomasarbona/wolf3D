/*
** sprite.c for draw in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sun Jan 15 21:18:30 2017 Thomas ARBONA
** Last update Sun Jan 15 22:06:46 2017 Thomas ARBONA
*/
#include <SFML/System/Vector2.h>
#include "view/view.h"
#include "view/draw/draw.h"
#include "view/shader.h"
#include "view/texture/texture.h"
#include "my_put_pixel.h"
#include "game/sprite/sprite.h"
#include "game/zbuffer.h"

void		draw_sprite_line(t_fromto *fromto,
				 sfVector2i *sprt_size,
				 sfVector2i *sprt_scrn,
				 t_sprites *sprite)
{
  sfVector2i	text_pxl;
  sfColor	color;
  int		y;
  int		d;
  t_video	*video;
  t_texture	*texture;

  video = view_getvideo();
  texture = texture_get(sprite->sprite->img, sprite->sprite->state);
  text_pxl.x =
    (int)(256 * (fromto->from.x - (-sprt_size->x / 2 + sprt_scrn->x)) *
	  texture->size.x / sprt_size->x) / 256;
  y = fromto->from.y;
  while (y < fromto->to.y)
    {
      d = (y) * 256 - video->fbuff.height * 128 + sprt_size->y * 128;
      text_pxl.y = ((d * texture->size.y) / sprt_size->y) / 256;
      color = sfImage_getPixel(texture->img, text_pxl.x, text_pxl.y);
      if (color.a != 0)
	{
	  my_put_pixel(&video->fbuff, fromto->from.x, y, color);
	  set_shaderbuff(fromto->from.x, y, sprite->sprite->dist, 0);
	}
      y += 1;
    }
}

void		draw_sprite(t_sprites *sprite,
			    sfVector2i *sprt_size,
			    sfVector2i *sprt_scrn)
{
  t_fromto	fromto;
  t_video	*video;

  video = view_getvideo();
  fromto.from.y = -sprt_size->y / 2 + video->fbuff.height / 2;
  fromto.to.y = sprt_size->y / 2 + video->fbuff.height / 2;
  if (fromto.from.y < 0)
    fromto.from.y = 0;
  if (fromto.to.y > video->fbuff.height)
    fromto.to.y = video->fbuff.height;
  fromto.from.x = -sprt_size->x / 2 + sprt_scrn->x;
  fromto.to.x = sprt_size->x / 2 + sprt_scrn->x;
  if (fromto.from.x < 0)
    fromto.from.x = 0;
  if (fromto.to.x > video->fbuff.width)
    fromto.to.x = video->fbuff.width;
  while (fromto.from.x < fromto.to.x)
    {
      if (fromto.from.x > 0 && fromto.from.x < video->fbuff.width &&
	  sprite->sprite->dist > 0 &&
	  sprite->sprite->dist < zbuffer_getdist(fromto.from.x))
	draw_sprite_line(&fromto, sprt_size, sprt_scrn, sprite);
      fromto.from.x += 1;
    }
}
