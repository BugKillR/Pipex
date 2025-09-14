#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h> // perror
#include "./Libft/libft.h"

void	pipex(int argc, char *argv[], char *envp[]);

#endif