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

// path bulma OK
// komutu alma ve flagleri ayırma KO
// heredoc'a uygun şekilde çalışma KO
// multiple-pipe kullanımı KO

void	here_doc(char *argv[], char *envp[])
{
	t_exec_data	data;

	(void)argv;
	data = execve_setup(envp, "ip");
	(void)data;
	return ;
}
