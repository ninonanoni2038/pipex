/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyakei <ninomiyakei@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:41:10 by ninomiyakei       #+#    #+#             */
/*   Updated: 2024/12/19 15:58:56 by ninomiyakei      ###   ########.fr       */
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
}	t_pipex;

// count_commnad.c
int			count_command(char *str);

// execute.c
void		execute(char *cmds[], char **envp);

// main.c
int			main(int argc, char **argv, char **envp);
void		child_process(char *infile_str, char *cmds_str, int pipe_fd[2],
				char **envp);
void		parent_process(char *outfile_str, char *cmds_str, int pipe_fd[2],
				char **envp);
void		print_error(int exit_code, const char *fmt, ...);
void		ft_printstr(const char *str);

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

#endif
