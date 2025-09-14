#include "pipex.h"

static int	is_here_doc(char *argv[])
{
	if (!ft_strncmp("here_doc", argv[1], ft_strlen(argv[1])))
		return (1);
	else
		return (0);
}

void	pipex(int argc, char *argv[], char *envp[])
{
	(void)envp;
	if (argc < 5)
		perror("Invalid argument count!\n");
	if (is_here_doc(argv))
		here_doc(argv, envp);
	else
		classic(argv, envp);
	exit(0);
}
