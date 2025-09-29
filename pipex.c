/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 03:33:28 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/16 03:33:29 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	is_here_doc(char *argv[])
{
	if (!ft_strncmp("here_doc", argv[1], ft_strlen(argv[1])))
		return (1);
	else
		return (0);
}

void	pipex(int argc, char *argv[], char *envp[])
{
	if (argc < 2 || argv[1][0] == '\0')
	{
		ft_putstr_fd("Empty file name!\n", 2);
		exit(2);
	}
	if (is_here_doc(argv))
	{
		if (argc < 6)
		{
			ft_putstr_fd("Invalid argument count!\n", 2);
			exit(2);
		}
		here_doc(argc, argv, envp);
	}
	else
	{
		if (argc < 5)
		{
			ft_putstr_fd("Invalid argument count!\n", 2);
			exit(2);
		}
		classic(argc, argv, envp);
	}
	exit(0);
}
