/*
** enemy.h for game in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Mon Jan 16 18:29:14 2017 Thomas ARBONA
** Last update Wed Jan 18 11:34:19 2017 Thomas ARBONA
*/

#ifndef GAME_ENEMY_H_
# define GAME_ENEMY_H_

# define MOB_MOVE_SPD	.35
# define MOB_DIE_SPD	.7
# define MOB_MOVE_DIST	.05
# define MOB_MOVE_CALIB	.4
# define MOB_BITE	2

# include "game/sprite/sprite.h"

void	enemy_handle();
void	enemy_move(t_sprite*);

#endif /* !GAME_ENEMY_H_ */
