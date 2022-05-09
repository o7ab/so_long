/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 23:15:01 by oabushar          #+#    #+#             */
/*   Updated: 2022/04/28 21:10:56 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	maplength(t_map *spec)
{
	int	i;

	i = 0;
	while (spec->split[i] != 0)
	{
		if (ft_strlen(spec->split[i]) != ft_strlen(spec->split[0]))
			return (0);
		i++;
	}
	return (1);
}

int	getheight(t_map *spec)
{
	int	i;

	i = 0;
	if (!spec->split[i])
		return (0);
	while (spec->split[i] != 0)
		i++;
	return (i);
}

int	checkchar(char c)
{
	if (c == 'P' || c == 'C' || c == 'E' || c == '1' || c == '0')
		return (1);
	else
		return (0);
}

t_map	*ft_assign(t_map *spec)
{
	spec->collectable = 0;
	spec->start = 0;
	spec->ex = 0;
	spec->height = getheight(spec);
	spec->x = 0;
	spec->y = 0;
	spec->w = ft_strlen(spec->split[0]) * 75;
	spec->h = spec->height * 75;
	spec->px = getx(spec);
	spec->counter = 1;
	return (spec);
}

int	begin(t_map *spec, int k)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (spec->split[0][j] != 0)
	{
		if (spec->split[0][j] != '1')
			return (0);
		j++;
	}
	while (spec->split[k][i] != 0)
	{
		if (spec->split[k][i] != '1')
			return (0);
		i++;
	}
	return (1);
}
