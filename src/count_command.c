/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyakei <ninomiyakei@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:38:50 by ninomiyakei       #+#    #+#             */
/*   Updated: 2024/11/26 19:04:52 by ninomiyakei      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	handle_double_quotes(char **str, t_cmd_state *st)
{
	if (**str == '\"' && !is_escaped(*str, st->word_start))
		st->in_dq = 0;
	else
		st->word_len++;
	(*str)++;
}

static void	handle_outside_quotes(char **str, t_cmd_state *st)
{
	if (**str == '\'')
		st->in_sq = !st->in_sq;
	else if (**str == '\"')
		st->in_dq = 1;
	else if (**str == ' ' && !st->in_sq)
	{
		if (st->word_len > 0)
		{
			st->count++;
			st->word_len = 0;
		}
	}
	else
		st->word_len++;
	(*str)++;
}

int	count_command(char *str)
{
	t_cmd_state	st;

	init_cmd_state(&st, str);
	while (*str)
	{
		if (st.in_dq)
			handle_double_quotes(&str, &st);
		else
			handle_outside_quotes(&str, &st);
	}
	if (st.word_len > 0)
		st.count++;
	return (st.count);
}
