/*
** time.c for game in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Jan 10 17:42:10 2017 Thomas ARBONA
** Last update Sat Jan 14 20:20:28 2017 Thomas ARBONA
*/
#include <sys/time.h>
#include <math.h>
#include <unistd.h>
#include "game/time.h"

unsigned long long	get_timestamp()
{
  struct timeval	tv;

  gettimeofday(&tv, NULL);
  return ((unsigned long long)(tv.tv_sec) * 1000 +
	  (unsigned long long)(tv.tv_usec) / 1000);
}

t_frametime		*frametime_get()
{
  static t_frametime	ftime;
  static int		call = 0;
  unsigned long long	now;

  now = get_timestamp();
  if (call == 0)
    {
      ftime.started = now;
      ftime.start_dur = 0;
      ftime.last = now;
      ftime.current = now;
      call = 1;
    }
  return (&ftime);
}

void			frametime_update()
{
  unsigned long long	now;
  t_frametime		*ftime;

  now = get_timestamp();
  ftime = frametime_get();
  ftime->last = ftime->current;
  ftime->current = now;
  ftime->start_dur = now - ftime->started;
}

unsigned long long 	frametime_getduration()
{
  t_frametime		*ftime;

  ftime = frametime_get();
  return (ftime->current - ftime->last);
}

void			frametime_control()
{
  unsigned long long	dur;

  dur = frametime_getduration();
  if (dur < FRAME_DUR)
    usleep((FRAME_DUR - dur) * 1000);
}
