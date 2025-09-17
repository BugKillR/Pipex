/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pathname_for_command.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 03:28:40 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/16 03:28:40 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*search_for_cmd_path(char **paths, char *cmd)
{
	char	*real_path;
	char	*add_slash;
	int		i;

	i = 0;
	while (paths[i])
	{
		add_slash = ft_strjoin(paths[i], "/");
		if (!add_slash)
			return (NULL);
		real_path = ft_strjoin(add_slash, cmd);
		free(add_slash);
		if (!real_path)
			return (NULL);
		if (access(real_path, X_OK) == 0)
			return (real_path);
		free(real_path);
		i++;
	}
	return (NULL);
}

char	*find_pathname_for_command(char *all_paths, char *cmd)
{
	char	**paths;
	char	*real_path;

	paths = ft_split(all_paths, ':');
	if (!paths)
	{
		return (NULL);
	}
	real_path = search_for_cmd_path(paths, cmd);
	free_double_chr(paths);
	return (real_path);
}
