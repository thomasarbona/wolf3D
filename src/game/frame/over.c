/*
** menu.c for frame in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sun Jan  8 19:53:31 2017 Thomas ARBONA
** Last update Sat Jan 21 19:33:11 2017 Thomas ARBONA
*/
#include <stdlib.h>
#include "game/frame/frame.h"
#include "game/event/event.h"
#include "view/draw/draw.h"
#include "level/level.h"

static void	over_handle_event()
{
  t_eventlist	*eventlist;

  eventlist = event_getlist();
  if (eventlist->key_enter)
    frame_set(FRAME_MENU);
}

void		frame_over_update(int call, t_video *video)
{
  t_level	*level;
  sfVector2f	pos;

  (void)video;
  (void)call;
  level = level_get();
  pos.x = 80;
  pos.y = 100;
  draw_text((level->player.life > 0) ? "YOU SURVIVED !"
	    : "YOU ARE DEAD..", pos, 80);
  pos.y = video->fbuff.height / 2 - 60;
  draw_text_clr("Continue",
		pos, 45, (sfColor){255, 255, 255, 210});
  over_handle_event();
}
