# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 18:35:14 by assokenay         #+#    #+#              #
#    Updated: 2021/07/13 18:42:49 by mde-rosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= 	gcc
FLAGS 		=	-Wall -Wextra -Werror

FT_ECHO 		=	ft_echo
SRC_FT_ECHO		=	ft_echo.c
OBJCS_FT_ECHO 	= $(SRC_FT_ECHO:%.c=%.o)

FT_HELLO_WORLD			=	ft_hello_world
SRC_FT_HELLO_WORLD		=	ft_hello_world.c
OBJCS_FT_HELLO_WORLD 	= $(SRC_FT_HELLO_WORLD:%.c=%.o)

%.o			:	%.c
				@$(CC)  -c $<

all			:	$(FT_ECHO) $(FT_HELLO_WORLD)

$(FT_ECHO)	: $(OBJCS_FT_ECHO)
				@$(CC) $(FLAGS) $(SRC_FT_ECHO) -o $(FT_ECHO)

$(FT_HELLO_WORLD)	: $(OBJCS_FT_HELLO_WORLD)
				@$(CC) $(FLAGS) $(SRC_FT_HELLO_WORLD) -o $(FT_HELLO_WORLD)

clean		:
				@rm -f $(OBJCS_FT_ECHO) $(OBJCS_FT_HELLO_WORLD)

fclean		:	clean
				@rm -f $(FT_ECHO) $(FT_HELLO_WORLD)

re			:	fclean all

.PHONY		:	all clean fclean re
