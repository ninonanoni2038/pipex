/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:41:56 by ninomiyasat       #+#    #+#             */
/*   Updated: 2024/12/24 11:45:18 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipes(int ***pipe_fd, int num_commands)
{
	int	i;

	i = 0;
	*pipe_fd = malloc(sizeof(int *) * (num_commands - 1));
	if (!*pipe_fd)
	{
		perror("malloc error");
		exit(1);
	}
	while (i < num_commands - 1)
	{
		(*pipe_fd)[i] = malloc(sizeof(int) * 2);
		if (!(*pipe_fd)[i])
		{
			perror("malloc error");
			exit(1);
		}
		if (pipe((*pipe_fd)[i]) == -1)
		{
			perror("pipe error");
			exit(1);
		}
		i++;
	}
}

void	close_pipes(int ***pipe_fd, int num_commands)
{
	int	i;

	i = 0;
	while (i < num_commands - 1)
	{
		close((*pipe_fd)[i][0]);
		close((*pipe_fd)[i][1]);
		i++;
	}
}

void	free_pipes(int ***pipe_fd, int num_commands)
{
	int	i;

	i = 0;
	while (i < num_commands - 1)
	{
		free((*pipe_fd)[i]);
		i++;
	}
	free(*pipe_fd);
}

void	close_unused_pipes(int num_commands, int ***pipe_fd, int current)
{
	int	j;

	j = 0;
	while (j < num_commands - 1)
	{
		if (j != current - 1)
			close((*pipe_fd)[j][0]);
		if (j != current)
			close((*pipe_fd)[j][1]);
		j++;
	}
}

void	close_unused_pipes_here_doc(int ***pipe_fd, int num_commands, int i)
{
	int	j;

	j = 0;
	while (j < num_commands - 1)
	{
		if (j != i - 1)
			close((*pipe_fd)[j][0]);
		if (j != i)
			close((*pipe_fd)[j][1]);
		j++;
	}
}
