/*
** load.c for level in /home/arbona/tek1/MUL/wolf3d
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Jan  5 12:15:41 2017 Thomas ARBONA
** Last update Sat Jan 21 19:16:13 2017 Thomas ARBONA
*/
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "my.h"
#include "level/setter.h"
#include "level/entity/update_fnc.h"
#include "util/get_next_line.h"

t_update_fnc	g_update_fnc[] = {
  {"map", &level_setmap},
  {"player", &level_setplayer},
  {"sprites", &level_setsprites},
  {NULL, NULL}
};

static void	exec_update_fnc(char *line, int fd, t_level *level)
{
  int		index;

  index = 0;
  if (line[0] != 0)
    line[strlen(line) - 1] = 0;
  while (g_update_fnc[index].func != NULL)
    {
      if (strcmp(line, g_update_fnc[index].name) == 0)
	return (g_update_fnc[index].func(fd, level));
      index += 1;
    }
}

t_level	*level_load(char *filename, t_level *level)
{
  int	fd;
  char	*line;

  if ((fd = open(filename, O_RDONLY)) < 0)
    return (level = NULL);
  while ((line = get_next_line(fd)))
    exec_update_fnc(line, fd, level);
  close(fd);
  return (level);
}
