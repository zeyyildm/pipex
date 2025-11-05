#include "pipex.h"

char *get_paths(char **env)
{
    int i;

    i = 0;
    while (env)
    {
        if(ft_strncmp(env[i], "PATH=", 5) == 0)
            return (env[i] + 5); //pathin geri kalanını döndürsün
        i++;
    }
    exit(1); //veya hata mı döndürürüm?
}

char **get_split_paths(char *path)
{
    char	**tmp;

	tmp = ft_split(path, ':');
	return (tmp);
}