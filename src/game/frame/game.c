/*
** game.h for game in /home/arbona/tek1/MUL/wolf3d
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Jan  5 18:47:08 2017 Thomas ARBONA
** Last update Sat Jan 21 23:15:30 2017 Thomas ARBONA
*/
#include "game/vision.h"
#include "game/time.h"
#include "view/framebuffer.h"
#include "game/frame/frame.h"
#include "game/enemy/enemy.h"
#include "game/event/event.h"
#include "game/action/move.h"
#include "game/action/action.h"
#include "game/action/shot.h"
#include "game/data.h"
#include "sound/sound.h"
#include "view/view.h"
#include "view/draw/draw.h"
#include "level/level.h"
#include "util.h"

static void	handle_mouse_move(t_eventlist *eventlist, t_video *video)
{
  sfVector2i    mouse_pos;
  sfVector2i    mouse_delta;

  mouse_pos = sfMouse_getPosition((sfWindow*)video->window);
  if (mouse_pos.x == eventlist->mouse_pos.x &&
      mouse_pos.y == eventlist->mouse_pos.y)
    return;
  mouse_delta.x = eventlist->mouse_pos.x - mouse_pos.x;
  mouse_delta.y = eventlist->mouse_pos.y - mouse_pos.y;
  mouse_pos.x = video->mode.width / 2;
  mouse_pos.y = video->mode.height / 2;
  sfMouse_setPosition(mouse_pos, (sfWindow*)video->window);
  eventlist->mouse_pos = mouse_pos;
  action_turn(&mouse_delta);
}

static void	game_handle_event()
{
  t_eventlist   *eventlist;
  t_video       *video;

  eventlist = event_getlist();
  video = view_getvideo();
  handle_mouse_move(eventlist, video);
  action_handle_shot(eventlist->mouse_lclk, eventlist->dkey_z);
  if (eventlist->key_esc)
    frame_set(FRAME_PAUSE);
  if (eventlist->key_z || eventlist->dkey_z)
    action_move(0, (eventlist->key_z) ? WALK_DIST : RUN_DIST);
  if (eventlist->key_s)
    action_move(180, LATERAL_DIST);
  if (eventlist->key_d)
    action_move(-90, LATERAL_DIST);
  if (eventlist->key_q)
    action_move(90, LATERAL_DIST);
}

static void	handle_sounds()
{

}

void		frame_game_update(int call, t_video *video)
{
  t_level	*level;

  level = level_get();
  (void)call;
  frametime_update();
  game_handle_event();
  framebuffer_clearall();
  game_updatevision(video);
  game_displaydata();
  enemy_handle();
  handle_sounds();
  frametime_control();
  if (LOWINT(level->player.pos.x) == 10 &&
      LOWINT(level->player.pos.y) == 2)
    {
      draw_text("Press enter to open the door.",
		(sfVector2f){video->fbuff.width / 2 - 180,
		    video->fbuff.height/2 - 150}, 30);
      if (event_getlist()->key_enter)
	frame_set(FRAME_OVER);
    }
}
