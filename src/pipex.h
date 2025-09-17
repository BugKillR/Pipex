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
# include <stdio.h>
# include "../Libft/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_exec_data
{
	char	*pathname;
	char	*cmd;
	char	**flags;
	char	*outputfile;
}				t_exec_data;

//	----- Main Function -----

void		pipex(int argc, char *argv[], char *envp[]);

//	----- Decider Functions -----
// >> Decides whether to run pipex in here_doc mode or classic mode.
// >> Each function sets the starting index for the first command in argv.
// >> Then calls execute_commands() with that index.

void		here_doc(int argc, char *argv[], char *envp[]);
void		classic(int argc, char *argv[], char *envp[]);

/*	 ----- 		Command Executer Function(s)	-----
						   &&
	----- Decider Functions for Input Output Files -----

>> Output files: open() flags differ
- classic: O_CREAT | O_WRONLY | O_TRUNC (truncate file)
- here_doc: O_CREAT | O_WRONLY | O_APPEND (append to file)

>> Input files: first pipe input differs
- classic: read from argv[1] (regular input file)
- here_doc: read lines from stdin until delimiter and use temp file/pipe
*/

void		execute_commands(int argc, char *argv[], char *envp[], int *index);
int			decide_outputfile_settings(int argc, char *argv[], int index);
int			decide_inputfile_heredoc_or_classic(int index, char *argv[]);
int			c_inputfile_to_pipe(char *argv[]);
int			h_inputfile_to_pipe(char *argv[]);

// ----- Executive Setup (t_exec_data builder functions) -----
// >> These functions build the t_exec_data struct for each command.
// >> They extract command flags from argv, search for its full path in $PATH,
// >>and prepare all data needed before calling execve().

t_exec_data	execve_setup(char *argv[], char *envp[], int *index);
char		*all_paths_from_envp(char *envp[]);
char		*find_pathname_for_command(char *all_paths, char *cmd);
char		**get_flags(char *argv[], int i);

//	----- Free Functions :) -----

void		free_double_chr(char **d_c);
void		free_data(t_exec_data data);

#endif