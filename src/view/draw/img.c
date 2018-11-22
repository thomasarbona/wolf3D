/*
** img.c for draw in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sun Jan  8 22:13:07 2017 Thomas ARBONA
** Last update Mon Jan 16 19:50:50 2017 Thomas ARBONA
*/
#include <SFML/Graphics.h>
#include "view/view.h"

void		draw_rotate_img_game(sfImage *img,
				sfVector2f *pos,
				float angle,
				float dist)
{
  t_video	*video;
  sfSprite	*sprite;
  sfTexture	*texture;
  sfVector2u	size;
  sfVector2f	origin;

  video = view_getvideo();
  if (!(sprite = sfSprite_create()) ||
      !(texture = sfTexture_createFromImage(img, NULL)))
    return;
  sfSprite_setTexture(sprite, texture, 1);
  size = sfImage_getSize(img);
  origin.x = size.x / 2.;
  origin.y = size.y / 2.;
  sfSprite_setPosition(sprite, *pos);
  sfSprite_setOrigin(sprite, origin);
  sfSprite_setRotation(sprite, angle);
  sfShader_setFloat4Parameter(video->obj_shader, "lightColor",
			      226., 88., 34., 255.);
  sfShader_setFloatParameter(video->obj_shader, "dist", dist);
  sfRenderWindow_drawSprite(video->window, sprite, &video->obj_state);
  sfTexture_destroy(texture);
  sfSprite_destroy(sprite);
}

void	draw_img(sfImage *img, sfVector2f *pos)
{
  t_video		*video;
  sfSprite		*sprite;
  sfTexture		*texture;

  video = view_getvideo();
  if (!(sprite = sfSprite_create()) ||
      !(texture = sfTexture_createFromImage(img, NULL)))
    return;
  sfSprite_setTexture(sprite, texture, 1);
  sfSprite_setPosition(sprite, *pos);
  sfRenderWindow_drawSprite(video->window, sprite, NULL);
  sfTexture_destroy(texture);
  sfSprite_destroy(sprite);
}

void			draw_img_game(sfImage *img,
					sfVector2f *pos,
					float dist)
{
  t_video		*video;
  sfSprite		*sprite;
  sfTexture		*texture;

  video = view_getvideo();
  if (!(sprite = sfSprite_create()) ||
      !(texture = sfTexture_createFromImage(img, NULL)))
    return;
  sfSprite_setTexture(sprite, texture, 1);
  sfSprite_setPosition(sprite, *pos);
  sfShader_setFloat4Parameter(video->obj_shader, "lightColor",
			      226., 88., 34., 255.);
  sfShader_setFloatParameter(video->obj_shader, "dist", dist);
  sfRenderWindow_drawSprite(video->window, sprite, &video->obj_state);
  sfTexture_destroy(texture);
  sfSprite_destroy(sprite);
}
