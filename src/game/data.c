/*
** data.c for game in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Jan 18 10:49:55 2017 Thomas ARBONA
** Last update Wed Jan 18 11:33:20 2017 Thomas ARBONA
*/
#include <SFML/System/Vector2.h>
#include "view/texture/texture.h"
#include "level/level.h"
#include "view/draw/draw.h"
#include "my.h"

void		game_displaydata()
{
  sfVector2f	pos;
  t_level	*level;
  t_texture	*texture;

  level = level_get();
  texture = texture_get(9, (level->player.munition == 0));
  pos.x = 10;
  pos.y = 10;
  draw_img(texture->img, &pos);
  pos.x += 80;
  draw_text(my_asprintf("%i", level->player.munition), pos, 45);
  pos.x = 10;
  pos.y = 80;
  texture = texture_get(10, (level->player.life < 10));
  draw_img(texture->img, &pos);
  pos.x += 80;
  pos.y -= 5;
  draw_text(my_asprintf("%i", (int)level->player.life), pos, 45);
}
