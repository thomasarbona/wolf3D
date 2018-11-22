/*
** sound.h for sound in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Jan 11 11:17:18 2017 Thomas ARBONA
** Last update Wed Jan 11 12:02:10 2017 Thomas ARBONA
*/

#ifndef SOUND_H_
# define SOUND_H_

# include <SFML/Audio.h>

typedef struct		s_sbufflist
{
  int			id;
  sfSoundBuffer		*buff;
  struct s_sbufflist	*next;
}			t_sbufflist;

# define SOUND_FLD	"./resources/sound/"

void		sblist_add(t_sbufflist **, char*);
sfSoundBuffer	***sound_getlist();
void		sound_load();
sfSoundBuffer	*sound_get(int);
void		sound_play(int);

#endif /* !SOUND_H_ */
