/*
** getter.c for texture in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sun Jan  8 22:24:52 2017 Thomas ARBONA
** Last update Wed Jan 11 18:11:10 2017 Thomas ARBONA
*/
#include <SFML/Graphics/Image.h>
#include "view/texture/texture.h"

t_texture       *texture_get(int id, int state)
{
  t_textgrp     ***textgrp;

  textgrp = texture_getall();
  return ((*textgrp)[id]->texture[state]);
}

sfColor         texture_getclr(int id, int state, sfVector2i *pixel)
{
  t_texture     *texture;

  texture = texture_get(id, state);
  return (sfImage_getPixel(texture->img, pixel->x, pixel->y));
}

sfColor         texture_getclr_prop(int id, int state, sfVector2f *prop)
{
  t_texture     *texture;
  sfVector2i    pixel;

  texture = texture_get(id, state);
  pixel.x = (int)(prop->x * texture->size.x) % texture->size.x;
  pixel.y = (int)(prop->y * texture->size.y) % texture->size.y;
  return (sfImage_getPixel(texture->img, pixel.x, pixel.y));
}
