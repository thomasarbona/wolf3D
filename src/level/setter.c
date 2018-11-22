/*
** setter.c for level in /home/arbona/tek1/MUL/wolf3d
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Jan  5 13:54:23 2017 Thomas ARBONA
** Last update Wed Mar  8 11:09:23 2017 Thomas ARBONA
** Last update Mon Jan 23 21:13:06 2017 Thomas ARBONA
*/
#include <stdlib.h>
#include <SFML/System/Vector2.h>
#include "level/level.h"
#include "util/get_next_line.h"
#include "game/sprite/sprite.h"
#include "util.h"
#include "my.h"

static void	handle_mapline(char *line, t_level *level, int index)
{
  char		**cells;
  char		**block;
  int		index2;
  int		nb_cell;

  cells = my_str_to_wordtab(line, ", ");
  if (!(level->map.blocks[index] =
	malloc(sizeof(t_block) * (level->map.size.x))))
    return;
  nb_cell = my_tablen((void**)cells);
  index2 = 0;
  while (index2 != level->map.size.x)
    {
      block = my_str_to_wordtab(cells[index2], "{;} ");
      level->map.blocks[index][index2] = (index2 < nb_cell)
	? map_newblock(block)
	: map_newblock(NULL);
      index2 += 1;
    }
}

void		level_setmap(int fd, t_level *level)
{
  char		*line;
  char		**size;
  int		index;

  index = 0;
  size = my_str_to_wordtab(get_next_line(fd), "[;]");
  level->map.size.x = my_getnbr(size[0]);
  level->map.size.y = my_getnbr(size[1]);
  if (!(level->map.blocks =
	malloc(sizeof(t_block*) * (level->map.size.y + 1))))
    return;
  while ((line = get_next_line(fd)) && line[0] != 0)
    {
      if (index < level->map.size.y)
	handle_mapline(line, level, index);
      index += 1;
    }
  level->map.blocks[level->map.size.y] = NULL;
}

void	level_setplayer(int fd, t_level *level)
{
  char	**pos;
  char	*line;

  pos = my_str_to_wordtab(get_next_line(fd), "[;]");
  level->player.pos.x = (float)my_getnbr(pos[0]) + .5;
  level->player.pos.y = (float)my_getnbr(pos[1]) + .5;
  level->player.mob_target = -1;
  level->player.munition = 0;
  level->player.life = PLAYER_LIFE;
  line = get_next_line(fd);
  level->player.dir = my_getnbr(line);
}

void		level_setsprites(int fd, t_level *level)
{
  char		*line;
  char		**data;
  char		**pos;
  t_sprite	*sprite;

  (void)level;
  (*sprite_getall()) = NULL;
  while ((line = get_next_line(fd)) && line[0] != 0)
    {
      data = my_str_to_wordtab(line, "{, }");
      pos = my_str_to_wordtab(data[0], "[; ]");
      sprite = sprite_create(atoi(data[1]));
      sprite->pos.x = atoi(pos[0]) + .5;
      sprite->pos.y = atoi(pos[1]) + .5;
      sprite->dir = RAND(0, 360);
      sprite->follow = 0;
      sprite->shoot = 0;
      sprite->pos.x = atoi(pos[0]);
      sprite->pos.y = atoi(pos[1]);
      sprite->img = atoi(data[2]);
    }
}
