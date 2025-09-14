/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:25:50 by kkeskin           #+#    #+#             */
/*   Updated: 2025/06/10 15:25:51 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_append(char *newstr, char const *s, size_t *i)
{
	size_t	k;

	k = 0;
	while (s[(k)])
		newstr[(*i)++] = s[k++];
}

static size_t	ft_appendlen(char const *s1, char const *s2)
{
	return (ft_strlen(s1) + ft_strlen(s2));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	newstr = (char *)malloc(ft_appendlen(s1, s2) + 1);
	if (!newstr)
		return (NULL);
	i = 0;
	ft_append(newstr, s1, &i);
	ft_append(newstr, s2, &i);
	newstr[i] = '\0';
	return (newstr);
}
