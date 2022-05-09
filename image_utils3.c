/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 23:06:29 by oabushar          #+#    #+#             */
/*   Updated: 2022/05/05 23:07:21 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collect_up(t_map *spec)
{
	if (spec->split[spec->py - 1][spec->px] == 'C')
	{
		spec->split[spec->py - 1][spec->px] = '0';
		spec->collectable -= 1;
		return ;
	}
}

void	ft_collect_left(t_map *spec)
{
	if (spec->split[spec->py][spec->px - 1] == 'C')
	{
		spec->split[spec->py][spec->px - 1] = '0';
		spec->collectable -= 1;
		return ;
	}
}

void	ft_collect_right(t_map *spec)
{
	if (spec->split[spec->py][spec->px + 1] == 'C')
	{
		spec->split[spec->py][spec->px + 1] = '0';
		spec->collectable -= 1;
		return ;
	}
}
