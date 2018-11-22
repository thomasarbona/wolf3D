/*
** text.c for draw in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Jan 17 23:53:37 2017 Thomas ARBONA
** Last update Sat Jan 21 18:19:34 2017 Thomas ARBONA
*/
#include <SFML/System/Vector2.h>
#include "view/view.h"

void		draw_text(char *str, sfVector2f pos, int size)
{
  sfText	*text;
  t_video	*video;

  video = view_getvideo();
  text = sfText_create();
  sfText_setString(text, str);
  sfText_setFont(text, video->font);
  sfText_setPosition(text, pos);
  sfText_setCharacterSize(text, size);
  sfRenderWindow_drawText(video->window, text, NULL);
}

void		draw_text_clr(char *str,
			      sfVector2f pos,
			      int size,
			      sfColor color)
{
  sfText	*text;
  t_video	*video;

  video = view_getvideo();
  text = sfText_create();
  sfText_setString(text, str);
  sfText_setFont(text, video->font);
  sfText_setPosition(text, pos);
  sfText_setColor(text, color);
  sfText_setCharacterSize(text, size);
  sfRenderWindow_drawText(video->window, text, NULL);
}
