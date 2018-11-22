/*
** my_put_pixel.c for wireframe in /home/arbona/tek1/MUL/wireframe/src
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sat Nov 26 00:20:06 2016 Thomas ARBONA
** Last update Thu Jan  5 17:15:13 2017 Thomas ARBONA
*/
#include "view/view.h"
#include "my_put_pixel.h"

void		my_put_pixel(t_my_framebuffer *fbuff, int x, int y, sfColor color)
{
  int		index;

  if ((x < 0 || x >= fbuff->width) ||
      (y < 0 || y >= fbuff->height))
    return;
  index = ((fbuff->width * y + x) * (VIEW_BPP / 8));
  fbuff->pixels[index] = color.r;
  fbuff->pixels[index + 1] = color.g;
  fbuff->pixels[index + 2] = color.b;
  fbuff->pixels[index + 3] = color.a;
}
