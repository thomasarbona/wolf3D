/*
** draw.h for view in /home/arbona/tek1/MUL/wolf3d
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Jan  5 21:13:36 2017 Thomas ARBONA
** Last update Sat Jan 21 18:19:49 2017 Thomas ARBONA
*/

#ifndef VIEW_DRAW_H_
# define VIEW_DRAW_H_

# include <SFML/Graphics/Image.h>
# include <SFML/System/Vector2.h>
# include "raycast.h"
# include "view/framebuffer.h"
# include "game/sprite/sprite.h"
# include "view/texture/texture.h"

typedef struct	s_fromto
{
  sfVector2i	from;
  sfVector2i	to;
}		t_fromto;

typedef struct	s_drw_wall
{
  sfVector2i	vector;
  sfVector2i	step;
  sfVector2i	err;
  float		text_y;
  t_texture	*texture;
  int		start;
  t_fromto	fromto;
}		t_drw_wall;

void	draw_wall(int, t_raydata*, t_my_framebuffer*);
void	draw_floor(int, t_raydata*, t_my_framebuffer*);
void	draw_img(sfImage*, sfVector2f*);
void	draw_img_game(sfImage*, sfVector2f*, float);
void	draw_sprite(t_sprites*, sfVector2i*, sfVector2i*);
void	draw_rotate_img_game(sfImage*, sfVector2f*, float, float);
void	draw_text(char*, sfVector2f, int);
void	draw_text_clr(char*, sfVector2f, int, sfColor);

#endif /* !VIEW_DRAW_H_ */
