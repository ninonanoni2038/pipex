/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyakei <ninomiyakei@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:39:42 by ninomiyakei       #+#    #+#             */
/*   Updated: 2024/11/26 19:05:20 by ninomiyakei      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	process_command(char *cmd)
{
	char	*src;
	char	*dst;
	int		len;

	src = cmd;
	len = ft_strlen(src);
	dst = src;
	if ((src[0] == '\'' && src[len - 1] == '\'')
		|| (src[0] == '\"' && src[len - 1] == '\"'))
	{
		src++;
		len -= 2;
	}
	while (*src != '\0' && len > 0)
	{
		if (*src == '\\' && *(src + 1) != '\0')
		{
			src++;
			len--;
		}
		*dst++ = *src++;
		len--;
	}
	*dst = '\0';
}

void	remove_quotes(char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i] != NULL)
	{
		process_command(cmds[i]);
		i++;
	}
}

static void	process_in_dq(t_cmd_state *st, char *str)
{
	if (*str == '\"' && !is_escaped(str, st->word_start))
		st->in_dq = 0;
	else
		st->word_len++;
}

static void	process_outside_dq(t_cmd_state *st, char *str, char **cmds)
{
	if (*str == '\'')
		st->in_sq = !st->in_sq;
	else if (*str == '\"')
		st->in_dq = !st->in_dq;
	else if (*str == ' ' && !st->in_sq)
	{
		if (st->word_len > 0)
		{
			cmds[st->cmd_index] = cmd_dup(st->word_start, str);
			st->cmd_index++;
			st->word_len = 0;
		}
		st->word_start = str + 1;
	}
	else
		st->word_len++;
}

char	**split_command(char *str)
{
	char		**cmds;
	t_cmd_state	st;

	cmds = (char **)malloc(sizeof(char *) * (count_command(str) + 1));
	if (!cmds)
		return (NULL);
	init_cmd_state(&st, str);
	while (*str)
	{
		if (st.in_dq)
			process_in_dq(&st, str);
		else
			process_outside_dq(&st, str, cmds);
		str++;
	}
	if (st.word_len > 0)
	{
		cmds[st.cmd_index] = cmd_dup(st.word_start, str);
		st.cmd_index++;
	}
	cmds[st.cmd_index] = NULL;
	remove_quotes(cmds);
	return (cmds);
}
