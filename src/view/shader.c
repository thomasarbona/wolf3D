/*
** shader.c for view in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Jan 11 17:35:19 2017 Thomas ARBONA
** Last update Mon Jan 16 03:29:02 2017 Thomas ARBONA
*/
#include <SFML/Graphics.h>
#include "raycast.h"
#include "view/view.h"
#include "my_put_pixel.h"

void		set_shaderbuff(int x, int y,
			       float dist,
			       int side)
{
  sfColor	c_data;
  t_video	*video;
  float		rate;

  video = view_getvideo();
  rate = ((dist > 10) ? 10. : dist) / 10. * 255;
  c_data.r = rate;
  c_data.g = rate;
  c_data.b = rate;
  c_data.a = rate;
  my_put_pixel(&video->dist_fbuff, x, y, c_data);
  if (side == SIDE_FLOOR)
    my_put_pixel(&video->dist_fbuff, x, video->fbuff.height - y, c_data);
  c_data.r = (side == SIDE_RIGHT) ? 255 :
    (side == SIDE_LEFT) ? 0 : 128;
  c_data.g = (side == SIDE_UP) ? 0 :
    (side == SIDE_DOWN) ? 255 : 128;
  c_data.b = (side == SIDE_FLOOR) ? 255 : 128;
  c_data.a = 128;
  my_put_pixel(&video->side_fbuff, x, y, c_data);
  if (side == SIDE_FLOOR)
    {
      c_data.b = 0;
      my_put_pixel(&video->side_fbuff, x, video->fbuff.height - y, c_data);
    }
}
