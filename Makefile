# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/02 13:02:52 by marimatt          #+#    #+#              #
#    Updated: 2022/06/20 14:44:53 by marimatt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	    =		minishell

SRC     	=		main.c \

CFLAGS  	=		-Wall -Werror -Wextra

SRC_OBJ 	=		$(SRC:.c=.o)

LINKS		=		-lreadline

all:    $(NAME)

$(NAME):	$(SRC_OBJ)
		gcc $(CFLAGS) $(LINKS) $(SRC_OBJ) -o $(NAME)

clean:
	/bin/rm -f	*.o utils/*.o

fclean: clean
	/bin/rm -f	$(NAME)

re: fclean
	make

rec: re
	make clean

.PHONY: re fclean clean rec all
