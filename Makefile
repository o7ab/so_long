# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 14:49:38 by oabushar          #+#    #+#              #
#    Updated: 2022/04/24 02:06:10 by oabushar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CFLAGS	= -Wall -Werror -Wextra -g3

mlx = ./mlx/libmlx.a

$(NAME)	:
		make -C ./mlx
		gcc $(CFLAGS) -o so_long so_long.c $(mlx) -framework OpenGL -framework AppKit

all	: $(NAME)

clean :
		rm -f $(OBJS)
		make clean -C mlx

fclean : clean
		rm -f $(NAME)
		make clean -C mlx

re : fclean all
