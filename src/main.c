/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyakei <ninomiyakei@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:14:04 by ninomiyakei       #+#    #+#             */
/*   Updated: 2024/11/26 18:37:26 by ninomiyakei      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char *infile_str, char *cmds_str, int pipe_fd[2],
		char **envp)
{
	int		infile;
	char	**cmds;

	infile = open(infile_str, O_RDONLY);
	if (infile == -1)
		print_error(1, "pipex: %s: No such file or directory\n", infile_str);
	cmds = split_command(cmds_str);
	close(pipe_fd[0]);
	dup2(infile, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	execute(cmds, envp);
}

void	parent_process(char *outfile_str, char *cmds_str, int pipe_fd[2],
		char **envp)
{
	int		outfile;
	char	**cmds;

	outfile = open(outfile_str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		print_error(1, "Error opening outfile");
	cmds = split_command(cmds_str);
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipe_fd[0]);
	execute(cmds, envp);
}

void	ft_printstr(const char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	print_error(int exit_code, const char *fmt, ...)
{
	va_list	args;
	char	*str;
	char	*ptr;

	va_start(args, fmt);
	ptr = (char *)fmt;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == 's')
			{
				str = va_arg(args, char *);
				if (str)
					ft_printstr(str);
			}
		}
		else
			write(2, ptr, 1);
		ptr++;
	}
	va_end(args);
	exit(exit_code);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc != 5)
		print_error(1, "argc error");
	if (pipe(pipe_fd) == -1)
		print_error(1, "pipe error");
	pid = fork();
	if (pid == -1)
		print_error(1, "fork error");
	else if (pid == 0)
		child_process(argv[1], argv[2], pipe_fd, envp);
	else
	{
		parent_process(argv[4], argv[3], pipe_fd, envp);
		waitpid(pid, NULL, 0);
	}
	return (0);
}
