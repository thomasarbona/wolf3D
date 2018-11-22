/*
** main.c for wolf3d in /home/arbona/tek1/MUL/wolf3d
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Jan  5 11:26:29 2017 Thomas ARBONA
** Last update Sat Jan 21 18:43:37 2017 Thomas ARBONA
*/
#include "view/view.h"
#include "game/frame/frame.h"
#include "view/texture/texture.h"
#include "sound/sound.h"

int		main()
{
  texture_load();
  sound_load();
  frame_set(FRAME_MENU);
  view_render();
  return (0);
}
