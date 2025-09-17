/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 04:05:15 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/17 04:05:16 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process(t_exec_data data, char **envp, int input, int output)
{
	if (dup2(input, 0) == -1)
		perror("Dup2 input error!\n");
	if (dup2(output, 1) == -1)
		perror("Dup2 output error!\n");
	close(input);
	close(output);
	execve(data.pathname, data.flags, envp);
	perror("Execve failed!\n");
	exit(1);
}

static void	check_if_output_empty(t_exec_data data)
{
	char	*read;
	int		fd;

	fd = open(data.outputfile, O_RDONLY);
	read = get_next_line(fd);
	if (!read && access(data.outputfile, F_OK | X_OK) != 0)
	{
		free_data(data);
		exit(1);
	}
	else
	{
		while (read)
		{
			free(read);
			read = get_next_line(fd);
		}
	}
}

static void	last_process_before_output(t_exec_data data,
	char *envp[], int input, int output)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		child_process(data, envp, input, output);
	else
	{
		waitpid(pid, NULL, 0);
		check_if_output_empty(data);
		close(input);
		close(output);
		free_data(data);
	}
}

static void	get_next_command(t_exec_data data,
	int *pipe_fd, int *input, int *index)
{
	close(pipe_fd[1]);
	close(*input);
	*input = pipe_fd[0];
	free_data(data);
	(*index)++;
}

void	execute_commands(int argc, char *argv[], char *envp[], int *index)
{
	t_exec_data	data;
	int			inputfile;
	int			outputfile;
	int			fd[2];
	pid_t		pid;

	outputfile = decide_outputfile_settings(argc, argv, *index);
	inputfile = decide_inputfile_heredoc_or_classic(*index, argv);
	while (*index < argc - 2)
	{
		pipe(fd);
		data = execve_setup(argv, envp, index);
		pid = fork();
		if (pid == 0)
			child_process(data, envp, inputfile, fd[1]);
		else
		{
			waitpid(pid, NULL, 0);
			get_next_command(data, fd, &inputfile, index);
		}
	}
	data = execve_setup(argv, envp, index);
	last_process_before_output(data, envp, inputfile, outputfile);
}
