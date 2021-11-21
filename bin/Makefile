# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 18:35:14 by mde-rosa          #+#    #+#              #
#    Updated: 2021/11/20 23:52:56 by mde-rosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 				=	gcc
CFLAGS 			=	-Wall -Wextra -Werror

OUR_ECHO 		=	our_echo
SRC_OUR_ECHO	=	our_echo.c
OBJCS_OUR_ECHO 	=	$(SRC_OUR_ECHO:%.c=%.o)

OUR_PWD			=	our_pwd
SRC_OUR_PWD		=	our_pwd.c
OBJCS_OUR_PWD 	=	$(SRC_OUR_PWD:%.c=%.o)

OUR_ENV			=	our_env
SRC_OUR_ENV		=	our_env.c
OBJCS_OUR_ENV 	=	$(SRC_OUR_ENV:%.c=%.o)

%.o				:	%.c
					@$(CC) $(CFLAGS) -o $@ -c $<

all				:	$(OUR_ECHO) $(OUR_PWD) $(OUR_ENV)

$(OUR_ECHO)		:	$(OBJCS_OUR_ECHO)
					@$(CC) $(CFLAGS) $(SRC_OUR_ECHO) -o $(OUR_ECHO)

$(OUR_PWD)		:	$(OBJCS_OUR_PWD)
					@$(CC) $(CFLAGS) $(SRC_OUR_PWD) -o $(OUR_PWD)

$(OUR_ENV)		:	$(OBJCS_OUR_ENV)
					@$(CC) $(CFLAGS) $(SRC_OUR_ENV) -o $(OUR_ENV)

clean			:
					@rm -f *.o

fclean			:	clean
					@rm -f $(OUR_ECHO) $(OUR_PWD) $(OUR_ENV)

re				:	fclean all

.PHONY			:	all clean fclean re
