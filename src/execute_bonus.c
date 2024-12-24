/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:49:44 by ninomiyasat       #+#    #+#             */
/*   Updated: 2024/12/24 13:41:44 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_command(t_pipex *pipex, int i)
{
	char	**cmds;
	char	*pathname;

	cmds = split_command(pipex->argv[i + 2]);
	if (!cmds || !cmds[0])
		print_error(127, "pipex: : command not found\n");
	pathname = get_fullpath(cmds, pipex->envp);
	if (!pathname)
		print_error(127, "pipex: %s: command not found\n", cmds[0]);
	if (execve(pathname, cmds, pipex->envp) == -1)
	{
		if (errno == EACCES)
			print_error(126, "pipex: permission denied: %s\n", cmds[0]);
		else
			print_error(127, "pipex: %s: command not found\n", cmds[0]);
	}
}

void	execute_command_here_doc(t_pipex *pipex, int i)
{
	char	**cmds;
	char	*pathname;

	cmds = split_command(pipex->argv[i + 3]);
	if (!cmds || !cmds[0])
		print_error(127, "pipex: : command not found\n");
	pathname = get_fullpath(cmds, pipex->envp);
	if (!pathname)
		print_error(127, "pipex: %s: command not found\n", cmds[0]);
	if (execve(pathname, cmds, pipex->envp) == -1)
	{
		if (errno == EACCES)
			print_error(126, "pipex: permission denied: %s\n", cmds[0]);
		else
			print_error(127, "pipex: %s: command not found\n", cmds[0]);
	}
}

void	execute_process(int num_commands, int ***pipe_fd, t_pipex *pipex)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < num_commands)
	{
		pid = fork();
		if (pid == -1)
			print_error(1, "fork error");
		if (pid == 0)
			handle_child_process(num_commands, pipe_fd, pipex, i);
		i++;
	}
	close_pipes(pipe_fd, num_commands);
	exit(wait_for_children(num_commands));
}

void	execute_process_here_doc(int num_commands, int ***pipe_fd,
		t_pipex *pipex)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < num_commands)
	{
		pid = fork();
		if (pid == -1)
			print_error(1, "fork error");
		if (pid == 0)
		{
			handle_child_here_doc(pipe_fd, num_commands, pipex, i);
		}
		i++;
	}
	close_pipes(pipe_fd, num_commands);
	exit(wait_for_children(num_commands));
}
