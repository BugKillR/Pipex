/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 03:31:38 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/16 03:31:38 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	classic(int argc, char *argv[], char *envp[])
{
	int			index;

	if (argc < 3)
	{
		ft_putstr_fd("Missing input file or cmd!\n", 2);
		exit(2);
	}
	index = 2;
	execute_commands(argc, argv, envp, &index);
	return ;
}
