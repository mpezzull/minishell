# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 18:35:14 by assokenay         #+#    #+#              #
#    Updated: 2021/08/02 16:01:36 by mpezzull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c echo.c init.c counters.c parser.c parser_utils.c get_next_line.c \
		minishell_utils.c expander.c free.c \
    			ft_lexer.c ft_lexer_word.c ft_lexer_token.c ft_lexer_utils.c 

NAME	=	minishell

LIBS =  -L /Users/$(USER)/.brew/opt/readline/lib ./libft/libft.a  -lreadline

INCLUDE = -I /Users/$(USER)/.brew/opt/readline/include

OBJCS	=	$(SRCS:.c=.o)

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

%.o		:	%.c
			@$(CC) $(FLAGS) $(INCLUDE) -c $< #-fsanitize=address -static-libsan

all		:	$(NAME)
			
$(NAME)		:	$(OBJCS)
				@(make --no-print-directory -C libft/)
				@(make --no-print-directory -C bin/)
				@$(CC) $(FLAGS) $(OBJCS) -o $(NAME) $(LIBS) #-fsanitize=address
				@echo "\033[1;32m$@ successfully build\033[0m"

clean		:
				@(make clean --no-print-directory -C ./libft/)
				@(make clean --no-print-directory -C ./bin/)
				@rm -f $(OBJCS)
			 	@echo "\033[1;31m.o files deleted\033[0m"

fclean		:	clean
				@(make fclean --no-print-directory -C ./libft/)
				@(make fclean --no-print-directory -C ./bin/)
				@rm -f $(NAME)
				@rm -rf debug*
			 	@echo "\033[1;31mbinaries deleted\033[0m"

re			:	fclean all

debug	:	re
			@$(CC) -g $(FLAGS) $(INCLUDE) $(SRCS) $(LIBS) -o debug
		  	@echo "\033[1;31mper aprire il debug: \033[1;32mlancia \"lldb debug\"\033[0m"

.PHONY		:	all clean fclean re
