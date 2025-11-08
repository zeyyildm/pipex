#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

char	*get_paths(char **env);
char	**get_split_paths(char *path);
char	**get_commands(char *cmd);
char	*find_real_path(char **paths, char *cmd);
void	child_process(char **arg, int *fd);
void	parent_process(char **arg, int *fd);

#endif
