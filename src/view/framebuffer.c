/*
** framebuffer.c for render in /home/arbona/
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Thu Nov 17 15:54:36 2016 Thomas ARBONA
** Last update Thu Jan 12 18:10:31 2017 Thomas ARBONA
*/
#include <stdlib.h>
#include "view/framebuffer.h"
#include "view/view.h"

void		framebuffer_clear(t_my_framebuffer *fbuff, int value)
{
  sfUint8	*pixel;
  int		index;
  int		limit;

  index = 0;
  limit = fbuff->width * fbuff->height;
  while (index != limit)
    {
      pixel = fbuff->pixels + (index * (VIEW_BPP / 8));
      pixel[0] = value;
      pixel[1] = value;
      pixel[2] = value;
      pixel[3] = value;
      index += 1;
    }
}

void		framebuffer_clearall()
{
  int		pixel;
  t_video	*video;
  int		index;
  int		limit;

  index = 0;
  video = view_getvideo();
  limit = video->fbuff.width * video->fbuff.height;
  while (index != limit)
    {
      pixel = index * (VIEW_BPP / 8);
      (video->fbuff.pixels + pixel)[0] = 255;
      (video->fbuff.pixels + pixel)[1] = 255;
      (video->fbuff.pixels + pixel)[2] = 255;
      (video->fbuff.pixels + pixel)[3] = 0;
      (video->dist_fbuff.pixels + pixel)[0] = 255;
      (video->dist_fbuff.pixels + pixel)[1] = 255;
      (video->dist_fbuff.pixels + pixel)[2] = 255;
      (video->dist_fbuff.pixels + pixel)[3] = 0;
      (video->side_fbuff.pixels + pixel)[0] = 255;
      (video->side_fbuff.pixels + pixel)[1] = 255;
      (video->side_fbuff.pixels + pixel)[2] = 255;
      (video->side_fbuff.pixels + pixel)[3] = 0;
      index += 1;
    }
}

int    framebuffer_init(t_my_framebuffer *fbuff, int width, int height)
{
  if (!(fbuff->pixels = malloc(sizeof(int) * (width * height))))
    return (0);
  fbuff->width = width;
  fbuff->height = height;
  framebuffer_clear(fbuff, 0);
  return (1);
}
