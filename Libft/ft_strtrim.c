/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:27:38 by kkeskin           #+#    #+#             */
/*   Updated: 2025/06/10 15:27:38 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_compare(char c, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(set);
	while (i < len)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmedstr;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_compare(s1[start], set))
		start++;
	while (end > start && ft_compare(s1[end - 1], set))
		end--;
	trimmedstr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!trimmedstr)
		return (trimmedstr);
	ft_strlcpy(trimmedstr, s1 + start, end - start + 1);
	return (trimmedstr);
}
