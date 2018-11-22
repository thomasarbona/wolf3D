/*
** raycasting.h for  in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Mon Jan  9 18:36:37 2017 Thomas ARBONA
** Last update Fri Jan 13 13:47:43 2017 Thomas ARBONA
*/
#ifndef GAME_RAYCASTING_H_
# define GAME_RAYCASTING_H_

# include <pthread.h>
# include "level/level.h"
# include "view/entity/video.h"

typedef struct		s_th_data
{
  int			index;
  int			limit;
  float			scan;
}			t_th_data;

# define NB_THREAD	8

void		raycasting_make();
pthread_mutex_t	*get_mutex();

#endif /* !GAME_RAYCASTING_H_ */
