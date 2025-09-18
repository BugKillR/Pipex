/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputfile_to_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 04:55:27 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/17 04:55:28 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	h_inputfile_to_pipe(char *argv[])
{
	char	*read;
	int		fd[2];
	char	*delimiter;

	delimiter = argv[2];
	pipe(fd);
	read = get_next_line(0);
	while (read && (ft_strlen(read) - 1 != ft_strlen(delimiter)
			|| ft_strncmp(read, delimiter, ft_strlen(delimiter)) != 0))
	{
		write(fd[1], read, ft_strlen(read));
		free(read);
		read = get_next_line(0);
	}
	if (read)
		free(read);
	close(fd[1]);
	return (fd[0]);
}

int	c_inputfile_to_pipe(char *argv[])
{
	char	*read;
	int		inputfile;
	int		fd[2];

	pipe(fd);
	if (access(argv[1], F_OK) != 0)
		close(fd[1]);
	else if (access(argv[1], X_OK | R_OK) != 0)
		exit(0);
	else
	{
		inputfile = open(argv[1], O_RDONLY);
		read = get_next_line(inputfile);
		while (read)
		{
			write(fd[1], read, ft_strlen(read));
			free(read);
			read = get_next_line(inputfile);
		}
		close(inputfile);
		close(fd[1]);
	}
	return (fd[0]);
}
