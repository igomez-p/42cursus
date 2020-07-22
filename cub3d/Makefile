# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igomez-p <ire.go.pla@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/06 15:29:03 by igomez-p          #+#    #+#              #
#    Updated: 2020/02/13 15:54:41 by igomez-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3d

SRCS =	*.c libft/*.c libft/printf/*.c
OBJS =	$(SRCS:.c=.o)

CC =	gcc
FLAGS =	$(CC) -Wall -Werror -Wextra -framework OpenGL -framework AppKit -lmlx -lXext -lX11

all:	$(NAME)

# COMPROBAR
$(NAME):$(OBJS)
		make -C minilibx_opengl_20191021
		ar rc ${NAME} ${OBJS}

# COMPROBAR
debug:	$(CC) $(FLAGS) -g $(SRCS) minilibx_opengl_20191021/*.c -I minilibx_opengl_20191021

clean:	rm -f ${OBJS}
fclean:	rm -f ${NAME} minilibx_opengl_20191021/*.o *.o

re:		fclean all
.PHONY:	all clean fclean re



