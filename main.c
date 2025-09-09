#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];

	pipe(fd);
	pid1 = fork();
	if (pid1 == -1)
		perror("Can't fork!\n");
	if (pid1 == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execve("/usr/bin/ls", (char *[]){"ls", "-l", NULL}, NULL);
		perror("Execute not worked!\n");
	}
	
	pid2 = fork();
	if (pid2 == -1)
		perror("Can't fork!\n");
	if (pid2 == 0)
	{
		dup2(fd[0], 0);
		close(fd[1]);
		close(fd[0]);
		execve("/usr/bin/wc", (char *[]){"wc", "-l", NULL}, NULL);
		perror("Execute not worked!\n");
	}
	close(fd[0]);
	close(fd[1]);
    return (0);
}