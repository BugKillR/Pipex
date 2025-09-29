/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 03:35:21 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/16 03:35:21 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_flags(char *argv[], int index)
{
	char	**flags;

	if (argv[index][0] == '\0')
	{
		perror("Null command");
		exit(1);
	}
	flags = ft_split(argv[index], ' ');
	return (flags);
}
