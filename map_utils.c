/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:38:14 by oabushar          #+#    #+#             */
/*   Updated: 2022/03/31 09:06:25 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	maplength(t_map spec)
{
	int i;

	i = 0;
	while (spec.split[i] != 0)
	{
		if (ft_strlen(spec.split[i]) != ft_strlen(spec.split[0]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_assign()
{
	t_map spec;

	spec.collectable = 0;
	spec.start = 0;
	spec.ex = 0;
	spec.height = getheight(spec);
}

int	getheight(t_map spec)
{
	int i;

	i = 0;
	if (!spec.split[i])
		return 0;
	while (spec.split[i] != 0)
		i++;
	return (i);
}

// int	wallcheck(t_map spec)
// {
// 	while (spec.height != 0)
// 	{
// 		if (spec.split[spec.height][0] != 1 && spec.split[spec.height][ft_strlen(spec.split[i])] != 1)
// 			return (0);
// 		spec.height--;
// 	}
// 	while (spec.split[i] != 0)
// }

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
	char *lines;
	t_map spec; 
	char *ret;

	if (ft_strstr(str, ".ber") == 0)
		return (0);
	lines = NULL;
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
	spec.split = ft_split(ret, '\n');
	if (maplength(spec) == 0)
		return (0);
	// if (wallcheck(spec) == 0)
	return (1);
}
