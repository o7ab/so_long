/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:18:34 by oabushar          #+#    #+#             */
/*   Updated: 2022/03/29 13:34:50 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx/mlx.h"
#include "get_next_line/get_next_line.h"
// #include "get_next_line/get_next_line.c"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_image {
	int	collectable;
	int	ex;
	int	start;
	char **split;
	int height;
}	t_map;

typedef struct s_data {
	void	*img;
	int 	endian;
	int		bits;
	int		linelen;
	char	*addrs;
}	t_data;

typedef struct s_vect {
	int	x;
	int	y;
}	t_vect;

int		maplength(t_map spec);
int		getheight(t_map spec);
int		ft_maphandle(char *str, int fd);
void	ft_assign();
char	*ft_strstr(char *str, char *to_find);
char	**ft_split(char const *s, char c);


#endif