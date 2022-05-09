/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:38:42 by oabushar          #+#    #+#             */
/*   Updated: 2022/05/05 23:07:41 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collect_down(t_map *spec)
{
	if (spec->split[spec->py + 1][spec->px] == 'C')
	{
		spec->split[spec->py + 1][spec->px] = '0';
		spec->collectable -= 1;
		return ;
	}
}

void	ft_lose(t_map *spec)
{
	ft_free(spec);
	mlx_destroy_window(spec->mlx, spec->mlx_new);
	mlx_destroy_image(spec->mlx, spec->img);
	write(1, "You lost puto\n", 15);
	exit(1);
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_free(t_map *spec)
{
	int	i;

	i = 0;
	while (spec->split[i])
		free (spec->split[i++]);
	free (spec->split[i]);
	free (spec->split);
}
