/*
** texture.c for sound in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Jan 11 11:06:40 2017 Thomas ARBONA
** Last update Mon Jan 16 21:48:00 2017 Thomas ARBONA
*/

#include <SFML/Audio.h>
#include <stddef.h>
#include <dirent.h>
#include <stdlib.h>
#include "sound/sound.h"
#include "my.h"

sfSound			*sound_getthread()
{
  static sfSound	*sound;
  static int		call = 0;

  if (call == 0)
    {
      sound = sfSound_create();
      call = 1;
    }
  return (sound);
}

sfSoundBuffer		***sound_getlist()
{
  static sfSoundBuffer	**soundlist;

  return (&soundlist);
}

static void		sound_makelist(t_sbufflist *sblist)
{
  int			sound_nb;
  t_sbufflist		*curr;
  sfSoundBuffer		***sounds;

  sounds = sound_getlist();
  curr = sblist;
  sound_nb = 0;
  while (curr != NULL)
    {
      sound_nb += 1;
      curr = curr->next;
    }
  if (!(*sounds = malloc(sizeof(sfSoundBuffer*) * (sound_nb + 1))))
    return;
  (*sounds)[sound_nb] = NULL;
  curr = sblist;
  while (curr != NULL)
    {
      (*sounds)[curr->id] = curr->buff;
      curr = curr->next;
    }
}

void			sound_load()
{
  struct dirent		*entry;
  DIR			*dir;
  t_sbufflist		*sblist;

  sblist = NULL;
  if ((dir = opendir(SOUND_FLD)) == NULL)
    return;
  while ((entry = readdir(dir)) != NULL)
    {
      if (entry->d_type == DT_REG)
	sblist_add(&sblist, entry->d_name);
    }
  closedir(dir);
  sound_makelist(sblist);
}

void		sound_play(int id)
{
  sfSoundBuffer	*sb;
  sfSound	*sound;

  sb = sound_get(id);
  sound = sfSound_create();
  sfSound_setBuffer(sound, sb);
  sfSound_play(sound);
}
