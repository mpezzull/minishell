# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 18:35:14 by mde-rosa          #+#    #+#              #
#    Updated: 2021/11/21 01:51:40 by mde-rosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

SRCS_PATH		=	./srcs/

OBJ_PATH 		= 	./obj/

LIBS 			=	-L /Users/$(USER)/.brew/opt/readline/lib ./libft/libft.a -lreadline

INCLUDE			=	-I /Users/$(USER)/.brew/opt/readline/include

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror 

OTHER_MAKE_1	=	./libft/

OTHER_MAKE_2	=	./bin/
					
SRCS			=	main.c \
					free.c get_next_line.c get_next_line_utils.c minishell_utils.c minishell_utils_2.c parser.c \
					ft_lexer.c ft_lexer_word.c ft_lexer_token.c parser_utils.c \
					our_cd.c our_cd_utils.c our_export.c our_unset.c \
					ft_lexer_utils.c expander.c executer.c parser_utils_2.c\
					executer_utils.c executer_utils_2.c executer_utils_3.c expander_utils.c exit.c

OBJCS 			= 	$(patsubst %,$(OBJ_PATH)%,$(SRCS:.c=.o))

$(OBJ_PATH)%.o	:	$(SRCS_PATH)%.c
					@([ -d $(OBJ_PATH) ] || mkdir -p $(OBJ_PATH))
					@$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all		:	$(NAME)
			
$(NAME)	:	$(OBJCS)
			$(export PATH=$(PATH):$(PWD)/bin)
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
			@(rm -rf $(OBJ_PATH))
			@rm -rf minishell*
			@echo "\033[1;31mbinaries deleted\033[0m"

re		:	fclean all

.PHONY	:	all clean fclean re
