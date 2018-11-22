/*
** update_fnc.c for level in /home/arbona/tek1/MUL/wolf3d
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Thu Jan  5 17:02:21 2017 Thomas ARBONA
** Last update Thu Jan  5 17:08:22 2017 Thomas ARBONA
*/

#ifndef UPDATE_FNC_H_
# define UPDATE_FNC_H_

typedef struct  s_update_fnc
{
  char          *name;
  void          (*func)(int, t_level*);
}		t_update_fnc;

#endif /* !UPDATE_FNC_H_ */
