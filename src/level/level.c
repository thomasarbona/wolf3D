/*
** level.c for level in /home/arbona/tek1/MUL/wolf3d
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Jan  5 19:10:22 2017 Thomas ARBONA
** Last update Thu Jan  5 19:11:05 2017 Thomas ARBONA
*/
#include "level/level.h"

t_level			*level_get()
{
  static t_level	level;

  return (&level);
}
