/*
** vision.h for game in /home/arbona/tek1/MUL/wolf3d
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Jan  5 18:54:23 2017 Thomas ARBONA
** Last update Sat Jan 14 19:00:26 2017 Thomas ARBONA
*/
#ifndef GAME_VISION_H_
# define GAME_VISION_H_

# include <SFML/Graphics.h>
# include "view/view.h"

# define VISION_FOV	90.
# define LIGHT_DIST	10.
# define LIGHT_COLOR	(sfColor){226, 88, 34, 255}

void	game_updatevision(t_video*);
float	correct_fisheye(float, float, float);
sfColor	apply_light(sfColor, float);

#endif /* !GAME_VISION_H_ */
