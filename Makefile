# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/02 13:02:52 by marimatt          #+#    #+#              #
#    Updated: 2022/11/17 11:10:13 by mvolpi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

SRC			=	src/main.c \

LIBFT		=	libft/libft.a

CFLAGS		=	-Wall -Werror -Wextra

OBJ_DIR		=	obj

OBJ		=	$(SRC:src/%.c=$(OBJ_DIR)/%.o)

LINKS		=	-lreadline

all:	$(NAME)

clean:
	@echo "-Removing minishell object files..."
	@rm -rf $(OBJ_DIR)
	@echo "		MINISHELL OBJECT DELETED!!"
	@make -C libft clean

fclean: clean
	@echo "-Removing $(NAME)"
	@rm -rf $(NAME)
	@echo "		$(NAME) *.a DELETED!!"
	@make -C libft fclean

re: fclean all

rec: re clean

$(OBJ_DIR):
			@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: src/%.c
				@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ_DIR) $(OBJ)
			@echo "-Making libft..."
			@make -s -C libft
			@echo "-Making $(NAME)..."
			@gcc $(CFLAGS) $(LINKS) $(LIBFT) -L/usr/local/lib -I/usr/local/include $(OBJ) -o $(NAME)
			@gcc 
			@echo "  $(NAME) CREATED!!"
			@echo "		-COMPILED-"

norm:
		@norminette -R CheckForbiddenSourceHeader

.PHONY: re fclean clean rec all norm
