/*
** _raycast.c for wolf3d in /home/arbona/tek1/MUL/wolf3d_autograder
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Jan  4 23:08:43 2017 Thomas ARBONA
** Last update Mon Jan 23 22:05:24 2017 Thomas ARBONA
*/
#include <stdio.h>
#include <SFML/System/Vector2.h>
#include <math.h>
#include "level/level.h"
#include "raycast.h"
#include "util.h"

static void	cmp_rayinter(t_raydata *raydata,
			     t_rayinter *rayinter,
			     t_level *level)
{
  if (raydata->case_id == -1 || raydata->dist > rayinter->dist)
    {
      raydata->dist = rayinter->dist;
      raydata->case_id =
	(0 <= LOWINT(rayinter->inter.x) &&
	 LOWINT(rayinter->inter.x) < level->map.size.x &&
	 0 <= LOWINT(rayinter->inter.y) &&
	 LOWINT(rayinter->inter.y) < level->map.size.y &&
	 map_getf(rayinter->inter.x, rayinter->inter.y)->wall != 0)
	? map_getf(rayinter->inter.x, rayinter->inter.y)->wall : 3;
      raydata->prop = (rayinter->side == SIDE_DOWN ||
		       rayinter->side == SIDE_UP)
	? rayinter->inter.x - trunc(rayinter->inter.x)
	: rayinter->inter.y - trunc(rayinter->inter.y);
      if (raydata->prop < 0.)
	raydata->prop = -raydata->prop;
      raydata->side = rayinter->side;
      raydata->inter.x = rayinter->inter.x;
      raydata->inter.y = rayinter->inter.y;
    }
}

static void	travel_inter(t_raydata *raydata,
			     t_rayinter *rayinter,
			     t_level *level)
{
  while (0 <= LOWINT(rayinter->inter.x) &&
	 LOWINT(rayinter->inter.x) < level->map.size.x &&
	 0 <= LOWINT(rayinter->inter.y) &&
	 LOWINT(rayinter->inter.y) < level->map.size.y &&
	 map_getf(rayinter->inter.x, rayinter->inter.y)->wall == 0)
    {
      rayinter->inter.y += rayinter->step.y;
      rayinter->inter.x += rayinter->step.x;
      rayinter->dist += rayinter->delta;
    }
  cmp_rayinter(raydata, rayinter, level);
}

static void	get_dist_vertical(t_raydata *raydata,
				  sfVector2f *pos,
				  float dir,
				  t_level *level)
{
  t_rayinter	rayinter;

  if (dir == 90 || dir == 270)
    return;
  rayinter.side = (dir > 90 && dir < 270) ? SIDE_DOWN : SIDE_UP;
  rayinter.pos = *pos;
  rayinter.rad = (dir < 90) ? dir :
    (dir < 180) ? 180 - dir :
    (dir < 270) ? dir - 180 :
    360 - dir;
  rayinter.rad = rayinter.rad * M_PI / 180.;
  rayinter.dir = dir;
  rayinter.inter.y = (dir > 90 && dir < 270) ? ceilf(pos->y) : floorf(pos->y);
  rayinter.inter.x = pos->x +
    ((dir > 180)
     ? -(fabsf(pos->y - rayinter.inter.y) * tanf(rayinter.rad))
     : (fabsf(pos->y - rayinter.inter.y) * tanf(rayinter.rad)));
  rayinter.dist = sqrt(pow(rayinter.inter.x - rayinter.pos.x, 2) +
		       pow(rayinter.inter.y - rayinter.pos.y, 2));
  rayinter.delta = sqrt(1 + pow(tanf(rayinter.rad), 2));
  rayinter.inter.y -= (dir < 90 || 270 < dir);
  rayinter.step.x = (dir > 180) ? -tanf(rayinter.rad) : tanf(rayinter.rad);
  rayinter.step.y = (dir > 90 && dir < 270) ? 1 : -1;
  travel_inter(raydata, &rayinter, level);
}

static void	get_dist_horizontal(t_raydata *raydata,
				    sfVector2f *pos,
				    float dir,
				    t_level *level)
{
  t_rayinter	rayinter;

  if (dir == 0 || dir == 180)
    return;
  rayinter.side = (dir < 180) ? SIDE_RIGHT : SIDE_LEFT;
  rayinter.pos = *pos;
  rayinter.rad = (dir < 90) ? 90 - dir :
    (dir < 180) ? dir - 90 :
    (dir < 270) ? 270 - dir
    : dir - 270;
  rayinter.rad = rayinter.rad * M_PI / 180.;
  rayinter.dir = dir;
  rayinter.inter.x = (dir > 180) ? floorf(pos->x) : ceilf(pos->x);
  rayinter.inter.y = pos->y +
    ((dir > 90 && dir < 270)
     ? (fabsf(pos->x - rayinter.inter.x) * tanf(rayinter.rad))
     : -(fabsf(pos->x - rayinter.inter.x) * tanf(rayinter.rad)));
  rayinter.dist = sqrt(pow(rayinter.inter.x - rayinter.pos.x, 2) +
		       pow(rayinter.inter.y - rayinter.pos.y, 2));
  rayinter.delta = sqrt(1 + pow(tanf(rayinter.rad), 2));
  rayinter.inter.x -= (dir > 180);
  rayinter.step.x = (dir > 180) ? -1 : 1;
  rayinter.step.y = (dir > 90 && dir < 270)
    ? tanf(rayinter.rad) : -tanf(rayinter.rad);
  travel_inter(raydata, &rayinter, level);
}

void	raycast(t_raydata *raydata, sfVector2f pos,
		float dir, t_level *level)
{
  dir += 90;
  while (dir >= 360)
    dir -= 360;
  while (dir < 0)
    dir += 360;
  raydata->case_id = -1;
  get_dist_horizontal(raydata, &pos, dir, level);
  get_dist_vertical(raydata, &pos, dir, level);
}
