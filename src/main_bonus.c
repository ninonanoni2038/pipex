/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyakei <ninomiyakei@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:14:04 by ninomiyakei       #+#    #+#             */
/*   Updated: 2024/12/19 18:53:14 by ninomiyakei      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	*get_next_line(int fd)
{
	char	*line;
	char	buffer;
	int		i;
	int		read_bytes;

	line = (char *)malloc(10000);
	if (!line)
		return (NULL);
	i = 0;
	read_bytes = read(fd, &buffer, 1);
	while (read_bytes > 0)
	{
		line[i++] = buffer;
		if (buffer == '\n')
			break ;
		read_bytes = read(fd, &buffer, 1);
	}
	line[i] = '\0';
	if (read_bytes <= 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

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

void	wait_for_children_here_doc(int num_commands)
{
	int	i;
	int	status;
	int	last_exit_code;

	i = 0;
	last_exit_code = 0;
	while (i < num_commands)
	{
		if (wait(&status) == -1)
			print_error(1, "wait error");
		if (WIFEXITED(status))
			last_exit_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			last_exit_code = 128 + WTERMSIG(status);
		i++;
	}
	exit(last_exit_code);
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
	wait_for_children_here_doc(num_commands);
}

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
