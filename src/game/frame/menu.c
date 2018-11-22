/*
** menu.c for frame in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sun Jan  8 19:53:31 2017 Thomas ARBONA
** Last update Sat Jan 21 19:27:03 2017 Thomas ARBONA
*/
#include <stdlib.h>
#include "game/frame/frame.h"
#include "game/event/event.h"
#include "view/draw/draw.h"
#include "level/level.h"

static void	menu_handle_event(int *selected)
{
  t_eventlist	*eventlist;

  eventlist = event_getlist();
  if (eventlist->key_up)
    *selected = 0;
  if (eventlist->key_down)
    *selected = 1;
  if (eventlist->key_enter && *selected == 0)
    {
      level_load("./resources/maps/default", level_get());
      frame_set(FRAME_GAME);
    }
  if (eventlist->key_enter && *selected == 1)
    exit(EXIT_SUCCESS);
}

void		frame_menu_update(int call, t_video *video)
{
  static int	selected;
  sfVector2f	pos;

  (void)video;
  if (call == 0)
    selected = -1;
  pos.x = 80;
  pos.y = 100;
  draw_text("WOLF3D DEMO", pos, 80);
  pos.y = video->fbuff.height / 2 - 60;
  draw_text_clr((selected == 0) ? " Play" : "Play", pos, 45, (sfColor){255, 255, 255, 160
	+ ((selected == 0) * 50)});
  pos.y += 60;
  draw_text_clr((selected == 1) ? " Quit" : "Quit", pos, 45, (sfColor){255, 255, 255, 160
	+ ((selected == 1) * 50)});
  pos.y = video->fbuff.height - 120;
  draw_text_clr("made by thomas arbona", pos, 20, (sfColor){255, 255, 255, 80});
  menu_handle_event(&selected);
}
