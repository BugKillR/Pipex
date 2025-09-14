/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:45:01 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/14 18:45:01 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_realloc(char **ptr1, char *ptr2)
{
	char	*temp;

	if (!ptr2)
		return ;
	if (!*ptr1)
		temp = ft_strdup(ptr2);
	else
		temp = ft_strjoin(*ptr1, ptr2);
	if (!temp)
	{
		return ;
	}
	free(*ptr1);
	*ptr1 = temp;
}
