/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:38:14 by oabushar          #+#    #+#             */
/*   Updated: 2022/04/24 05:37:34 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	maplength(t_map *spec)
{
	int i;

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
	int i;

	i = 0;
	if (!spec->split[i])
		return 0;
	while (spec->split[i] != 0)
		i++;
	return (i);
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
	return (spec);
}

int	checkchar(char c)
{
	if (c == 'P' || c == 'C' || c == 'E' || c == '1' || c == '0')
		return (1);
	else
		return (0);
}

int	collectcheck(t_map *spec)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (spec->split[i] != 0)
	{
		while (spec->split[i][j])
		{
			if (spec->split[i][j] == 'C')
				spec->collectable += 1;
			if (spec->split[i][j] == 'E')
				spec->ex += 1;
			if (spec->split[i][j] == 'P')
				spec->start += 1;
			if (checkchar(spec->split[i][j]) == 0)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	if (spec->collectable == 0 || spec->ex != 1 || spec->start != 1)
		return	(0);
	return (1);
}

int	wallcheck(t_map *spec)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	spec = ft_assign(spec);
	k = spec->height - 1;
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
	i = 0;
	while (spec->split[i])
	{
		if (spec->split[i][0] != '1' || spec->split[i][ft_strlen(spec->split[i]) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_maphandle(char *str, int fd, t_map *spec)
{
	char	*lines;
	char	*ret;

	if (ft_strstr(str, ".ber") == 0)
		return (0);
	ret = NULL;
	while (1)
	{
		lines = get_next_line(fd);
		if (!lines)
			break;
		if (lines[0] == '\n')
			return (0);
		ret = ft_strjoin(ret, lines);
		free (lines);
	}
	if (!ret || !ret[0])
		return (0);
	if (ret[ft_strlen(ret) - 1] == '\n')
		return (0);
	spec->split = ft_split(ret, '\n');
	if (maplength(spec) == 0)
		return (0);
	if (wallcheck(spec) == 0)
		return (0);
	if (collectcheck(spec) == 0)
		return (0);
	return (1);
}
