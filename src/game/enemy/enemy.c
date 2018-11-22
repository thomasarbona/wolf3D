/*
** enemy.c for game in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Mon Jan 16 18:24:41 2017 Thomas ARBONA
** Last update Sat Jan 21 19:25:05 2017 Thomas ARBONA
*/
#include <unistd.h>
#include <math.h>
#include "game/frame/frame.h"
#include "game/enemy/enemy.h"
#include "game/sprite/sprite.h"
#include "sound/sound.h"
#include "level/level.h"
#include "raycast.h"

static void	enemy_walk(t_sprite *mob, t_level *level)
{
  static int	count = 0;
  sfVector2f	inc;
  float		angle;
  t_raydata	rdata;

  inc.x = mob->pos.x - level->player.pos.x;
  inc.y = mob->pos.y - level->player.pos.y;
  angle = 360 - (180 - atan2(inc.y, inc.x) * (180. / M_PI));
  raycast(&rdata, mob->pos, angle, level);
  if (mob->dist < rdata.dist || mob->follow)
    {
      mob->dir = angle;
      mob->follow = 1;
    }
  if (mob->dist > MOB_MOVE_CALIB)
    enemy_move(mob);
  else
    {
      level->player.life -= MOB_BITE;
      count += 1;
      if (count % 10 == 0)
	sound_play(2);
    }
}

static void	enemy_handle_state(t_sprite *mob)
{
  t_level	*level;

  level = level_get();
  if (mob->state >= 12)
    return;
  if (mob->state >= 4)
    {
      mob->state += MOB_DIE_SPD;
      return;
    }
  enemy_walk(mob, level);
  if (level->player.life <= 0)
    frame_set(FRAME_OVER);
  mob->state += MOB_MOVE_SPD;
  if (mob->state >= 4)
    mob->state = 0;

}

void		enemy_handle()
{
  t_sprites	**list;
  t_sprites	*curr;

  list = sprite_getall();
  curr = *list;
  while (curr != NULL)
    {
      if (curr->sprite->type == SPRT_MOB)
	enemy_handle_state(curr->sprite);
      curr = curr->next;
    }
}
