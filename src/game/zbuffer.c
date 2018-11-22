/*
** zbuffer.c for game in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sat Jan 14 22:30:21 2017 Thomas ARBONA
** Last update Tue Jan 17 23:32:42 2017 Thomas ARBONA
*/
#include <stdlib.h>

static float	**zbuffer_get()
{
  static float	*zbuffer;
  static int	call = 0;

  if (call == 0)
    {
      zbuffer = NULL;
      call = 1;
    }
  return (&zbuffer);
}

void	zbuffer_set(int width)
{
  float	**zbuffer;

  zbuffer = zbuffer_get();
  if (!((*zbuffer) = malloc(sizeof(int) * width)))
    return;
}

void	zbuffer_setdist(int x, float dist)
{
  float	**zbuffer;

  zbuffer = zbuffer_get();
  (*zbuffer)[x - 1] = dist;
}

float	zbuffer_getdist(int x)
{
  return ((*zbuffer_get())[x - 1]);
}
