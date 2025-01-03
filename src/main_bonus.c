/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:14:04 by ninomiyakei       #+#    #+#             */
/*   Updated: 2024/12/24 13:29:17 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc >= 5)
	{
		pipex.argc = argc;
		pipex.argv = argv;
		pipex.envp = envp;
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			if (argc < 6)
				print_error(1,
					"Usage: ./pipex here_doc LIMITER cmd1 cmd2 ... outfile\n");
			pipex_multi_here_doc(&pipex);
		}
		else
			pipex_multi(&pipex);
	}
	else
		print_error(1, "Usage: ./pipex file1 cmd1 cmd2 ... file2\n");
	return (0);
}
