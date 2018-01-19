##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Castle Hunter maker
##

SRC_DIR		=	src

SRC		=	src/event.c			\
			src/explosion.c			\
			src/lives.c			\
			src/main.c			\
			src/score.c			\
			src/target.c			\
			src/cursor.c			\
			src/gui.c			\
			src/tools/tools_sprite.c	\
			src/kernel/init_main.c		\
			src/kernel/init_window.c	\
			src/kernel/init_ui.c		\
			src/kernel/init_target.c	\
			src/tools/tools_gui.c		\
			src/ending.c			\
			src/events/events_gui.c		\
			src/boss.c			\
			src/kernel/init_boss.c		\
			src/events/events_boss.c	\
			src/tools/tools_global.c	\
			src/boss_health.c

OBJ		=	$(SRC:.c=.o)

CPPFLAGS	=	-I./include/ -l c_graph_prog

NAME	=	castle_hunter

all :	$(NAME)

$(NAME) :	$(OBJ)
	  gcc -I./include/ -l c_graph_prog -o $(NAME) $(SRC)

clean :
	rm -f $(OBJ)

fclean :	clean
	rm -f $(NAME)

re :	fclean all

.PHONY	: clean fclean re
