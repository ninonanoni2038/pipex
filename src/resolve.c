/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyakei <ninomiyakei@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:33:25 by ninomiyakei       #+#    #+#             */
/*   Updated: 2024/11/26 19:05:50 by ninomiyakei      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_default_paths(char *cmd)
{
	const char	*default_paths[] = {"/bin", "/usr/bin", NULL};
	char		*full_path;
	int			i;

	i = 0;
	while (default_paths[i])
	{
		full_path = malloc(ft_strlen(default_paths[i]) + ft_strlen(cmd) + 2);
		if (!full_path)
			return (NULL);
		ft_strcpy(full_path, default_paths[i]);
		ft_strcat(full_path, "/");
		ft_strcat(full_path, cmd);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*get_path_env(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

char	*resolve_absolute_path(char *cmd)
{
	if (access(cmd, F_OK) == 0)
	{
		if (access(cmd, X_OK) == 0)
			return (cmd);
		else
			print_error(126, "pipex: permission denied: %s\n", cmd);
	}
	print_error(127, "pipex: no such file or directory: %s\n", cmd);
	return (NULL);
}

char	*resolve_from_path_env(char *cmd, char **envp)
{
	char	**path_dirs;
	char	*path_dir;
	int		i;
	char	*cmd_full_path;

	path_dirs = ft_split(get_path_env(envp), ':');
	i = 0;
	while (path_dirs[i])
	{
		path_dir = ft_strjoin(path_dirs[i], "/");
		cmd_full_path = ft_strjoin(path_dir, cmd);
		if (access(cmd_full_path, X_OK) == 0)
		{
			return (cmd_full_path);
		}
		i++;
	}
	return (NULL);
}

char	*get_fullpath(char *cmds[], char **envp)
{
	if (ft_strchr(cmds[0], '/'))
		return (resolve_absolute_path(cmds[0]));
	if (!envp || !*envp)
		return (check_default_paths(cmds[0]));
	else
		return (resolve_from_path_env(cmds[0], envp));
}
