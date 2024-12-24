/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyakei <ninomiyakei@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:34:44 by ninomiyakei       #+#    #+#             */
/*   Updated: 2024/11/26 19:04:56 by ninomiyakei      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *cmds[], char **envp)
{
	char	*pathname;

	pathname = get_fullpath(cmds, envp);
	if (pathname == NULL)
		print_error(127, "pipex: %s: command not found\n", cmds[0]);
	if (execve(pathname, cmds, envp) == -1)
	{
		if (errno == EACCES)
			print_error(126, "pipex: permission denied: %s\n", cmds[0]);
		perror("syntax error at source line 1");
		exit(2);
	}
}
