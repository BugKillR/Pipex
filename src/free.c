/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 03:32:25 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/16 03:32:25 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_double_chr(char **d_c)
{
	int	i;

	i = 0;
	while (d_c[i])
	{
		if (d_c[i])
			free(d_c[i]);
		i++;
	}
	if (d_c)
		free(d_c);
}

void	free_data(t_exec_data data)
{
	if (data.pathname)
		free(data.pathname);
	if (data.flags)
		free_double_chr(data.flags);
}
