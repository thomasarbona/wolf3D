/*
** list.c for texture in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Jan 10 10:38:24 2017 Thomas ARBONA
** Last update Sun Jan 15 22:40:22 2017 Thomas ARBONA
*/
#include <unistd.h>
#include <stdlib.h>
#include "view/texture/texture.h"
#include "my.h"

t_texture	*texture_create();

void		tlist_add(t_textlist **tlist, char *name)
{
  t_textgrp	*textgrp;
  t_textlist	*curr;
  char		**data;
  int		id;

  curr = *tlist;
  data = my_str_to_wordtab(name, "-.");
  id = my_getnbr(data[0]);
  if (!(textgrp = tlist_getid(*tlist, id)))
    {
      if (!(textgrp = malloc(sizeof(t_textgrp))))
	return;
      while (curr && curr->next != NULL)
	curr = curr->next;
      if (curr == NULL)
	*tlist = tlist_create(textgrp);
      else
	curr->next = tlist_create(textgrp);
    }
  name = my_asprintf("./%s/%s", TEXTURE_FLD, name);
  textgrp->id = id;
  id = my_getnbr(data[1]);
  textgrp->texture[id] = texture_create();
  textgrp->texture[id]->img = sfImage_createFromFile(name);
  textgrp->texture[id]->size = sfImage_getSize(textgrp->texture[id]->img);
}

t_textgrp	*tlist_getid(t_textlist *tlist, int id)
{
  t_textlist	*curr;

  curr = tlist;
  while (curr != NULL)
    {
      if (curr->grp->id == id)
	return (curr->grp);
      curr = curr->next;
    }
  return (NULL);
}

t_texture	*texture_create()
{
  t_texture	*texture;

  if (!(texture = malloc(sizeof(t_texture))))
    return (NULL);
  return (texture);
}

t_textlist	*tlist_create(t_textgrp *textgrp)
{
  t_textlist	*tlist;

  if (!(tlist = malloc(sizeof(t_textlist))))
    return (NULL);
  tlist->grp = textgrp;
  tlist->next = NULL;
  return (tlist);
}
