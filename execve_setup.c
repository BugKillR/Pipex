/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 03:31:56 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/16 03:31:57 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_exec_data	execve_setup(char *envp[], char *cmd)
{
	t_exec_data	data;
	char		*all_paths;
	char		*pathname;

	all_paths = all_paths_from_envp(envp);
	pathname = find_pathname_for_command(all_paths, cmd);
	data.pathname = pathname;
	data.cmd = cmd;
	printf("Pathname: %s\nCmd: %s\n", data.pathname, data.cmd);
	if (data.pathname != NULL)
		free(data.pathname);
	return (data);
}
