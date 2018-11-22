/*
** drop.c for game in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Jan 18 12:12:14 2017 Thomas ARBONA
** Last update Sat Jan 21 18:14:03 2017 Thomas ARBONA
*/
#include "game/sprite/sprite.h"
#include "level/level.h"
#include "sound/sound.h"
#include "game/action/action.h"

void		action_drop(t_sprite *obj)
{
  t_level	*level;

  (void)obj;
  level = level_get();
  level->player.munition += MUN_DROP;
  sound_play(4);
}
