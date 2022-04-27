/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:18:34 by oabushar          #+#    #+#             */
/*   Updated: 2022/04/27 16:27:14 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx/mlx.h"
#include "get_next_line/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_image {
	int		collectable;
	int		ex;
	int		start;
	char	**split;
	int		height;
	void	*img;
	void	*mlx;
	void	*mlx_new;
	int		x;
	int		y;
	int		h;
	int		w;
	int		px;
	int		py;
	int		counter;
}	t_map;


int		maplength(t_map *spec);
int		getheight(t_map *spec);
int		ft_maphandle(char *str, t_map *spec);
t_map	*ft_assign(t_map *spec);
char	*ft_strstr(char *str, char *to_find);
char	**ft_split(char const *s, char c);
int		ft_hook(int keycode, t_map *spec);
int		getx(t_map *spec);

#endif