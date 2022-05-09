/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:17:24 by oabushar          #+#    #+#             */
/*   Updated: 2022/04/27 23:02:25 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print(char *path, t_map *core)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	core->img = mlx_xpm_file_to_image(core->mlx, path, &w, &h);
	mlx_put_image_to_window(
		core->mlx, core->mlx_new, core->img, core->x, core->y);
}

void	ft_helper(t_map *spec, char c)
{
	if (c == '1')
		ft_print("./wall.xpm", spec);
	if (c == '0')
		ft_print("./floor.xpm", spec);
	if (c == 'P')
	{
		ft_print("./floor.xpm", spec);
		ft_print("./player.xpm", spec);
	}
	if (c == 'C')
	{
		ft_print("./floor.xpm", spec);
		ft_print("./collectable.xpm", spec);
	}
	if (c == 'E')
	{
		ft_print("./floor.xpm", spec);
		ft_print("./exit.xpm", spec);
	}
}

void	ft_putmap(t_map *spec)
{
	int	i;
	int	j;

	i = 0;
	spec->mlx_new = mlx_new_window(spec->mlx, spec->w, spec->h, "so_long");
	while (spec->split[i])
	{
		j = 0;
		spec->x = 0;
		while (spec->split[i][j])
		{
			ft_helper(spec, spec->split[i][j]);
			j++;
			spec->x += 75;
		}
		i++;
		spec->y += 75;
	}
}

int	main(int argc, char **argv)
{
	t_map	spec;

	if (argc < 2)
	{
		printf ("Not enough arguements \n");
		return (0);
	}
	if (ft_maphandle(argv[1], &spec) == 0)
	{
		printf("Invalid map \n");
		return (0);
	}
	spec.mlx = mlx_init();
	ft_putmap(&spec);
	mlx_hook (spec.mlx_new, 2, (1L << 0), ft_hook, &spec);
	mlx_hook (spec.mlx_new, 17, (1L << 17), ft_close, &spec);
	mlx_loop(spec.mlx);
}
