# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 23:05:14 by sklaokli          #+#    #+#              #
#    Updated: 2024/11/18 01:13:16 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Libraries
SERVER	=	server
CLIENT	=	client

## Paths to files
SRC_DIR	=	src
INC_DIR	=	include

## Source files
SRC_S	=	$(SRC_DIR)/server.c $(SRC_DIR)/utils.c
SRC_C	=	$(SRC_DIR)/client.c $(SRC_DIR)/utils.c
INC		=	$(INC_DIR)/minitalk.h

## Convert *.c files tnto *.o files
OBJ_S	=	$(SRC_S:%.c=%.o)
OBJ_C	=	$(SRC_C:%.c=%.o)

## Commands
RM		=	rm -f
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror

## Targets
%.o:		%.c
			$(CC) $(FLAGS) -I $(INC) -c $< -o $@

all:		$(SERVER) $(CLIENT)

$(SERVER):	$(OBJ_S)
			$(CC) $(FLAGS) -I $(INC) $(OBJ_S) -o $(SERVER)

$(CLIENT):	$(OBJ_C)
			$(CC) $(FLAGS) -I $(INC) $(OBJ_C) -o $(CLIENT)

clean:
			$(RM) $(OBJ_S) $(OBJ_C)

fclean:		clean
			$(RM) $(SERVER) $(CLIENT)

re:			fclean all

.PHONY:		all clean fclean re help bonus