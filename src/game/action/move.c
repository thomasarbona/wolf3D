/*
** move.c for game in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sat Jan  7 18:04:03 2017 Thomas ARBONA
** Last update Tue Jan 17 22:49:57 2017 Thomas ARBONA
*/
#include <SFML/System/Vector2.h>
#include "level/level.h"
#include "game/action/move.h"
#include "move_forward.h"
#include "raycast.h"
#include "util.h"

void	action_turn(sfVector2i *delta)
{
  t_level	*level;

  level = level_get();
  level->player.dir += delta->x * MOVE_TURN;
}

static void	slide_onwall(sfVector2f *cnext_pos,
			     sfVector2f *next_pos,
			     sfVector2f *player_pos,
			     t_level	*level)
{
  if (0 <= LOWINT(cnext_pos->y) && LOWINT(cnext_pos->y) < level->map.size.y &&
      0 <= LOWINT(next_pos->y) && LOWINT(next_pos->y) < level->map.size.y &&
      map_getf(player_pos->x, cnext_pos->y)->wall == 0 &&
      map_getf(player_pos->x, next_pos->y)->wall == 0)
    level->player.pos.y = next_pos->y;
  else if  (0 <= LOWINT(cnext_pos->x) &&
	    LOWINT(cnext_pos->x) < level->map.size.x &&
	    0 <= LOWINT(next_pos->x) &&
	    LOWINT(next_pos->x) < level->map.size.x &&
	    map_getf(cnext_pos->x, player_pos->y)->wall == 0 &&
	    map_getf(next_pos->x, player_pos->y)->wall == 0)
    level->player.pos.x = next_pos->x;
}

void		action_move(float move_dir, float move_dist)
{
  t_level	*level;
  sfVector2f	cnext_pos;
  sfVector2f	next_pos;
  sfVector2f	player_pos;

  level = level_get();
  player_pos = level->player.pos;
  cnext_pos = move_forward(player_pos, level->player.dir + move_dir,
			   move_dist + MOVE_CALIB);
  next_pos = move_forward(player_pos, level->player.dir + move_dir,
			  move_dist);
  if (0 <= LOWINT(cnext_pos.x) && LOWINT(cnext_pos.x) < level->map.size.x &&
      0 <= LOWINT(cnext_pos.y) && LOWINT(cnext_pos.y) < level->map.size.y &&
      0 <= LOWINT(next_pos.x) && LOWINT(next_pos.x) < level->map.size.x &&
      0 <= LOWINT(next_pos.y) && LOWINT(next_pos.y) < level->map.size.y &&
      map_getf(cnext_pos.x, cnext_pos.y)->wall == 0 &&
      map_getf(next_pos.x, next_pos.y)->wall == 0)
    level->player.pos = next_pos;
  else
    slide_onwall(&cnext_pos, &next_pos, &player_pos, level);
}
