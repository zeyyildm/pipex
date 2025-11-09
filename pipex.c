/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:18:57 by zeyildir          #+#    #+#             */
/*   Updated: 2025/11/09 20:05:22 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;
	char	*paths;
	char	**find_cmd;
	char	**find2_cmd;
	char	*exc_path;
	char	*exc2_path;

	if (ac == 5)
	{
		null_check(av);
		paths = get_paths(env);
		find_cmd = get_commands(av[2]);
		find2_cmd = get_commands(av[3]);
		if (!find_cmd || !find_cmd[0])
		{
			write(2, "Error\n", 7);
		}
		else
		{
			exc_path = find_real_path(get_split_paths(paths), find_cmd[0]);
		}
		if (!find2_cmd || !find2_cmd[0])
		{
			write(2, "Error: Command not found\n", 26);
		}
		else
		{
			exc2_path = find_real_path(get_split_paths(paths), find2_cmd[0]);
		}
		pipe(fd);
		pid = fork();
		if (pid == -1)
			write(2, "Error\n", 7);
		if (pid == 0)
		{
			if (find_cmd[0] != NULL)
				child_process(exc_path, av, find_cmd, fd);
		}
		else if (pid > 0)
		{
			waitpid(pid, NULL, 0);
			parent_process(exc2_path, av, find2_cmd, fd);
		}
	}
	else
		write(2, "Error\n", 7);
	return (0);
}
