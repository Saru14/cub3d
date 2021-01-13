SRCNAME    = 	parsing/parsing.c	\
				srcs/main.c			\
				usedata/directions.c\
				usedata/res_sprite_rgb.c\
				utils/utils1.c\
				utils/gnl/get_next_line_utils.c\
				utils/gnl/get_next_line.c \
				verifmap/verifmap1.c


SRCS    = ${SRCNAME}

OBJS    = ${SRCS:.c=.o}

NAME    = cub3D

CC        = gcc
RM        = rm -f
CFLAGS    = -Wall -Wextra -Werror -I.

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
		
${NAME}:    ${OBJS}
		make -C utils/libft
		make -C minilbx
		cp minilbx/libmlx.dylib .
		${CC} -o ${NAME} ${OBJS} -L./utils/libft -lft -L. -lmlx -framework OpenGL -framework AppKit

all:         ${NAME}

clean:
			make -C minilbx clean
			${RM} ${OBJS} ${NAME}

fclean:        clean
			rm -f libmlx.dylib
			${RM} ${NAME}

re:        fclean all

c:        all clean

.PHONY:        clean fclean re all bonus