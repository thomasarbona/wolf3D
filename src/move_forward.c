/*
** move_forward.c for wolf3d in /home/arbona/tek1/MUL/bswolf3d
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Fri Dec 16 17:27:21 2016 Thomas ARBONA
** Last update Sun Jan 15 22:08:32 2017 Thomas ARBONA
*/
#include <stdlib.h>
#include <math.h>
#include <SFML/System/Vector2.h>

static void	polar2cartesian(sfVector2f *pos,
				float direction,
				float distance)
{
  direction = direction * M_PI / 180;
  pos->x = distance * cos(direction);
  pos->y = distance * sin(direction);
}

sfVector2f	move_forward(sfVector2f pos,
			     float direction,
			     float distance)
{
  sfVector2f	move;

  polar2cartesian(&move, direction, distance);
  pos.x += move.x;
  pos.y += move.y;
  return (pos);
}
