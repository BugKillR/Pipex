/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 03:32:41 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/16 03:32:41 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(int argc, char *argv[], char *envp[])
{
	int			index;

	if (argc < 4)
	{
		ft_putstr_fd("Delimiter is missing!\n", 2);
		exit(1);
	}
	index = 3;
	execute_commands(argc, argv, envp, &index);
	return ;
}
