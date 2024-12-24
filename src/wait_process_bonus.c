/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_process_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:46:04 by ninomiyasat       #+#    #+#             */
/*   Updated: 2024/12/24 13:41:50 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	wait_for_children(int num_commands)
{
	int	i;
	int	status;
	int	exit_status;

	i = 0;
	exit_status = 0;
	while (i < num_commands)
	{
		if (waitpid(-1, &status, 0) == -1)
			print_error(1, "waitpid error");
		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
		i++;
	}
	return (exit_status);
}

// void	wait_for_children_here_doc(int num_commands)
// {
// 	int	i;
// 	int	status;
// 	int	last_exit_code;

// 	i = 0;
// 	last_exit_code = 0;
// 	while (i < num_commands)
// 	{
// 		if (wait(&status) == -1)
// 			print_error(1, "wait error");
// 		if (WIFEXITED(status))
// 			last_exit_code = WEXITSTATUS(status);
// 		else if (WIFSIGNALED(status))
// 			last_exit_code = 128 + WTERMSIG(status);
// 		i++;
// 	}
// 	exit(last_exit_code);
// }
