# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 14:49:38 by oabushar          #+#    #+#              #
#    Updated: 2022/03/24 11:09:44 by oabushar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SO_LONG = so_long

SRC_NAME = so_long.c 

OBJ_NAME = $(SRC_NAME:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: ${SO_LONG}
${SO_LONG}:
	$(CC) -o so_long -Lmlx -lmlx -framework OpenGL -framework AppKit so_long.c

clean :
	rm -rf ${SO_LONG}
fclean: clean
	rm -f ${SO_LONG} 
re: fclean all
