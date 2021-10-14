# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 18:35:14 by assokenay         #+#    #+#              #
#    Updated: 2021/10/14 19:09:30 by mpezzull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

SRCS_PATH		=	./src/

OBJ_PATH 		= 	./obj/

#LINUX LIBS			=	-L./libft -L/readline-6.3 -lft -lreadline -lhistory -ltinfo

LIBS 			=	-L /Users/$(USER)/.brew/opt/readline/lib ./libft/libft.a -lreadline

INCLUDE			=	-I /Users/$(USER)/.brew/opt/readline/include

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

OTHER_MAKE_1	=	./libft/

OTHER_MAKE_2	=	./bin/
					
SRCS			=	main.c \
					init.c free.c get_next_line.c minishell_utils.c parser.c \
					ft_lexer.c ft_lexer_word.c ft_lexer_token.c parser_utils.c \
					ft_lexer_utils.c expander.c env.c executer.c parser_utils_2.c\
					executer_utils.c executer_utils_2.c

OBJCS 			= 	$(patsubst %,$(OBJ_PATH)%,$(SRCS:.c=.o))

$(OBJ_PATH)%.o	:	$(SRCS_PATH)%.c
					@(mkdir -p $(OBJ_PATH))
					@$(CC) $(FLAGS) $(INCLUDE) -o $@ -c $<
	
all		:	$(NAME)
			
$(NAME)	:	$(OBJCS)
			@(make -s -C $(OTHER_MAKE_1))
			@(make -s -C $(OTHER_MAKE_2))
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJCS) $(LIBS)

			@echo "\033[1;32m\"./$@\" successfully build\033[0m"

clean	:
			@(make clean -s -C  $(OTHER_MAKE_1))
			@(make clean -s -C  $(OTHER_MAKE_2))
			@rm -f $(OBJCS)
			@echo "\033[1;31m.o files deleted\033[0m"

fclean	:	clean
			@(make fclean -s -C  $(OTHER_MAKE_1))
			@(make fclean -s -C  $(OTHER_MAKE_2))
			@rm -f $(NAME)
			@(rm -rf $(OBJ_PATH))
			@rm -rf debug*
			@echo "\033[1;31mbinaries deleted\033[0m"

re		:	fclean all

debug	:	re
			@$(CC) $(CFLAGS) -g $(INCLUDE) -o $@ $(patsubst %,$(SRCS_PATH)%,$(SRCS)) $(LIBS)
			@echo " \033[1;32m\"lldb $@\" \033[0mper aprire il debug"

.PHONY	:	all clean fclean re debug
