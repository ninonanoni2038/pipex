/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_multi_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:37:24 by ninomiyasat       #+#    #+#             */
/*   Updated: 2024/12/24 11:55:48 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_multi(t_pipex *pipex)
{
	int	num_commands;
	int	**pipe_fd;

	num_commands = pipex->argc - 3;
	init_pipes(&pipe_fd, num_commands);
	execute_process(num_commands, &pipe_fd, pipex);
	close_pipes(&pipe_fd, num_commands);
	free_pipes(&pipe_fd, num_commands);
	while (wait(NULL) > 0)
		;
}

void	pipex_multi_here_doc(t_pipex *pipex)
{
	int	num_commands;
	int	**pipe_fd;

	num_commands = pipex->argc - 4;
	init_pipes(&pipe_fd, num_commands);
	execute_process_here_doc(num_commands, &pipe_fd, pipex);
	close_pipes(&pipe_fd, num_commands);
	free_pipes(&pipe_fd, num_commands);
	while (wait(NULL) > 0)
		;
}
