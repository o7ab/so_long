/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:17:24 by oabushar          #+#    #+#             */
/*   Updated: 2022/03/15 10:06:07 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "get_next_line/get_next_line.h"
#include "get_next_line/get_next_line.c"

// typedef struct s_data {
// 	void	*img;
// 	int 	endian;
// 	int		bits;
// 	int		linelen;
// 	char	*addrs;
// }	t_data;

// typedef struct s_vect {
// 	int	x;
// 	int	y;
// }	t_vect;

char		*ft_strstr(char *str, char *to_find)
{
	int i;
	int rt;

	i = 0;
	if (to_find[0] == (0))
		return (str);
	while (str[i])
	{
		rt = (0);
		while (str[i + rt] != 0 && str[i + rt] == to_find[rt])
		{
			if (to_find[rt + 1] == 0)
				return (&str[i]);
			++rt;
		}
		++i;
	}
	return (0);
}

int	ft_maphandle(char *str, int fd)
{
	char **lines;
	int i;
	
	i = 0;
	if (ft_strstr(str, ".ber") == 0)
		return (0);
	
	while (i)
	{
		lines[i] = get_next_line(fd);
		if (!lines[i])
			return (0);
		i++;
	}
	i = 0;
	while (lines[i])
	{
		if (ft_strlen(lines[i]) != ft_strlen(lines[0]))
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	// t_data	core;
	// t_vect	vector;
	int fd;

	fd = open (argv[1], O_RDONLY);
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
