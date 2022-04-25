/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 08:46:42 by oabushar          #+#    #+#             */
/*   Updated: 2022/04/01 12:39:01 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (to_find[rt + 1] == 0 && str[i + rt + 1] == '\0')
				return (&str[i]);
			++rt;
		}
		++i;
	}
	return (0);
}

static	void	ft_undoalloc(char *s, int i)
{
	while (i >= 0)
	{
		free(&s[i]);
		i--;
	}
	free (s);
}

static	int	ft_worddet(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static	char	*ft_cpystr(char const *s, char c)
{
	size_t	i;
	char	*str;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	while (n < i)
	{
		str[n] = s[n];
		n++;
	}
	str[n] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		wordcount;
	char	**split;

	if (!s)
		return (0);
	wordcount = ft_worddet(s, c);
	split = (((char **) malloc (sizeof(char *) * (wordcount + 1))));
	if (!split)
		return (0);
	i = 0;
	while (i < wordcount)
	{
		while (*s == c)
			s++;
		split[i] = ft_cpystr(s, c);
		if (!split)
			ft_undoalloc(*split, i);
		s += ft_strlen(split[i]);
		i++;
	}
	split[i] = 0;
	return (split);
}