/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:42:47 by ninomiyasat       #+#    #+#             */
/*   Updated: 2024/12/24 13:30:03 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_input_to_pipe(t_pipex *pipex, int ***pipe_fd, int i)
{
	int	infile;

	infile = open(pipex->argv[1], O_RDONLY);
	if (infile == -1)
		print_error(1, "pipex: %s: No such file or directory\n",
			pipex->argv[1]);
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2((*pipe_fd)[i][1], STDOUT_FILENO);
	close((*pipe_fd)[i][1]);
}

void	redirect_input_to_pipe_here_doc(char *delimiter, int ***pipe_fd, int i)
{
	char	*line;
	int		here_doc_pipe[2];

	if (pipe(here_doc_pipe) == -1)
		print_error(1, "pipex: here_doc: pipe error\n");
	while (1)
	{
		write(STDOUT_FILENO, "here_doc> ", 10);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0
			&& line[ft_strlen(delimiter)] == '\n')
		{
			free(line);
			break ;
		}
		write(here_doc_pipe[1], line, ft_strlen(line));
		free(line);
	}
	close(here_doc_pipe[1]);
	dup2(here_doc_pipe[0], STDIN_FILENO);
	close(here_doc_pipe[0]);
	dup2((*pipe_fd)[i][1], STDOUT_FILENO);
	close((*pipe_fd)[i][1]);
}

void	redirect_pipe_to_output(t_pipex *pipex, int ***pipe_fd, int i)
{
	int	outfile;

	outfile = open(pipex->argv[pipex->argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
			0644);
	if (outfile == -1)
		print_error(1, "Error opening outfile");
	dup2((*pipe_fd)[i - 1][0], STDIN_FILENO);
	close((*pipe_fd)[i - 1][0]);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
}

void	redirect_pipe_to_pipe(int ***pipe_fd, int i)
{
	dup2((*pipe_fd)[i - 1][0], STDIN_FILENO);
	close((*pipe_fd)[i - 1][0]);
	dup2((*pipe_fd)[i][1], STDOUT_FILENO);
	close((*pipe_fd)[i][1]);
}
