/*
** raycast.h for wolf3d in /home/arbona/tek1/MUL/wolf3d
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Jan  4 16:29:38 2017 Thomas ARBONA
** Last update Thu Jan 12 22:09:29 2017 Thomas ARBONA
*/

#ifndef RAYCAST_H_
# define RAYCAST_H_

# include <math.h>
# include <SFML/System/Vector2.h>
# include "level/level.h"

typedef struct	s_raydata
{
  float		dist;
  int		case_id;
  float		prop;
  int		side;
  sfVector2f	inter;
}		t_raydata;

typedef struct	s_rayinter
{
  int		side;
  sfVector2f	inter;
  sfVector2f	pos;
  float		dist;
  float		delta;
  float		dir;
  float		rad;
  sfVector2f	step;
}		t_rayinter;

# define SIDE_UP	0
# define SIDE_DOWN	1
# define SIDE_RIGHT	2
# define SIDE_LEFT	3
# define SIDE_FLOOR	4
# define SIDE_CEIL	5

void	raycast(t_raydata *, sfVector2f, float, t_level*);

#endif /* !RAYCAST_H_ */
