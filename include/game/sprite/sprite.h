/*
** sprite.h for sprite in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Fri Jan 13 18:26:55 2017 Thomas ARBONA
** Last update Wed Jan 18 16:27:15 2017 Thomas ARBONA
*/

#ifndef GAME_SPRITE_H_
# define GAME_SPRITE_H_

# include <SFML/System/Vector2.h>

typedef struct	s_sprite
{
  int		id;
  int		img;
  sfVector2f	pos;
  float		dist;
  int		type;
  float		state;
  float		dir;
  int		follow;
  int		shoot;
}		t_sprite;

typedef struct		s_sprites
{
  t_sprite		*sprite;
  struct s_sprites	*next;
}			t_sprites;

# define SPRT_MOB	0
# define SPRT_MUN	1

# define DROP_DIST	1

void		sprite_sort();
t_sprites	*sprite_destroy();
t_sprite	*sprite_create(int);
t_sprites	**sprite_getall();
t_sprite	*sprite_getid(int);
void		sprite_handle();

#endif /* !GAME_SPRITE_H_ */
