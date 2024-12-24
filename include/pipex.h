/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:41:10 by ninomiyakei       #+#    #+#             */
/*   Updated: 2024/12/24 13:43:18 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>

// データ構造
typedef struct s_cmd_state
{
	int		count;
	int		in_sq;
	int		in_dq;
	int		word_len;
	char	*word_start;
	int		cmd_index;
}			t_cmd_state;

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
}			t_pipex;

// count_commnad.c
int			count_command(char *str);

// error_handling_bonus.c
void		ft_printstr(const char *str);
void		print_error(int exit_code, const char *fmt, ...);

// execute.c
void		execute(char *cmds[], char **envp);

// execute_bonus.c
void		execute_command(t_pipex *pipex, int i);
void		execute_command_here_doc(t_pipex *pipex, int i);
void		execute_process(int num_commands, int ***pipe_fd, t_pipex *pipex);
void		execute_process_here_doc(int num_commands, int ***pipe_fd,
				t_pipex *pipex);

// handle_bonus.c
void		handle_child_process(int num_commands, int ***pipe_fd,
				t_pipex *pipex, int i);
void		handle_child_here_doc(int ***pipe_fd, int num_commands,
				t_pipex *pipex, int i);

// main_bonus.c
int			main(int argc, char **argv, char **envp);

// main.c
int			main(int argc, char **argv, char **envp);
void		child_process(char *infile_str, char *cmds_str, int pipe_fd[2],
				char **envp);
void		parent_process(char *outfile_str, char *cmds_str, int pipe_fd[2],
				char **envp);
void		print_error(int exit_code, const char *fmt, ...);
void		ft_printstr(const char *str);

// pipex_multi_bonus.c
void		pipex_multi(t_pipex *pipex);
void		pipex_multi_here_doc(t_pipex *pipex);

// pipex_utils_bonsu.c
void		init_pipes(int ***pipe_fd, int num_commands);
void		close_pipes(int ***pipe_fd, int num_commands);
void		free_pipes(int ***pipe_fd, int num_commands);
void		close_unused_pipes(int num_commands, int ***pipe_fd, int current);
void		close_unused_pipes_here_doc(int ***pipe_fd, int num_commands,
				int current);

// redirect_utils_bonus.c
void		redirect_input_to_pipe(t_pipex *pipex, int ***pipe_fd, int i);
void		redirect_input_to_pipe_here_doc(char *delimiter, int ***pipe_fd,
				int i);
void		redirect_pipe_to_output(t_pipex *pipex, int ***pipe_fd, int i);
void		redirect_pipe_to_pipe(int ***pipe_fd, int i);

// resolve.c
char		*get_fullpath(char *cmds[], char **envp);
char		*get_path_env(char **envp);
char		*check_default_paths(char *cmd);
char		*resolve_absolute_path(char *cmd);
char		*resolve_from_path_env(char *cmd, char **envp);

// split_command.c
void		remove_quotes(char **cmds);
char		**split_command(char *str);

// split_utils.c
char		*cmd_dup(char *word_start, char *word_end_next);
void		init_cmd_state(t_cmd_state *st, char *str);
int			is_escaped(const char *ptr, const char *word_start);

// utils.c
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*get_next_line(int fd);

// wait_process_bonus.c
int			wait_for_children(int num_commands);

#endif
