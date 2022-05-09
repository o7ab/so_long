# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 14:49:38 by oabushar          #+#    #+#              #
#    Updated: 2022/05/05 23:07:56 by oabushar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c map_utils.c map_utils2.c map_utils3.c map_utils4.c image_utils.c image_utils2.c image_utils3.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 

OBJS = $(SRCS:.c=.o)

NAME	= so_long

CFLAGS	= -Wall -Werror -Wextra -g

mlx = ./mlx/libmlx.a

$(NAME)	:
		make -C ./mlx
		gcc $(CFLAGS) -o so_long $(SRCS) $(mlx) -framework OpenGL -framework AppKit

all	: $(NAME)

clean :
		rm -f $(OBJS)
		make clean -C mlx

fclean : clean
		rm -f $(NAME)
		make clean -C mlx

re : fclean all
