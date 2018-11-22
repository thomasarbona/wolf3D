/*
** setter.c for sound in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Jan 11 11:20:42 2017 Thomas ARBONA
** Last update Wed Jan 11 14:34:02 2017 Thomas ARBONA
*/
# include <stdlib.h>
# include "sound/sound.h"
# include "my.h"

void		sblist_add(t_sbufflist **sblist, char *name)
{
  t_sbufflist	*new;
  t_sbufflist	*curr;

  if (!(new = malloc(sizeof(t_sbufflist))))
    return;
  new->next = NULL;
  new->id = my_getnbr((my_str_to_wordtab(name, "-"))[0]);
  new->buff =
    sfSoundBuffer_createFromFile(my_asprintf("%s/%s", SOUND_FLD, name));
  if (*sblist == NULL)
    {
      *sblist = new;
      return;
    }
  curr = *sblist;
  while (curr->next != NULL)
    curr = curr->next;
  curr->next = new;
}
