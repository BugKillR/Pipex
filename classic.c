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

void	classic(char *argv[], char *envp[])
{
	t_exec_data	data;

	(void)argv;
	data = execve_setup(envp, "ls");
	(void)data;
	return ;
}
