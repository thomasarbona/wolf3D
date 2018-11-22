/*
** texture.h for view in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Fri Jan  6 21:46:11 2017 Thomas ARBONA
** Last update Sun Jan 15 19:49:46 2017 Thomas ARBONA
*/

#ifndef VIEW_TEXTURE_H_
# define VIEW_TEXTURE_H_

# include <SFML/Graphics.h>

# define TEXT_STATE_NB	20

typedef struct	s_texture
{
  int		id;
  sfImage	*img;
  sfVector2u	size;
}		t_texture;

typedef struct	s_textgrp
{
  int		id;
  t_texture	*texture[TEXT_STATE_NB];
}		t_textgrp;

typedef struct		s_textlist
{
  t_textgrp		*grp;
  struct s_textlist	*next;
}			t_textlist;

# define TEXTURE_FLD		"./resources/texture/"
# define TEXTURE_FMT		"png"

t_textgrp	***texture_getall();
t_texture	*texture_get(int, int);
void		texture_load();
sfColor		texture_getclr(int, int, sfVector2i*);
sfColor		texture_getclr_prop(int, int, sfVector2f*);
void		tlist_add(t_textlist**, char*);
t_textgrp	*tlist_getid(t_textlist*, int);
t_textlist	*tlist_create(t_textgrp*);

#endif /* !VIEW_TEXTURE_H_ */
