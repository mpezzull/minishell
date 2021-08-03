# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 18:35:14 by assokenay         #+#    #+#              #
#    Updated: 2021/08/03 02:43:11 by mde-rosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

SRCS_PATH		=	./src/

OBJ_PATH 		= 	./obj/

LIBS			=	-L./libft -L/readline-6.3 -lft -lreadline -lhistory -ltinfo

CC				=	gcc

FLAGS			=	-Wall -Wextra -Werror

OTHER_MAKE_1	=	./libft/

OTHER_MAKE_2	=	./bin/

OTHER_MAKE_3	=	./readline-6.3/
					
SRCS			=	main.c echo.c init.c counters.c \
					ft_lexer.c ft_lexer_word.c ft_lexer_token.c \
					ft_lexer_utils.c 

OBJCS 			= 	$(patsubst %,$(OBJ_PATH)%,$(SRCS:.c=.o))

$(OBJ_PATH)%.o	:	$(SRCS_PATH)%.c
					@$(CC) $(FLAGS) -o $@ -c $<
	
all		:	$(NAME)
			
$(NAME)	:	$(OBJCS)
			@(make -s -C $(OTHER_MAKE_1))
			@(make -s -C $(OTHER_MAKE_2))
			@(make -s -C $(OTHER_MAKE_3))
			@$(CC) $(FLAGS) -o $(NAME) $(OBJCS) $(LIBS)
			@echo "\033[1;32m\"./$@\" successfully build\033[0m"

clean	:
			@(make clean -s -C  $(OTHER_MAKE_1))
			@(make clean -s -C  $(OTHER_MAKE_2))
			@(make clean -s -C  $(OTHER_MAKE_3))
			@rm -f $(OBJCS)
			@echo "\033[1;31m.o files deleted\033[0m"

fclean	:	clean
			@(make fclean -s -C  $(OTHER_MAKE_1))
			@(make fclean -s -C  $(OTHER_MAKE_2))
			@rm -f $(NAME)
			@rm -rf debug*
			@echo "\033[1;31mbinaries deleted\033[0m"

re		:	fclean all

debug	:	re
			@$(CC) $(FLAGS) -g -o $@ $(OBJCS) $(LIBS)
			@echo " \033[1;32m\"lldb $@\" \033[0mper aprire il debug"

.PHONY	:	all clean fclean re debug
