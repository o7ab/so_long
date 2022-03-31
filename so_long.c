/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:17:24 by oabushar          #+#    #+#             */
/*   Updated: 2022/03/29 13:53:16 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "map_utils.c"
#include "map_utils2.c"
#include "get_next_line/get_next_line.c"


int main(int argc, char **argv)
{
	// t_data	core;
	// t_vect	vector;
	int fd;

	fd = open (argv[1], O_RDONLY);
	if (argc < 2)
	{
		printf ("Not enough arguements \n");
		return (0);
	}
	if (ft_maphandle(argv[1], fd) == 0)
	{
		printf("Invalid map \n");
		return (0);
	}

	// vector.x = 500;
	// vector.y = 500;

	// void *mlx = mlx_init();
	// void *mlx_new = mlx_new_window(mlx, 1000,500, "Hello");
	// core.img = mlx_new_image(mlx, 100, 100);
	// core.img = mlx_xpm_file_to_image(mlx, "./Super-mario.xpm", &vector.x, &vector.y);
	// core.addrs = mlx_get_data_addr(core.img, &core.bits, &core.linelen, &core.endian);
	// mlx_put_image_to_window(mlx, mlx_new, core.img, 0, 0);
	
	// mlx_loop(mlx);
}
