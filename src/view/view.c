/*
** view.c for view in /home/arbona/tek1/MUL/wolf3d
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Jan  5 11:33:44 2017 Thomas ARBONA
** Last update Sun Jan 22 01:40:18 2017 Thomas ARBONA
*/
#include <SFML/Graphics.h>
#include "view/view.h"
#include "view/framebuffer.h"
#include "view/entity/video.h"
#include "game/event/event.h"
#include "game/frame/frame.h"
#include "game/zbuffer.h"

t_video			*view_getvideo()
{
  static t_video	video;

  return (&video);
}

static int	init_video(t_video *vd)
{
  if (!(vd->window =
	sfRenderWindow_create(vd->mode, VIEW_NAME, sfClose, NULL)) ||
      !(vd->texture = sfTexture_create(vd->mode.width, vd->mode.height)) ||
      !(vd->dist_text = sfTexture_create(vd->mode.width, vd->mode.height)) ||
      !(vd->side_text = sfTexture_create(vd->mode.width, vd->mode.height)) ||
      !framebuffer_init(&vd->fbuff, vd->mode.width, vd->mode.height) ||
      !framebuffer_init(&vd->dist_fbuff, vd->mode.width, vd->mode.height) ||
      !framebuffer_init(&vd->side_fbuff, vd->mode.width, vd->mode.height) ||
      !(vd->sprite = sfSprite_create()) ||
      !(vd->font = sfFont_createFromFile("./resources/font/HACKED.ttf")))
    return (0);
  return (1);
}

static void	init_shader(t_video *vd)
{
  vd->shader = sfShader_createFromFile("./shader/basique.vert",
				       "./shader/basique.frag");
  vd->state.shader = vd->shader;
  vd->state.blendMode = sfBlendAlpha;
  vd->state.transform = sfTransform_Identity;
  vd->state.texture = NULL;
  vd->obj_shader = sfShader_createFromFile("./shader/basique.vert",
					   "./shader/obj_basique.frag");
  vd->obj_state.shader = vd->obj_shader;
  vd->obj_state.blendMode = sfBlendAlpha;
  vd->obj_state.transform = sfTransform_Identity;
  vd->obj_state.texture = NULL;
}

void			view_render()
{
  t_video		*vd;

  vd = view_getvideo();
  vd->mode.width = VIEW_WIDTH;
  vd->mode.height = VIEW_HEIGHT;
  vd->mode.bitsPerPixel = VIEW_BPP;
  if (!init_video(vd))
    return;
  init_shader(vd);
  zbuffer_set(vd->fbuff.width);
  sfRenderWindow_setMouseCursorVisible(vd->window, sfFalse);
  sfSprite_setTexture(vd->sprite, vd->texture, sfTrue);
  while (sfRenderWindow_isOpen(vd->window))
    {
      while (sfRenderWindow_pollEvent(vd->window, &vd->event))
	event_set(&vd->event);
      sfRenderWindow_clear(vd->window, sfBlack);
      frame_update(vd);
      sfRenderWindow_display(vd->window);
    }
  sfRenderWindow_destroy(vd->window);
}
