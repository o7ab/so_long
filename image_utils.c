/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 06:32:55 by oabushar          #+#    #+#             */
/*   Updated: 2022/05/05 23:08:53 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_left(t_map *spec)
{
	int	imgw;
	int	imgh;

	write (1, "Moves: ", 8);
	ft_putnbr_fd(spec->counter, 1);
	write (1, "\r", 1);
	if (spec->split[spec->py][spec->px - 1] == 'E')
		if (spec->collectable <= 0)
			ft_exit(spec);
	if (spec->split[spec->py][spec->px - 1] == 'E' && spec->collectable != 0)
		return ;
	if (spec->split[spec->py][spec->px - 1] != '1')
	{
		spec->counter++;
		spec->img = mlx_xpm_file_to_image(
				spec->mlx, "./floor.xpm", &imgw, &imgh);
		mlx_put_image_to_window(
			spec->mlx, spec->mlx_new, spec->img, spec->px * 75, spec->py * 75);
		ft_collect_left(spec);
		spec->px -= 1;
		ft_move(spec);
	}
}

void	ft_right(t_map *spec)
{
	int	imgw;
	int	imgh;

	write (1, "Moves: ", 8);
	ft_putnbr_fd(spec->counter, 1);
	write (1, "\r", 1);
	if (spec->split[spec->py][spec->px + 1] == 'E')
		if (spec->collectable <= 0)
			ft_exit(spec);
	if (spec->split[spec->py][spec->px + 1] == 'E' && spec->collectable != 0)
		return ;
	if (spec->split[spec->py][spec->px + 1] != '1')
	{
		spec->counter++;
		spec->img = mlx_xpm_file_to_image(
				spec->mlx, "./floor.xpm", &imgw, &imgh);
		mlx_put_image_to_window(
			spec->mlx, spec->mlx_new, spec->img, spec->px * 75, spec->py * 75);
		ft_collect_right(spec);
		spec->px += 1;
		ft_move(spec);
	}
}

void	ft_down(t_map *spec)
{
	int	imgw;
	int	imgh;

	write (1, "Moves: ", 8);
	ft_putnbr_fd(spec->counter, 1);
	write (1, "\r", 1);
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
		spec->img = mlx_xpm_file_to_image(
				spec->mlx, "./floor.xpm", &imgw, &imgh);
		mlx_put_image_to_window(
			spec->mlx, spec->mlx_new, spec->img, spec->px * 75, spec->py * 75);
		ft_collect_down(spec);
		spec->py += 1;
		ft_move(spec);
	}
}

void	ft_up(t_map *spec)
{
	int	imgw;
	int	imgh;

	write (1, "Moves: ", 8);
	ft_putnbr_fd(spec->counter, 1);
	write (1, "\r", 1);
	if (spec->split[spec->py - 1][spec->px] == 'E')
		if (spec->collectable <= 0)
			ft_exit(spec);
	if (spec->split[spec->py - 1][spec->px] == 'E' && spec->collectable != 0)
		return ;
	if (spec->split[spec->py - 1][spec->px] != '1')
	{
		spec->counter++;
		spec->img = mlx_xpm_file_to_image(
				spec->mlx, "./floor.xpm", &imgw, &imgh);
		mlx_put_image_to_window(
			spec->mlx, spec->mlx_new, spec->img, spec->px * 75, spec->py * 75);
		ft_collect_up(spec);
		spec->py -= 1;
		ft_move(spec);
	}
}

int	ft_hook(int keycode, t_map *spec)
{
	if (keycode == 53)
		ft_lose(spec);
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
