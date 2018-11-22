/*
** sprite.c for sprite in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Fri Jan 13 18:24:34 2017 Thomas ARBONA
<<<<<<< HEAD
** Last update Wed Jan 18 16:04:47 2017 Thomas ARBONA
=======
** Last update Mon Jan 23 21:08:07 2017 Thomas ARBONA
>>>>>>> df50b09c9b7da66dd8d31614ca79951e5d63f30c
*/
#include <unistd.h>
#include <stdlib.h>
#include "game/sprite/sprite.h"

t_sprites		**sprite_getall()
{
  static t_sprites	*sprites;
  static int		call = 0;

  if (call == 0)
    {
      sprites = NULL;
      call = 1;
    }
  return (&sprites);
}

t_sprite	*sprite_create(int type)
{
  static int	id = -1;
  t_sprites	**list;
  t_sprites	*curr;
  t_sprites	*sprt_ctnr;

  id += 1;
  list = sprite_getall();
  if (!(sprt_ctnr = malloc(sizeof(t_sprites))) ||
      !(sprt_ctnr->sprite = malloc(sizeof(t_sprite))))
    return (NULL);
  sprt_ctnr->next = NULL;
  sprt_ctnr->sprite->type = type;
  sprt_ctnr->sprite->state = 0;
  sprt_ctnr->sprite->id = id;
  if (*list == NULL)
    return ((*list = sprt_ctnr)->sprite);
  curr = *list;
  while (curr->next != NULL)
    curr = curr->next;
  curr->next = sprt_ctnr;
  return (sprt_ctnr->sprite);
}

t_sprites	*sprite_destroy(int id)
{
  t_sprites	**list;
  t_sprites	*curr;
  t_sprites	*prev;
  t_sprites	*tmp;

  list = sprite_getall();
  if ((*list)->sprite->id == id)
    {
      tmp = *list;
      *list = (*list)->next;
      free(tmp);
      return (*list);
    }
  curr = *list;
  while (curr != NULL && curr->sprite->id != id)
    {
      prev = curr;
      curr = curr->next;
    }
  if (curr->sprite->id == id)
    {
      tmp = curr;
      prev->next = curr->next;
      free(tmp);
    }
  return (prev->next);
}

void		sprite_sort()
{
  t_sprites	*curs1;
  t_sprites	*curs2;
  t_sprites	**list;
  t_sprite	*tmp;

  list = sprite_getall();
  if ((*list)->next == NULL)
    return;
  curs1 = *list;
  curs2 = (*list)->next;
  while (curs1->next != NULL)
    {
      curs2 = curs1->next;
      while (curs2 != NULL)
	{
	  if (curs1->sprite->dist < curs2->sprite->dist)
	    {
	      tmp = curs1->sprite;
	      curs1->sprite = curs2->sprite;
	      curs2->sprite = tmp;
	    }
	  curs2 = curs2->next;
	}
      curs1 = curs1->next;
    }
}

t_sprite	*sprite_getid(int id)
{
  t_sprites	**list;
  t_sprites	*curr;

  list = sprite_getall();
  curr = *list;
  while (curr != NULL)
    {
      if (curr->sprite->id == id)
	return (curr->sprite);
      curr = curr->next;
    }
  return (NULL);
}
