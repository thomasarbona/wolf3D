/*
** getter.c for sound in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Jan 11 11:32:21 2017 Thomas ARBONA
** Last update Wed Jan 11 13:29:18 2017 Thomas ARBONA
*/
#include "sound/sound.h"

sfSoundBuffer	*sound_get(int id)
{
  if (id < 0)
    return (NULL);
  return ((*sound_getlist())[id]);
}
