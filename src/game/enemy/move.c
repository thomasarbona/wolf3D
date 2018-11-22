/*
** move.c for game in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sat Jan  7 18:04:03 2017 Thomas ARBONA
** Last update Tue Jan 17 22:49:46 2017 Thomas ARBONA
*/
#include <SFML/System/Vector2.h>
#include "game/enemy/enemy.h"
#include "level/level.h"
#include "move_forward.h"
#include "util.h"

static void	slide_onwall(sfVector2f *cnext_pos,
			     sfVector2f *next_pos,
			     t_sprite *mob,
			     t_level *level)
{
  if (0 <= LOWINT(cnext_pos->y) && LOWINT(cnext_pos->y) < level->map.size.y &&
      0 <= LOWINT(next_pos->y) && LOWINT(next_pos->y) < level->map.size.y &&
      map_getf(mob->pos.x, cnext_pos->y)->wall == 0 &&
      map_getf(mob->pos.x, next_pos->y)->wall == 0)
    mob->pos.y = next_pos->y;
  else if  (0 <= LOWINT(cnext_pos->x) &&
	    LOWINT(cnext_pos->x) < level->map.size.x &&
	    0 <= LOWINT(next_pos->x) &&
	    LOWINT(next_pos->x) < level->map.size.x &&
	    map_getf(cnext_pos->x, mob->pos.y)->wall == 0 &&
	    map_getf(next_pos->x, mob->pos.y)->wall == 0)
    mob->pos.x = next_pos->x;
}

void		enemy_move(t_sprite *mob)
{
  t_level	*level;
  sfVector2f	cnext_pos;
  sfVector2f	next_pos;

  level = level_get();
  cnext_pos = move_forward(mob->pos, mob->dir, MOB_MOVE_DIST + MOB_MOVE_CALIB);
  next_pos = move_forward(mob->pos, mob->dir, MOB_MOVE_DIST);
  if (0 <= LOWINT(cnext_pos.x) && LOWINT(cnext_pos.x) < level->map.size.x &&
      0 <= LOWINT(cnext_pos.y) && LOWINT(cnext_pos.y) < level->map.size.y &&
      0 <= LOWINT(next_pos.x) && LOWINT(next_pos.x) < level->map.size.x &&
      0 <= LOWINT(next_pos.y) && LOWINT(next_pos.y) < level->map.size.y &&
      map_getf(cnext_pos.x, cnext_pos.y)->wall == 0 &&
      map_getf(next_pos.x, next_pos.y)->wall == 0)
    mob->pos = next_pos;
  else
    slide_onwall(&cnext_pos, &next_pos, mob, level);
}
