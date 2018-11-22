/*
** action.h for game in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sat Jan  7 18:20:37 2017 Thomas ARBONA
** Last update Wed Jan 18 16:13:46 2017 Thomas ARBONA
*/

#ifndef GAME_ACTION_H_
# define GAME_ACTION_H_

# include <SFML/System/Vector2.h>
# include "game/sprite/sprite.h"

# define MUN_DROP	15

void	action_move(float, float);
void	action_turn(sfVector2i*);
void	action_drop(t_sprite*);

#endif /* !GAME_ACTION_H_ */
