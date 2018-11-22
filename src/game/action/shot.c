/*
** shot.c for action in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Jan 10 23:02:13 2017 Thomas ARBONA
** Last update Wed Jan 18 16:29:17 2017 Thomas ARBONA
*/
#include "game/action/move.h"
#include "game/action/shot.h"
#include "game/time.h"
#include "game/sprite/sprite.h"
#include "raycast.h"
#include "level/level.h"
#include "sound/sound.h"

static t_shotdata	*get_shotdata()
{
  static t_shotdata	sdata;
  static int		call = 0;

  if (call == 0)
    {
      sdata.last_ms = 0;
      sdata.is_shooting = 0;
      sdata.was_shooting = 0;
      call = 1;
    }
  return (&sdata);
}

int	action_is_shooting()
{
  return (get_shotdata()->is_shooting);
}

int	action_was_shooting()
{
  return (get_shotdata()->was_shooting);
}

static void	action_shot(t_shotdata *sdata)
{
  t_level	*level;
  t_raydata	rdata;
  t_block	*block;
  t_sprite	*sprite;

  level = level_get();
  if (level->player.munition == 0)
    return (sound_play(3));
  sdata->is_shooting = 1;
  sound_play(0);
  level->player.munition -= 1;
  if (level->player.mob_target != -1)
    {
      sprite = sprite_getid(level->player.mob_target);
      sprite->shoot += 1;
      if (sprite->shoot == 3)
	sprite->state = 4;
      sound_play(2);
      return;
    }
  raycast(&rdata, level->player.pos, level->player.dir, level);
  block = map_getf(rdata.inter.x, rdata.inter.y);
  if (block && block->breakable)
    {
      block->state += 1;
      if (block->state == 11)
	{
	  block->wall = 0;
	  sound_play(1);
	}
    }
}

void			action_handle_shot(int click, int running)
{
  t_shotdata		*sdata;
  unsigned long long	now;

  sdata = get_shotdata();
  sdata->was_shooting = sdata->is_shooting;
  if (!click || running)
    sdata->is_shooting = 0;
  else
    {
      now = get_timestamp();
      if (now - sdata->last_ms > SHOT_DELAY)
	{
	  action_shot(sdata);
	  sdata->last_ms = now;
	}
      else
	sdata->is_shooting = 0;
    }
}
