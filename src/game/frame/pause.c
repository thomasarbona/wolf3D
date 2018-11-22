/*
** menu.c for frame in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sun Jan  8 19:53:31 2017 Thomas ARBONA
** Last update Sat Jan 21 18:49:51 2017 Thomas ARBONA
*/
#include <stdlib.h>
#include "game/frame/frame.h"
#include "game/event/event.h"
#include "view/draw/draw.h"
#include "level/level.h"

static void	pause_handle_event(int *selected)
{
  t_eventlist	*eventlist;

  eventlist = event_getlist();
  if (eventlist->key_up)
    *selected = 0;
  if (eventlist->key_down)
    *selected = 1;
  if (eventlist->key_enter && *selected == 0)
    frame_set(FRAME_GAME);
  if (eventlist->key_enter && *selected == 1)
    frame_set(FRAME_MENU);
}

void		frame_pause_update(int call, t_video *video)
{
  static int	selected;
  sfVector2f	pos;

  (void)video;
  if (call == 0)
    selected = -1;
  pos.x = 80;
  pos.y = 100;
  draw_text("PAUSE", pos, 80);
  pos.y = video->fbuff.height / 2 - 60;
  draw_text_clr((selected == 0) ? " Continue" : "Continue",
		pos, 45, (sfColor){255, 255, 255, 160
		    + ((selected == 0) * 50)});
  pos.y += 60;
  draw_text_clr((selected == 1) ? " Go to menu" : "Go to menu",
		pos, 45, (sfColor){255, 255, 255, 160
		    + ((selected == 1) * 50)});
  pause_handle_event(&selected);
}
