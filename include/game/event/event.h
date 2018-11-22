/*
** event.h for game in /home/arbona/tek1/MUL/wolf3d
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Jan  5 21:38:19 2017 Thomas ARBONA
** Last update Sat Jan 21 18:32:40 2017 Thomas ARBONA
*/

#ifndef GAME_EVENT_H_
# define GAME_EVENT_H_

# include <SFML/Graphics.h>

typedef struct		s_eventlist
{
  int			key_esc;
  int			key_up;
  int			key_down;
  int			key_right;
  int			key_left;
  int			key_enter;
  int			key_q;
  int			key_s;
  int			key_d;
  int			key_l;
  int			key_z;
  int			dkey_z;
  unsigned long long	lkey_z;
  sfVector2i		mouse_pos;
  int			mouse_lclk;
}			t_eventlist;

t_eventlist	*event_getlist();
void		event_resetlist(t_eventlist*);
void		event_set(sfEvent*);
void		event_handle();

#endif /* !GAME_EVENT_H_ */
