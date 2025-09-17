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

static int	inputfile_to_pipe(char *argv[])
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
		exit(1);
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

static void	last_process_before_output(t_exec_data data,
	char *envp[], int input, int output)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		child_process(data, envp, input, output);
	else
	{
		close(input);
		close(output);
		free_data(data);
		waitpid(pid, NULL, 0);
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

	if (*index == 3)
		printf("Test\n");
	else if (*index == 2)
		inputfile = inputfile_to_pipe(argv);
	while (*index < argc - 2)
	{
		pipe(fd);
		data = execve_setup(argv, envp, index);
		pid = fork();
		if (pid == 0)
			child_process(data, envp, inputfile, fd[1]);
		else
			get_next_command(data, fd, &inputfile, index);
	}
	outputfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outputfile < 0)
		exit(1);
	data = execve_setup(argv, envp, index);
	last_process_before_output(data, envp, inputfile, outputfile);
}
