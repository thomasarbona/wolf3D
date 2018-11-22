/*
** frame.h for frame in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Sun Jan  8 19:24:55 2017 Thomas ARBONA
** Last update Sat Jan 21 18:51:24 2017 Thomas ARBONA
*/

#ifndef GAME_FRAME_H_
# define GAME_FRAME_H_

# include "view/entity/video.h"

typedef struct	s_frame
{
  int		id;
  int		update_call;
  void		(*update)(int, t_video*);
}		t_frame;

void	frame_set(int);
void	frame_update(t_video*);

# define FRAME_MENU	0
# define FRAME_GAME	1
# define FRAME_PAUSE	2
# define FRAME_OVER	3

#endif /* !GAME_FRAME_H_ */
