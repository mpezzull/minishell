# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpezzull <mpezzull@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 18:35:14 by assokenay         #+#    #+#              #
#    Updated: 2021/08/02 19:12:39 by mpezzull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= 	gcc
FLAGS 		=	-Wall -Wextra -Werror

FT_ECHO 		=	ft_echo
SRC_FT_ECHO		=	ft_echo.c
OBJCS_FT_ECHO 	= $(SRC_FT_ECHO:%.c=%.o)

FT_HELLO_WORLD			=	our_pwd
SRC_FT_HELLO_WORLD		=	our_pwd.c
OBJCS_FT_HELLO_WORLD 	= $(SRC_FT_HELLO_WORLD:%.c=%.o)

%.o			:	%.c
				@$(CC) -c $<

all			:	$(FT_ECHO) $(FT_HELLO_WORLD)

$(FT_ECHO)	: $(OBJCS_FT_ECHO)
				@$(CC) $(FLAGS) $(SRC_FT_ECHO) -o $(FT_ECHO)

$(FT_HELLO_WORLD)	: $(OBJCS_FT_HELLO_WORLD)
				@$(CC) $(FLAGS) $(SRC_FT_HELLO_WORLD) -o $(FT_HELLO_WORLD)

clean		:
				@rm -f *.o

fclean		:	clean
				@rm -f $(FT_ECHO) $(FT_HELLO_WORLD)

re			:	fclean all

.PHONY		:	clean fclean
