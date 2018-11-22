/*
** frame.c for frame in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sun Jan  8 19:23:15 2017 Thomas ARBONA
** Last update Sat Jan 21 19:05:08 2017 Thomas ARBONA
*/
#include "game/frame/frame.h"
#include "game/frame/game.h"
#include "game/frame/menu.h"
#include "game/frame/over.h"
#include "game/frame/pause.h"
#include "game/event/event.h"

t_frame			*frame_get()
{
  static t_frame	frame;
  static int		call = 0;

  if (call == 0)
    {
      frame.update = NULL;
      call = 1;
    }
  return (&frame);
}

void		frame_set(int frame_id)
{
  t_frame	*frame;
  int		invalid_id;

  invalid_id = 0;
  frame = frame_get();
  if (frame_id == FRAME_MENU)
    frame->update = &frame_menu_update;
  else if (frame_id == FRAME_GAME)
    frame->update = &frame_game_update;
  else if (frame_id == FRAME_PAUSE)
    frame->update = &frame_pause_update;
  else if (frame_id == FRAME_OVER)
    frame->update = &frame_over_update;
  else
    invalid_id = 1;
  if (!invalid_id)
    {
      event_resetlist(event_getlist());
      frame->id = frame_id;
      frame->update_call = 0;
    }
}

void		frame_update(t_video *video)
{
  t_frame	*frame;

  frame = frame_get();
  if (!frame->update)
    return;
  frame->update(frame->update_call, video);
  if (frame->update_call == 0)
    frame->update_call = 1;
}
