/*
** shot.h for action in /home/arbona/tek1/MUL/wolf3d/bonus
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Tue Jan 10 23:06:38 2017 Thomas ARBONA
** Last update Wed Jan 11 10:46:14 2017 Thomas ARBONA
*/

#ifndef ACTION_SHOT_H_
# define ACTION_SHOT_H_

typedef struct		s_shotdata
{
  unsigned long long	last_ms;
  int			is_shooting;
  int			was_shooting;
}			t_shotdata;

# define SHOT_DELAY	100

int	action_is_shooting();
int	action_was_shooting();
void	action_handle_shot();

#endif /* !ACTION_SHOT_H_ */
