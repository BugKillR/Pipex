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

// static void	check_flags(char **flags)
// {
// 	int	i;
// 
// 	i = 1;
// 	while (flags[i])
// 	{
// 		if (ft_strncmp("-", flags[i], 1) != 0)
// 		{
// 			free_double_chr(flags);
// 			ft_putstr_fd("Wrong flag!\n", 2);
// 			exit(2);
// 		}
// 		i++;
// 	}
// }

char	**get_flags(char *argv[], int index)
{
	char	**flags;

	flags = ft_split(argv[index], ' ');
	//// check_flags(flags);
	return (flags);
}
