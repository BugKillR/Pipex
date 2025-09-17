/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:00:23 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/22 00:00:24 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*str;
	size_t	i;

	i = 0;
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	str = (char *)ptr;
	while (i < nmemb * size)
	{
		str[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(ft_strlen(s) + 1);
	if (!ptr)
		return (NULL);
	i = -1;
	while (s[++i])
		ptr[i] = s[i];
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	k;

	if (!s1 || !s2)
		return (NULL);
	newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (NULL);
	i = 0;
	k = 0;
	while (s1[k])
		newstr[i++] = s1[k++];
	k = 0;
	while (s2[k])
		newstr[i++] = s2[k++];
	newstr[i] = '\0';
	return (newstr);
}
