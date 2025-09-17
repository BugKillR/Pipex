/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 03:34:49 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/16 03:34:49 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h> // perror
# include "./Libft/libft.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_exec_data
{
	char	*pathname;
	char	*cmd;
	char	**flags;
	char	*outputfile;
}				t_exec_data;

//	----- Normal Functions -----

void		pipex(int argc, char *argv[], char *envp[]);
void		here_doc(int argc, char *argv[], char *envp[]);
void		classic(int argc, char *argv[], char *envp[]);
char		*all_paths_from_envp(char *envp[]);
char		*find_pathname_for_command(char *all_paths, char *cmd);
t_exec_data	execve_setup(char *argv[], char *envp[], int *index);
char		**get_flags(char *argv[], int i);
void		execute_commands(int argc, char *argv[], char *envp[], int *index);
int			inputfile_to_pipe(char *argv[]);
int			decide_inputfile_heredoc_or_classic(int index, char *argv[]);

//	----- Free Functions -----

void		free_double_chr(char **d_c);
void		free_data(t_exec_data data);

#endif
