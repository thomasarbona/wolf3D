/*
** my_draw_line.c for wireframe in /home/arbona/tek1/MUL/wireframe/src
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sat Nov 26 00:20:28 2016 Thomas ARBONA
** Last update Sun Jan 15 22:37:15 2017 Thomas ARBONA
*/
#include <math.h>
#include <stdio.h>
#include "my_put_pixel.h"
#include "util.h"

static void	init_vector(sfVector2i *vector,
			    sfVector2i *from,
			    sfVector2i *to)
{
  vector->x = ABS(to->x - from->x);
  vector->y = ABS(to->y - from->y);
}

void		my_draw_line(t_my_framebuffer* fbuff,
			     sfVector2i from,
			     sfVector2i to,
			     sfColor color)
{
  sfVector2i	vector;
  sfVector2i	step;
  int		err;
  int		err2;

  init_vector(&vector, &from, &to);
  step.x = (from.x < to.x) ? 1 : -1;
  step.y = (from.y < to.y) ? 1 : -1;
  err = ((vector.x > vector.y) ? vector.x : -vector.y) / 2;
  while (from.x != to.x || from.y != to.y)
    {
      my_put_pixel(fbuff, from.x, from.y, color);
      err2 = err;
      if (err2 < vector.y && from.y != to.y)
	{
	  err += vector.x;
	  from.y += step.y;
	}
      if (err2 > -vector.x && from.x != to.x)
	{
	  err -= vector.y;
	  from.x += step.x;
	}
    }
  my_put_pixel(fbuff, from.x, from.y, color);
}
