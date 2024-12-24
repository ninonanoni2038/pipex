/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sninomiy <sninomiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:17:51 by sninomiy          #+#    #+#             */
/*   Updated: 2024/05/01 18:33:54 by sninomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int		count;
	char	*ptr;
	int		is_in_word;

	is_in_word = 0;
	count = 0;
	ptr = (char *)s;
	if (*ptr != c)
	{
		is_in_word = 1;
		count++;
	}
	while (*ptr)
	{
		if (*ptr == c)
			is_in_word = 0;
		if (is_in_word == 0 && *ptr != c)
		{
			count++;
			is_in_word = 1;
		}
		ptr++;
	}
	return (count);
}

char	*word_dup(char const *s, char *ptr, char c)
{
	char	*str;

	str = ft_substr(s, (unsigned int)(ptr - s), ft_strchr(ptr, c) - ptr);
	return (str);
}

char	**free_words(char **words, int words_i)
{
	while (words_i > 0)
	{
		words_i--;
		free(words[words_i]);
	}
	free (words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	char	*ptr;
	int		words_i;

	if (!s)
		return (NULL);
	words = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!words)
		return (NULL);
	ptr = (char *)s;
	words_i = 0;
	while (*ptr)
	{
		if (*ptr != c)
		{
			words[words_i] = word_dup(s, ptr, c);
			if (!words[words_i])
				return (free_words(words, words_i));
			ptr = ptr + ft_strlen(words[words_i]) - 1;
			words_i++;
		}
		ptr++;
	}
	words[words_i] = NULL;
	return (words);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	**result1;

// 	result1 = ft_split("  Hello  World  42  tokyo", ' ');
// 	printf("expected:{hello, world, 42, tokyo}");
// 	printf(" output:{");
// 	while (*result1)
// 	{
// 		printf("%s, ", *result1);
// 		result1++;
// 	}
// 	printf("}\n");
// // For check count_words
// printf("Expected:4, Output:%d\n",
// count_words("Hello World hey everybody", ' '));
// printf("Expected:4, Output:%d\n",
// count_words("Hello World hey everybody ", ' '));
// printf("Expected:4, Output:%d\n",
// count_words(" Hello World hey everybody", ' '));
// printf("Expected:4, Output:%d\n",
// count_words("Hello     World hey everybody", ' '));
// }
