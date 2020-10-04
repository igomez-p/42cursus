# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igomez-p <ire.go.pla@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 16:39:33 by igomez-p          #+#    #+#              #
#    Updated: 2020/02/13 15:39:23 by igomez-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
	ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa_unsig.c ft_itoa.c \
	ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	get_next_line.c printf/*.c

SRCBONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = ${SRC:.c=.o}

OBJBONUS = ${SRCBONUS:.c=.o}

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -c

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJ}
			ar rc ${NAME} ${OBJ}


all: $(NAME)

bonus:	${OBJ} ${OBJBONUS}
		ar rc ${NAME} {OBJBONUS}

clean:
		rm -f ${OBJ} ${OBJBONUS}

fclean: clean
		rm -f ${NAME}

re: fclean all
.PHONY: all clean fclean re