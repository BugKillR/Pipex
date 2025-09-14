/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:20:15 by kkeskin           #+#    #+#             */
/*   Updated: 2025/06/10 14:20:15 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit(long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

static void	ft_convert(int *i, long nb, char *str)
{
	if (nb >= 10)
		ft_convert(i, nb / 10, str);
	str[*i] = (nb % 10) + '0';
	(*i)++;
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;
	int		i;

	nb = n;
	len = ft_digit(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	i = 0;
	if (nb < 0)
	{
		str[0] = '-';
		i = 1;
		nb *= -1;
	}
	ft_convert(&i, nb, str);
	return (str);
}
