#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

char	*get_paths(char **env);
char **get_split_paths(char *path);

#endif