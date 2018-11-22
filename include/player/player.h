/*
** player.h for player in /home/arbona/tek1/MUL/wolf3d
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Jan  5 12:20:06 2017 Thomas ARBONA
** Last update Wed Jan 18 11:28:42 2017 Thomas ARBONA
*/

#ifndef PLAYER_H_
# define PLAYER_H_

# include <SFML/System/Vector2.h>

# define PLAYER_LIFE		100
# define PLAYER_MUNITION	20

typedef struct	s_player
{
  sfVector2f	pos;
  float		dir;
  int		mob_target;
  int		munition;
  float		life;
}		t_player;

#endif /* !PLAYER_H_ */
