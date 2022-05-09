/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:38:14 by oabushar          #+#    #+#             */
/*   Updated: 2022/04/28 21:24:03 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collectcheck(t_map *spec)
{
	int	i;
	int	j;

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
		return (0);
	return (1);
}

int	wallcheck(t_map *spec)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	spec = ft_assign(spec);
	k = spec->height - 1;
	if (begin(spec, k) == 0)
		return (0);
	i = 0;
	while (spec->split[i])
	{
		if (spec->split[i][0] != '1' ||
			spec->split[i][ft_strlen(spec->split[i]) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_maphelp(char *ret, t_map *spec, int fd)
{
	if (!ret || !ret[0])
		return (0);
	spec->split = ft_split(ret, '\n');
	if (!spec->split)
		return (0);
	if (maplength(spec) == 0)
		return (0);
	if (wallcheck(spec) == 0)
		return (0);
	if (collectcheck(spec) == 0)
		return (0);
	close (fd);
	return (1);
}

void	freeline(char *ret, char *line, int fd)
{
	if (ret)
		free(ret);
	free (line);
	close (fd);
}

int	ft_maphandle(char *str, t_map *spec)
{
	char	*lines;
	char	*ret;
	int		fd;

	if (ft_strstr(str, ".ber") == 0)
		return (0);
	fd = open (str, O_RDONLY);
	ret = NULL;
	while (1)
	{
		lines = get_next_line(fd);
		if (!lines)
			break ;
		if (lines[0] == '\n')
		{
			freeline(ret, lines, fd);
			return (0);
		}
		ret = ft_strjoin(ret, lines);
		free (lines);
	}
	if (ft_maphelp(ret, spec, fd) == 0)
		return (0);
	return (1);
}
