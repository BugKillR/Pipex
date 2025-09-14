/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:22:54 by kkeskin           #+#    #+#             */
/*   Updated: 2025/06/10 15:38:12 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	ft_freeall(char **split, size_t k)
{
	while (0 < k)
		free(split[--k]);
	free(split);
}

static size_t	ft_separate(char **split, char const *s, char c, size_t *k)
{
	size_t	i;
	size_t	start;

	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			split[*k] = ft_substr(s, start, i - start);
			if (!split[*k])
			{
				ft_freeall(split, *k);
				return (0);
			}
			(*k)++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	k;

	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!split)
		return (NULL);
	k = 0;
	if (!ft_separate(split, s, c, &k))
		return (NULL);
	split[k] = NULL;
	return (split);
}
