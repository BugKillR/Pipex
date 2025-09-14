/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:27:27 by kkeskin           #+#    #+#             */
/*   Updated: 2025/06/10 15:27:28 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;

	slen = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)&s[slen]);
	while (slen)
	{
		slen--;
		if (s[slen] == (char)c)
			return ((char *)&s[slen]);
	}
	return (NULL);
}
