#include "pipex.h"

char	*get_paths(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	exit(1);
}

char	**get_split_paths(char *path)
{
	char	**tmp;

	tmp = ft_split(path, ':');
	return (tmp);
}

char	**get_commands(char *cmd)
{
	char	**tmp;

	tmp = ft_split(cmd, ' ');
	return (tmp);
}

char	*find_real_path(char **paths, char *cmd)
{
	int		i;
	char	*joined_path;
	char	*path_with_cmd;

	i = 0;
	while (paths[i])
	{
		joined_path = ft_strjoin(paths[i], "/");
		path_with_cmd = ft_strjoin(joined_path, cmd);
		free(joined_path);
		if (access(path_with_cmd, F_OK | X_OK) == 0)
			return (path_with_cmd);
		free(path_with_cmd);
		i++;
	}
	write(2, "Error\n", 6);
	return (0);
}
