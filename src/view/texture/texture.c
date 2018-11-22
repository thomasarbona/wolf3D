/*
** texture.c for view in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Fri Jan  6 21:00:35 2017 Thomas ARBONA
** Last update Sun Jan 15 22:39:23 2017 Thomas ARBONA
*/
#include <SFML/Graphics/Image.h>
#include <stddef.h>
#include <dirent.h>
#include <stdlib.h>
#include "view/texture/texture.h"
#include "my.h"

t_textgrp		***texture_getall()
{
  static t_textgrp	**textgrp;

  return (&textgrp);
}

static void		texture_makelist(t_textlist *tlist)
{
  t_textlist		*curr;
  t_textgrp		***textgrp;
  int			grp_nb;

  textgrp = texture_getall();
  curr = tlist;
  grp_nb = 0;
  while (curr != NULL)
    {
      grp_nb += 1;
      curr = curr->next;
    }
  if (!(*textgrp = malloc(sizeof(t_textgrp*) * (grp_nb + 1))))
    return;
  (*textgrp)[grp_nb] = NULL;
  curr = tlist;
  while (curr != NULL)
    {
      (*textgrp)[curr->grp->id] = curr->grp;
      curr = curr->next;
    }
}

void			texture_load()
{
  struct dirent		*entry;
  DIR			*dir;
  t_textlist		*tlist;

  tlist = NULL;
  if ((dir = opendir(TEXTURE_FLD)) == NULL)
    return;
  while ((entry = readdir(dir)) != NULL)
    {
      if (entry->d_type == DT_REG)
	  tlist_add(&tlist, entry->d_name);
    }
  closedir(dir);
  texture_makelist(tlist);
}
