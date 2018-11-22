/*
** map.c for level in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Jan 12 13:23:56 2017 Thomas ARBONA
** Last update Thu Jan 12 17:48:35 2017 Thomas ARBONA
*/
#include "level/level.h"
#include "util.h"
#include "my.h"

t_block		*map_newblock(char **data)
{
  t_block	*new;

  if (!(new = malloc(sizeof(t_block))))
    return (NULL);
  if (data == NULL)
    {
      new->wall = 0;
      new->floor = 1;
      new->ceil = 1;
      new->breakable = 0;
      new->state = 0;
      return (new);
    }
  new->wall = my_getnbr(data[0]);
  new->floor = my_getnbr(data[1]);
  new->ceil = my_getnbr(data[2]);
  new->breakable = my_getnbr(data[3]);
  new->state = 0;
  return (new);
}

t_block		*map_get(int x, int y)
{
  t_level	*level;

  level = level_get();
  if (!is_inmap(x, y))
    return (NULL);
  return (level->map.blocks[y][x]);
}

t_block		*map_getf(float x, float y)
{
  t_level	*level;

  level = level_get();
  if (!is_inmap(LOWINT(x), LOWINT(y)))
    return (NULL);
  return (level->map.blocks[LOWINT(y)][LOWINT(x)]);
}

int	is_inmap(int x, int y)
{
  t_level	*level;

  level = level_get();
  return (0 <= x && x < level->map.size.x &&
	  0 <= y && y < level->map.size.y);
}

int	is_strict_inmap(int x, int y)
{
  t_level	*level;

  level = level_get();
  return (0 < x && x < level->map.size.x &&
	  0 < y && y < level->map.size.y);
}
