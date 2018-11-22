/*
** util.h for wolf3d in /home/arbona/tek1/MUL/wolf3d
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Wed Jan  4 17:08:26 2017 Thomas ARBONA
** Last update Sat Jan 14 23:26:56 2017 Thomas ARBONA
*/

#ifndef UTIL_H_
# define UTIL_H_

# include <math.h>
# include <stdlib.h>

# define SQRT2D2	0.70710678118

# define ABS(x)		(((x) < 0) ? -(x) : (x))
# define MIN(x, y)	(((x) < (y)) ? (x) : (y))
# define RAND(x, y)	((rand() % (x - y)) + y)
# define LOWINT(x)	((int)floor(x))

#endif /* !UTIL_H_ */
