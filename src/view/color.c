/*
** color.c for view in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Mon Jan  9 17:22:46 2017 Thomas ARBONA
** Last update Tue Jan 10 17:09:16 2017 Thomas ARBONA
*/
#include <SFML/Graphics.h>

sfColor	*color_filter(sfColor *color, sfColor *filter)
{
  float	rate;

  rate = filter->a / 255.;
  color->r = color->r * (1 - rate) + filter->r * rate;
  color->g = color->g * (1 - rate) + filter->g * rate;
  color->b = color->b * (1 - rate) + filter->b * rate;
  return (color);
}
