#include "pipex.h"

void	child_process(char **arg, int *fd)
{
	int	in_fd;

	in_fd = open(arg[1], O_RDONLY, 0644);
	if (in_fd == -1)
		write(2, "Error\n", 6);
	dup2(in_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(in_fd);
}

void	parent_process(char **arg, int *fd)
{
	int	o_fd;

	o_fd = open(arg[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (o_fd == -1)
		write(2, "Error\n", 6);
	dup2(fd[0], STDIN_FILENO);
	dup2(o_fd, STDOUT_FILENO);
	close(fd[1]);
	close(o_fd);
}

