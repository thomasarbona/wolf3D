/*
** video.h for view in /home/arbona/tek1/MUL/wolf3d
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Jan  5 21:23:41 2017 Thomas ARBONA
** Last update Tue Jan 17 23:51:39 2017 Thomas ARBONA
*/

#ifndef VIEW_VIDEO_H_
#define VIEW_VIDEO_H_

# include <SFML/Graphics.h>
# include "view/framebuffer.h"

typedef struct		s_video
{
  sfVideoMode		mode;
  sfRenderWindow	*window;
  sfTexture		*texture;
  sfTexture		*dist_text;
  sfTexture		*side_text;
  sfSprite		*sprite;
  sfEvent		event;
  sfShader		*shader;
  sfRenderStates	state;
  sfShader		*obj_shader;
  sfRenderStates	obj_state;
  sfFont		*font;
  t_my_framebuffer	fbuff;
  t_my_framebuffer	dist_fbuff;
  t_my_framebuffer	side_fbuff;
}			t_video;

#endif /* !VIEW_VIDEO_H_ */
