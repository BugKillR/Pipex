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

t_exec_data	execve_setup(char *argv[], char *envp[], int *index)
{
	t_exec_data	data;
	char		*all_paths;

	data.flags = get_flags(argv, *index);
	data.cmd = data.flags[0];
	all_paths = all_paths_from_envp(envp);
	data.pathname = find_pathname_for_command(all_paths, data.cmd);
	if (data.pathname == NULL)
	{
		ft_putstr_fd("Invalid pathname! Perhaps it caused of typo in commands!\n", 2);
		free_double_chr(data.flags);
		exit(2);
	}
	(*index)++;
	return (data);
}
