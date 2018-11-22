/*
** view.h for view in /home/arbona/tek1/MUL/wolf3d
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Jan  5 12:01:50 2017 Thomas ARBONA
** Last update Sat Jan 21 23:29:40 2017 Thomas ARBONA
*/

#ifndef VIEW_H_
# define VIEW_H_

# include <SFML/Graphics/Color.h>
# include "game/frame/frame.h"
# include "view/entity/video.h"
# include "view/framebuffer.h"

# define VIEW_NAME	"wolf3d"
# define VIEW_WIDTH	1280
# define VIEW_HEIGHT	720
# define VIEW_BPP	32
# define VIEW_RATIO	1.

void	view_render();
t_video	*view_getvideo();
sfColor	*color_filter(sfColor*, sfColor*);

#endif /* !VIEW_H_ */
