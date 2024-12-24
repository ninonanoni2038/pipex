/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyakei <ninomiyakei@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:58:04 by ninomiyakei       #+#    #+#             */
/*   Updated: 2024/11/26 19:05:12 by ninomiyakei      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*cmd_dup(char *word_start, char *word_end_next)
{
	size_t	length;
	char	*result;

	if (word_start == NULL || word_end_next == NULL
		|| word_start >= word_end_next)
		return (NULL);
	length = word_end_next - word_start;
	result = (char *)malloc(length + 1);
	if (result == NULL)
		return (NULL);
	ft_strncpy(result, word_start, length);
	result[length] = '\0';
	return (result);
}

void	init_cmd_state(t_cmd_state *st, char *str)
{
	st->count = 0;
	st->in_sq = 0;
	st->in_dq = 0;
	st->word_len = 0;
	st->word_start = str;
	st->cmd_index = 0;
}

int	is_escaped(const char *ptr, const char *word_start)
{
	const char	*prev_ptr;

	if (ptr != word_start)
	{
		prev_ptr = ptr - 1;
		return (*prev_ptr == '\\');
	}
	return (0);
}

// #include <stdio.h>

// void	print_string_array(char **array)
// {
// 	int	i;

// 	i = 0;
// 	if (!array)
// 	{
// 		printf("Array is NULL\n");
// 		return ;
// 	}
// 	while (array[i])
// 	{
// 		printf("Element %d: %s,\n", i, array[i]);
// 		i++;
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	char **str_array;

// 	(void)argc;
// 	str_array = split_command(argv[1]);
// 	print_string_array(str_array);
// 	printf("%d\n", count_command(argv[1]));
// 	return (0);
// }