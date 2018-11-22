/*
** map.h for level in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Jan 12 13:24:56 2017 Thomas ARBONA
** Last update Thu Jan 12 13:46:31 2017 Thomas ARBONA
*/

#ifndef ENTITY_MAP_H_
# define ENTITY_MAP_H_

# include <SFML/System/Vector2.h>

typedef struct	s_block
{
  int		floor;
  int		ceil;
  int		wall;
  int		breakable;
  int		state;
}		t_block;

typedef struct	s_map
{
  sfVector2i	size;
  t_block	***blocks;
}		t_map;

#endif /* !ENTITY_MAP_H_ */
