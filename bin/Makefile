# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-rosa <mde-rosa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 18:35:14 by assokenay         #+#    #+#              #
#    Updated: 2021/08/03 19:36:47 by mde-rosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 				=	gcc
CFLAGS 			=	-Wall -Wextra -Werror -g

OUR_ECHO 		=	our_echo
SRC_OUR_ECHO	=	our_echo.c
OBJCS_OUR_ECHO 	=	$(SRC_OUR_ECHO:%.c=%.o)

OUR_ENV			=	our_pwd
SRC_OUR_ENV		=	our_pwd.c
OBJCS_OUR_ENV 	=	$(SRC_OUR_ENV:%.c=%.o)

OUR_CD			=	our_cd
SRC_OUR_CD		=	our_cd.c
OBJCS_OUR_CD 	=	$(SRC_OUR_CD:%.c=%.o)

%.o				:	%.c
					@$(CC) $(CFLAGS) -o $@ -c $<

all				:	$(OUR_ECHO) $(OUR_ENV) $(OUR_CD)

$(OUR_ECHO)		:	$(OBJCS_OUR_ECHO)
					@$(CC) $(CFLAGS) $(SRC_OUR_ECHO) -o $(OUR_ECHO)

$(OUR_ENV)		:	$(OBJCS_OUR_ENV)
					@$(CC) $(CFLAGS) $(SRC_OUR_ENV) -o $(OUR_ENV)

$(OUR_CD)		:	$(OBJCS_OUR_CD)
					@$(CC) $(CFLAGS) $(SRC_OUR_CD) -o $(OUR_CD)

clean			:
					@rm -f *.o

fclean			:	clean
					@rm -f $(OUR_ECHO) $(OUR_ENV) $(OUR_CD)

re				:	fclean all

.PHONY			:	all clean fclean re
