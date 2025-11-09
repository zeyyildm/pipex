/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:25:35 by zeyildir          #+#    #+#             */
/*   Updated: 2025/11/09 17:13:28 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft/libft.h"

char	*get_paths(char **env);
char	**get_split_paths(char *path);
char	**get_commands(char *cmd);
char	*find_real_path(char **paths, char *cmd);
void	child_process(char *path, char **arg, char **cmd, int *fd);
void	parent_process(char *path, char **arg, char **cmd, int *fd);

#endif
