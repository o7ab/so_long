/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 23:28:15 by oabushar          #+#    #+#             */
/*   Updated: 2022/04/28 21:23:15 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	getx(t_map *spec)
{
	int	i;
	int	j;

	i = 0;
	while (spec->split[i])
	{
		j = 0;
		while (spec->split[i][j])
		{
			if (spec->split[i][j] == 'P')
			{
				spec->py = i;
				return (j);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_move(t_map *spec)
{
	int	w;
	int	h;
	int	x;
	int	y;

	x = spec->px * 75;
	y = spec->py * 75;
	spec->img = mlx_xpm_file_to_image(spec->mlx, "./player.xpm", &w, &h);
	mlx_put_image_to_window(spec->mlx, spec->mlx_new, spec->img, x, y);
}

void	ft_exit(t_map *spec)
{
	ft_free(spec);
	mlx_destroy_window(spec->mlx, spec->mlx_new);
	mlx_destroy_image(spec->mlx, spec->img);
	write(1, "YOU WON WOOOOOOOO!\n", 20);
	exit(1);
}

int	ft_close(t_map *spec)
{
	ft_free(spec);
	mlx_destroy_window(spec->mlx, spec->mlx_new);
	write(1, "You gave up\n", 13);
	exit(1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write (fd, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar_fd(n + 48, fd);
		return ;
	}
	else
	{
		ft_putnbr_fd(n / 10, 1);
		ft_putnbr_fd(n % 10, 1);
	}
}
