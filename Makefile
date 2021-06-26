# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: assokenay <assokenay@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 18:35:14 by assokenay         #+#    #+#              #
#    Updated: 2021/06/26 19:10:51 by assokenay        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c echo.c init.c counters.c

NAME = minishell

LIBS = ./libft/libft.a -lreadline

OBJCS	=	$(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

.c.o		:
				@$(CC)  -c $<

all			:	$(NAME)
			
$(NAME)		:	$(OBJCS)
				@(make re --no-print-directory -C libft/)
				@$(CC) $(FLAGS) -o $(NAME) $(OBJCS) $(LIBS)
			 	@echo "\033[1;32m$@ successfully build\033[0m"

clean		:
				@(make clean --no-print-directory -C ./libft/)
				@rm -f $(OBJCS)
			 	@echo "\033[1;31m.o files deleted\033[0m"

fclean		:	clean
				@(make fclean --no-print-directory -C ./libft/)
				@rm -f $(NAME)
			 	@echo "\033[1;31mbinaries deleted\033[0m"

re			:	fclean all

.PHONY		:	all clean fclean re

