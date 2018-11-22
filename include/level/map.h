/*
** map.h for  in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Jan 12 13:41:26 2017 Thomas ARBONA
** Last update Thu Jan 12 16:13:43 2017 Thomas ARBONA
*/

#ifndef LEVEL_MAP_H_
# define LEVEL_MAP_H_

# include "level/entity/map.h"

t_block	*map_newblock(char **);
t_block	*map_get(int, int);
t_block	*map_getf(float, float);
int	is_inmap(int, int);
int	is_strict_inmap(int, int);

#endif /* !LEVEL_MAP_H_ */
