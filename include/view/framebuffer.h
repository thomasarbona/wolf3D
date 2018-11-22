/*
** my_framebuffer.h for bswireframe in /home/arbona/Projects/bswireframe
**
** Made by Thomas ARBONA
** Login   <arbona@epitech.net>
**
** Started on  Thu Nov 17 15:07:00 2016 Thomas ARBONA
** Last update Thu Jan 12 01:03:00 2017 Thomas ARBONA
*/

#ifndef FRAMEBUFFER_H_
# define FRAMEBUFFER_H_

# include <SFML/Graphics.h>

typedef struct	s_my_framebuffer
{
  sfUint8	*pixels;
  int		width;
  int		height;
}		t_my_framebuffer;

void	framebuffer_clear(t_my_framebuffer *fbuff, int);
void	framebuffer_clearall();
int	framebuffer_init(t_my_framebuffer *fbuff, int width, int height);

#endif /* !FRAMEBUFFER_H_ */
