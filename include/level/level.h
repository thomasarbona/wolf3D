/*
** level.h for level in /home/arbona/tek1/MUL/wolf3d
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Jan  5 12:17:58 2017 Thomas ARBONA
** Last update Thu Jan 12 14:28:37 2017 Thomas ARBONA
*/
#ifndef LEVEL_H_
# define LEVEL_H_

# include <SFML/System/Vector2.h>
# include "player/player.h"
# include "level/map.h"

typedef struct	s_level
{
  t_map		map;
  t_player	player;
}		t_level;

# include "level/setter.h"
# include "level/load.h"

t_level	*level_get();

#endif /* !LEVEL_H_ */
