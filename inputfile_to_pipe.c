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

int	inputfile_to_pipe(char *argv[])
{
	char	*read;
	int		inputfile;
	int		fd[2];

	if (pipe(fd) == -1)
	{
		ft_putstr_fd("Pipe failed on inputfile_to_pipe funct!\n", 2);
		exit(1);
	}
	if (access(argv[1], F_OK) != 0)
	{
		ft_putstr_fd("Give an input file!\n", 2);
		exit(0);
	}
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
	return (fd[0]);
}
