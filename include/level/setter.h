/*
** setter.h for level in /home/arbona/tek1/MUL/wolf3d
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Jan  5 13:51:51 2017 Thomas ARBONA
** Last update Fri Jan 13 19:22:45 2017 Thomas ARBONA
*/

#ifndef LEVEL_SETTER_H_
# define LEVEL_SETTER_H_

# include "level/level.h"

void	level_setmap(int fd, t_level *level);
void	level_setplayer(int fd, t_level *level);
void	level_setsprites(int fd, t_level *level);

#endif /* !LEVEL_SETTER_H_ */
