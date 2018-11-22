/*
** time.h for time in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Jan 10 17:47:18 2017 Thomas ARBONA
** Last update Tue Jan 10 19:09:21 2017 Thomas ARBONA
*/

#ifndef GAME_TIME_H_
# define GAME_TIME_H_

typedef struct		s_frametime
{
  unsigned long long	started;
  unsigned long long	start_dur;
  unsigned long long	last;
  unsigned long long	current;
}			t_frametime;

# define FRAME_DUR	16.

t_frametime		*frametime_get();
void			frametime_update();
unsigned long long	frametime_getduration();
void			frametime_control();
unsigned long long	get_timestamp();

#endif /* !GAME_TIME_H_ */
