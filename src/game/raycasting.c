/*
** raycasting.c for game in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Mon Jan  9 18:04:25 2017 Thomas ARBONA
** Last update Sun Jan 15 23:33:11 2017 Thomas ARBONA
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "game/raycasting.h"
#include "game/vision.h"
#include "level/level.h"
#include "view/view.h"
#include "view/draw/draw.h"
#include "raycast.h"
#include "my_put_pixel.h"

void	th_data_getnext(t_th_data*, t_video*, t_level*);

void			*thread_start(void *arg)
{
  int			index;
  float			scan;
  float			prop;
  int			limit;
  t_video		*video;
  t_level		*level;
  t_raydata		raydata;

  video = view_getvideo();
  level = level_get();
  prop = video->fbuff.width / NB_THREAD;
  index = prop * (int)arg;
  scan = level->player.dir + VISION_FOV / 2.;
  scan -= (prop * (int)arg) * (VISION_FOV / (float)video->fbuff.width);
  limit = index + prop;
  prop = VISION_FOV / (float)video->fbuff.width;
  while (index++ != limit)
    {
      raycast(&raydata, level->player.pos, scan, level);
      raydata.dist = correct_fisheye(raydata.dist, scan, level->player.dir);
      draw_wall(index, &raydata, &video->fbuff);
      draw_floor(index, &raydata, &video->fbuff);
      scan -= prop;
    }
  return (NULL);
}

void			raycasting_make()
{
  pthread_t		th[NB_THREAD];

  pthread_create(&th[0], NULL, thread_start, (void*)0);
  pthread_create(&th[1], NULL, thread_start, (void*)1);
  pthread_create(&th[2], NULL, thread_start, (void*)2);
  pthread_create(&th[3], NULL, thread_start, (void*)3);
  pthread_create(&th[4], NULL, thread_start, (void*)4);
  pthread_create(&th[5], NULL, thread_start, (void*)5);
  pthread_create(&th[6], NULL, thread_start, (void*)6);
  pthread_create(&th[7], NULL, thread_start, (void*)7);
  pthread_join(th[0], NULL);
  pthread_join(th[1], NULL);
  pthread_join(th[2], NULL);
  pthread_join(th[3], NULL);
  pthread_join(th[4], NULL);
  pthread_join(th[5], NULL);
  pthread_join(th[6], NULL);
  pthread_join(th[7], NULL);
}
