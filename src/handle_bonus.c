/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:48:08 by ninomiyasat       #+#    #+#             */
/*   Updated: 2024/12/24 13:30:23 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_child_process(int num_commands, int ***pipe_fd, t_pipex *pipex,
		int i)
{
	close_unused_pipes(num_commands, pipe_fd, i);
	if (i == 0)
		redirect_input_to_pipe(pipex, pipe_fd, i);
	else if (i == num_commands - 1)
		redirect_pipe_to_output(pipex, pipe_fd, i);
	else
		redirect_pipe_to_pipe(pipe_fd, i);
	close_pipes(pipe_fd, num_commands);
	execute_command(pipex, i);
}

void	handle_child_here_doc(int ***pipe_fd, int num_commands, t_pipex *pipex,
		int i)
{
	close_unused_pipes_here_doc(pipe_fd, num_commands, i);
	if (i == 0)
	{
		redirect_input_to_pipe_here_doc(pipex->argv[2], pipe_fd, i);
	}
	else if (i == num_commands - 1)
	{
		redirect_pipe_to_output(pipex, pipe_fd, i);
	}
	else
	{
		redirect_pipe_to_pipe(pipe_fd, i);
	}
	close_pipes(pipe_fd, num_commands);
	execute_command_here_doc(pipex, i);
}
