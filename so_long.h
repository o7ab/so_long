/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:18:34 by oabushar          #+#    #+#             */
/*   Updated: 2022/05/05 23:04:10 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

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
int		ft_close(t_map *spec);
int		maplength(t_map *spec);
int		checkchar(char c);
int		begin(t_map *spec, int k);
int		getx(t_map *spec);
void	ft_free(t_map *spec);
void	ft_lose(t_map *spec);
void	ft_collect(t_map *spec);
void	ft_putchar_fd(char c, int fd);
void	ft_move(t_map *spec);
void	ft_exit(t_map *spec);
void	ft_putnbr_fd(int n, int fd);
void	ft_collect_down(t_map *spec);
void	ft_collect_up(t_map *spec);
void	ft_collect_left(t_map *spec);
void	ft_collect_right(t_map *spec);

#endif