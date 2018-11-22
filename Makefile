##
## Makefile for wolf3d in /home/arbona/tek1/MUL/wolf3d
## 
## Made by Thomas ARBONA
## Login   <thomas.arbona@epitech.eu>
## 
## Started on  Fri Nov 25 22:48:57 2016 Thomas ARBONA
## Last update Sat Jan 21 19:05:30 2017 Thomas ARBONA
##

CC	=	gcc

SRCS	=	src/level/setter.c		\
		src/level/load.c		\
		src/level/map.c			\
		src/level/level.c		\
		src/game/frame/frame.c		\
		src/game/frame/game.c		\
		src/game/frame/menu.c		\
		src/game/frame/pause.c		\
		src/game/frame/over.c		\
		src/game/event/event.c		\
		src/game/action/move.c		\
		src/game/action/shot.c		\
		src/game/action/drop.c		\
		src/game/sprite/sprite.c	\
		src/game/sprite/handle.c	\
		src/game/enemy/enemy.c		\
		src/game/enemy/move.c		\
		src/game/raycasting.c		\
		src/game/data.c			\
		src/game/time.c			\
		src/game/zbuffer.c		\
		src/game/vision.c		\
		src/view/draw/wall.c		\
		src/view/draw/floor.c		\
		src/view/draw/sprite.c		\
		src/view/draw/img.c		\
		src/view/draw/text.c		\
		src/view/texture/texture.c	\
		src/view/texture/getter.c	\
		src/view/texture/setter.c	\
		src/view/framebuffer.c		\
		src/view/color.c		\
		src/view/shader.c		\
		src/view/view.c			\
		src/sound/sound.c		\
		src/sound/setter.c		\
		src/sound/getter.c		\
		src/util/get_next_line.c	\
		src/my_draw_line.c		\
		src/my_put_pixel.c		\
		src/move_forward.c		\
		src/raycast.c			\
		src/main.c

CFLAGS	=	-W -Wall -I./include -I./src -O3

LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lsfml-graphics -lsfml-window -lsfml-system -lcsfml-audio -lm -L./lib -lmy -lpthread

OBJS	=	$(SRCS:.c=.o)

NAME	=	wolf3d

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
