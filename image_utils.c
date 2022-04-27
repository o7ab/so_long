/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 06:32:55 by oabushar          #+#    #+#             */
/*   Updated: 2022/04/27 20:27:07 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move(t_map *spec)
{
	int	w;
	int	h;
	int x;
	int y;
	
	x = spec->px * 75;
	y = spec->py * 75;
	spec->img = mlx_xpm_file_to_image(spec->mlx, "./player.xpm", &w, &h);
	mlx_put_image_to_window(spec->mlx, spec->mlx_new, spec->img, x, y);
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_free(t_map *spec)
{
	int i;

	i = 0;
	while (spec->split[i])
		free (spec->split[i++]);
	free (spec->split[i]);
	free (spec->split);
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

void	ft_collect(t_map *spec)
{
	if (spec->split[spec->py][spec->px + 1] == 'C')
	{
		spec->collectable -= 1;
		spec->split[spec->py][spec->px + 1] = '0';
	}
	if (spec->split[spec->py][spec->px - 1] == 'C')
	{
		spec->collectable -= 1;
		spec->split[spec->py][spec->px - 1] = '0';
	}
	if (spec->split[spec->py + 1][spec->px] == 'C')
	{
		spec->collectable -= 1;
		spec->split[spec->py + 1][spec->px] = '0';
	}
	if (spec->split[spec->py - 1][spec->px] == 'C')
	{
		spec->collectable -= 1;
		spec->split[spec->py - 1][spec->px] = '0';
	}
}

void	ft_exit(t_map *spec)
{
	
	mlx_destroy_window(spec->mlx, spec->mlx_new);
	write(1, "YOU WON WOOOOOOOO!\n", 20);
	exit(1);
}

void	ft_left(t_map *spec)
{
	int imgw;
	int imgh;
	
	if (spec->split[spec->py][spec->px - 1] == 'E')
	{
		if (spec->collectable <= 0)
			ft_exit(spec);
	}
	if (spec->split[spec->py][spec->px - 1] == 'E' && spec->collectable != 0)
			return ;
	if (spec->split[spec->py][spec->px - 1] != '1')
	{
		spec->counter++;
		spec->img = mlx_xpm_file_to_image(spec->mlx, "./floor.xpm", &imgw, &imgh);
		mlx_put_image_to_window(spec->mlx, spec->mlx_new, spec->img, spec->px * 75, spec->py * 75);
		ft_collect(spec);
		spec->px -= 1;
		ft_move(spec);
	}
}

void	ft_right(t_map *spec)
{
	int imgw;
	int imgh;
	if (spec->split[spec->py][spec->px + 1] == 'E')
	{
		if (spec->collectable <= 0)
			ft_exit(spec);
	}
	if (spec->split[spec->py][spec->px + 1] == 'E' && spec->collectable != 0)
		return ;
	if (spec->split[spec->py][spec->px + 1] != '1')
	{
		spec->counter++;
		spec->img = mlx_xpm_file_to_image(spec->mlx, "./floor.xpm", &imgw, &imgh);
		mlx_put_image_to_window(spec->mlx, spec->mlx_new, spec->img, spec->px * 75, spec->py * 75);
		ft_collect(spec);
		spec->px += 1;
		ft_move(spec);
	}
}

void	ft_down(t_map *spec)
{
	int imgw;
	int imgh;
	if (spec->split[spec->py + 1][spec->px] == 'E')
	{
		if (spec->collectable <= 0)
			ft_exit(spec);
	}
	if (spec->split[spec->py + 1][spec->px] == 'E' && spec->collectable != 0)
		return ;
	if (spec->split[spec->py + 1][spec->px] != '1')
	{
		spec->counter++;
		spec->img = mlx_xpm_file_to_image(spec->mlx, "./floor.xpm", &imgw, &imgh);
		mlx_put_image_to_window(spec->mlx, spec->mlx_new, spec->img, spec->px * 75, spec->py * 75);
		ft_collect(spec);
		spec->py += 1;
		ft_move(spec);
	}
}

void	ft_up(t_map *spec)
{
	int imgw;
	int imgh;
	if (spec->split[spec->py - 1][spec->px] == 'E')
	{
		if (spec->collectable <= 0)
			ft_exit(spec);
	}
	if (spec->split[spec->py - 1][spec->px] == 'E' && spec->collectable != 0)
		return ;
	if (spec->split[spec->py - 1][spec->px] != '1')
	{
		spec->counter++;
		spec->img = mlx_xpm_file_to_image(spec->mlx, "./floor.xpm", &imgw, &imgh);
		mlx_put_image_to_window(spec->mlx, spec->mlx_new, spec->img, spec->px * 75, spec->py * 75);
		ft_collect(spec);
		spec->py -= 1;
		ft_move(spec);
	}
}

void	ft_lose(t_map *spec)
{
	ft_free(spec);
	mlx_destroy_window(spec->mlx, spec->mlx_new);
	write(1, "You lost puto\n", 15);
	exit(1);
}

int	ft_hook(int keycode, t_map *spec)
{
	if (keycode == 53)
		ft_lose(spec);
	write (1, "Moves: ", 8);
	ft_putnbr_fd(spec->counter, 1);
	write (1, "\n", 1);
	if (keycode == 13)
		ft_up(spec);
	if (keycode == 0)
		ft_left(spec);
	if (keycode == 1)
		ft_down(spec);
	if (keycode == 2)
		ft_right(spec);
	return (0);
}

int ft_close(t_map *spec)
{
	ft_free(spec);
	write(1, "You gave up\n", 13);
	exit(1);
}