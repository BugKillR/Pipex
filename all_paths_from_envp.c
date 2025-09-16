/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_paths_from_envp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 03:31:09 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/16 03:31:09 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*all_paths_from_envp(char *envp[])
{
	char	*path;
	int		i;

	i = 0;
	while (envp[i])
	{
		path = ft_strnstr(envp[i], "PATH=", 5);
		if (path != NULL)
			return (path + 5);
		i++;
	}
	perror("Cannot find \"PATH=\"");
	return (exit(2), NULL);
}
