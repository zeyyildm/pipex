#include "pipex.h"
#include <stdio.h>

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t		pid;
	char	*paths;
	char	**split_paths;
	char	**find_cmd;
	char	*exc_path;

	if (ac == 5)
	{
		paths = get_paths(env);
		split_paths = get_split_paths(paths);
		find_cmd = get_commands(av[2]);
		exc_path = find_real_path(split_paths, find_cmd[0]);
        printf("%s: ", exc_path);
		pipe(fd);
		pid = fork();
        if(pid == -1)
            write(2, "Error\n", 6);
		if (pid == 0)
			child_process(av, fd);
		else
			parent_process(av, fd);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}


