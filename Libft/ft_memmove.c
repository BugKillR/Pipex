/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:21:52 by kkeskin           #+#    #+#             */
/*   Updated: 2025/06/10 14:21:53 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned const char	*s;
	unsigned char		*d;

	if (!dest && !src)
		return (NULL);
	s = (unsigned const char *)src;
	d = (unsigned char *)dest;
	if (d < s)
		return (ft_memcpy(dest, src, n));
	else
		while (n--)
			d[n] = s[n];
	return (dest);
}
