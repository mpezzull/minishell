# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 18:35:14 by assokenay         #+#    #+#              #
#    Updated: 2021/07/26 17:09:21 by mde-rosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c echo.c init.c counters.c \
			ft_lexer.c ft_lexer_utils.c ft_lexer_utils_2.c \

NAME	=	minishell

LIBS	=	./libft/libft.a -lreadline

OBJCS	=	$(SRCS:.c=.o)

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

%.o		:	%.c
			@$(CC)  -c $<

all		:	$(NAME)
			
$(NAME)	:	$(OBJCS)
			@(make --no-print-directory -C libft/)
			@(make --no-print-directory -C bin/)
			@$(CC) $(FLAGS) -o $(NAME) $(OBJCS) $(LIBS)
			@echo "\033[1;32m$@ successfully build\033[0m"

clean	:
			@(make clean --no-print-directory -C ./libft/)
			@(make clean --no-print-directory -C ./bin/)
			@rm -f $(OBJCS)
			@echo "\033[1;31m.o files deleted\033[0m"

fclean	:	clean
			@(make fclean --no-print-directory -C ./libft/)
			@(make fclean --no-print-directory -C ./bin/)
			@rm -f $(NAME)
			@rm -rf debug*
			@echo "\033[1;31mbinaries deleted\033[0m"

re		:	fclean all

debug	:	re
			@$(CC) -g $(SRCS) $(LIBS) -o debug
			@echo "\033[1;31mper aprire il debug: \033[1;32mlancia \"lldb debug\"\033[0m"

.PHONY	:	all clean fclean re debug
