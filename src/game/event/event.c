/*
** event.c for game in /home/arbona/tek1/MUL/wolf3d
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Jan  5 21:19:10 2017 Thomas ARBONA
<<<<<<< HEAD
** Last update Wed Apr  5 15:59:59 2017 Thomas ARBONA
=======
** Last update Mon Jan 23 21:04:53 2017 Thomas ARBONA
>>>>>>> df50b09c9b7da66dd8d31614ca79951e5d63f30c
*/

#include <SFML/Graphics.h>
#include "game/event/event.h"
#include "game/time.h"
#include "view/view.h"
#include <SFML/Window/Export.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Sensor.h>

t_eventlist		*event_getlist()
{
  static t_eventlist	eventlist;
  static int		call = 0;

  if (call == 0)
    {
      event_resetlist(&eventlist);
      call = 1;
    }
  return (&eventlist);
}

void		event_resetlist(t_eventlist *eventlist)
{
  t_video	*video;

  video = view_getvideo();
  eventlist->key_esc = 0;
  eventlist->key_up = 0;
  eventlist->key_down = 0;
  eventlist->key_right = 0;
  eventlist->key_enter = 0;
  eventlist->key_left = 0;
  eventlist->key_z = 0;
  eventlist->dkey_z = 0;
  eventlist->lkey_z = 0;
  eventlist->key_q = 0;
  eventlist->key_s = 0;
  eventlist->key_d = 0;
  eventlist->mouse_pos = sfMouse_getPosition((sfWindow*)video->window);
}

static void		handle_z(t_eventlist *el, int key_pressed)
{
  unsigned long long	now;

  now = get_timestamp();
  if (!key_pressed)
    {
      el->key_z = key_pressed;
      el->dkey_z = key_pressed;
      el->lkey_z = now;
      return;
    }
  if (el->key_z || el->dkey_z)
    return;
  if (now - el->lkey_z < 250)
    {
      el->dkey_z = 1;
      el->key_z = 0;
    }
  else
    {
      el->key_z = 1;
      el->dkey_z = 0;
    }
}

static void	event_setmore(sfEvent *event, t_eventlist *eventlist, int kp)
{
  if (event->type == 8)//sfEvtMouseWheelScrolled)
    eventlist->mouse_lclk = 1;
  if (event->type == 9)
    eventlist->mouse_lclk = 0;
  if (event->key.code == sfKeyZ)
    handle_z(eventlist, kp);
}

void		event_set(sfEvent *event)
{
  t_eventlist	*eventlist;
  int		key_pressed;

  eventlist = event_getlist();
  key_pressed = (event->type == sfEvtKeyPressed);
  event_setmore(event, eventlist, key_pressed);
  if (event->key.code == sfKeyEscape)
    eventlist->key_esc = key_pressed;
  if (event->key.code == sfKeyUp)
    eventlist->key_up = key_pressed;
  if (event->key.code == sfKeyReturn)
    eventlist->key_enter = key_pressed;
  if (event->key.code == sfKeyDown)
    eventlist->key_down = key_pressed;
  if (event->key.code == sfKeyRight)
    eventlist->key_right = key_pressed;
  if (event->key.code == sfKeyLeft)
    eventlist->key_left = key_pressed;
  if (event->key.code == sfKeyQ)
    eventlist->key_q = key_pressed;
  if (event->key.code == sfKeyS)
    eventlist->key_s = key_pressed;
  if (event->key.code == sfKeyD)
    eventlist->key_d = key_pressed;
  if (event->key.code == sfKeyL)
    eventlist->key_l = key_pressed;
}
