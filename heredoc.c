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

	index = 3;
	execute_commands(argc, argv, envp, &index);
	return ;
}
