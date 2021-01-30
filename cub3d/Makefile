# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igomez-p <ire.go.pla@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/06 15:29:03 by igomez-p          #+#    #+#              #
#    Updated: 2021/01/30 16:36:52 by igomez-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3d

SRCS =	cub.c src/*.c library/libft.a
OBJS =	$(SRCS:.c=.o)

CC =	gcc
FLAGS =	$(CC) -Wall -framework OpenGL -framework AppKit -lmlx #-Werror -Wextra

all:	$(NAME)

# COMPROBAR
$(NAME):$(OBJS)
		ar rc ${NAME} ${OBJS}

# COMPROBAR
debug:	$(CC) $(FLAGS) -g $(SRCS)

clean:	rm -f ${OBJS}
fclean:	rm -f ${NAME} *.o

re:		fclean all
.PHONY:	all clean fclean re
