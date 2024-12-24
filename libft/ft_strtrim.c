/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sninomiy <sninomiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:04:08 by sninomiy          #+#    #+#             */
/*   Updated: 2024/04/30 22:18:24 by sninomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char str_i, char const *set)
{
	while (*set)
	{
		if (str_i == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_start_ptr;
	char	*set_ptr;
	char	*str_end_ptr;

	if (!s1)
		return (NULL);
	str_start_ptr = (char *)s1;
	set_ptr = (char *)set;
	str_end_ptr = str_start_ptr + ft_strlen(s1);
	if (*set_ptr == '\0')
		return (ft_strdup(s1));
	while (*str_start_ptr)
	{
		if (is_set(*str_start_ptr, set) == 0)
			break ;
		str_start_ptr++;
	}
	str_end_ptr = str_start_ptr + ft_strlen(str_start_ptr) - 1;
	while (is_set(*str_end_ptr, set) == 1)
	{
		str_end_ptr--;
	}
	return (ft_substr(s1, str_start_ptr - s1, str_end_ptr - str_start_ptr + 1));
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("expected:{Hello World} output:{%s}\n",
// 		ft_strtrim("  !!Hello World!!  ", "! "));
// 	printf("expected:{hello world} output:{%s}\n",
// 		ft_strtrim("    hello world     ", " "));
// }

// /* 1 */ ASSERT_EQ_STR(ft_strtrim("hello world", "world"), "hello ");
// /* 2 */ ASSERT_EQ_STR(ft_strtrim("hello world", "hello"), " world");
// /* 3 */ ASSERT_EQ_STR(ft_strtrim("hello world", ""), "hello world");
// /* 4 */ ASSERT_EQ_STR(ft_strtrim("", ""), "");
