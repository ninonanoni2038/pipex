/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:39:14 by sninomiy          #+#    #+#             */
/*   Updated: 2024/04/24 17:00:26 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*substr;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	s_len = (unsigned int)ft_strlen(s);
	if (s[0] == '\0' || start >= s_len)
		return (ft_strdup("\0"));
	if (s_len < start + len)
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len && start + i < s_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// #include <stdio.h>
// #include <libc.h>

// __attribute__((destructor))
// static void destructor() {
// 	system("leaks -q a.out");
// }

// int	main(void)
// {
// 	char	*str;

// 	str = ft_substr("ABCDEF", 3, 3);
// 	printf("expected:DEF output:%s\n", str);
// 	free (str);
// 	// printf("expected: output:%s\n", ft_substr("", 3, 3));
// 	// printf("expected:NULL output:%s\n", ft_substr(NULL, 3, 3));
// 	// printf("expected:DEF output:%s\n", ft_substr("ABCDEF", 3, 4));
// 	// printf("expected:NULL output:%s\n", ft_substr("ABCDEF", 3, 0));
// 	// printf("expected:ABCDEF output:%s\n", ft_substr("ABCDEF", 0, 6));
// 	// printf("expected:NULL output:%s\n", ft_substr("ABCDEF", 6, 0));
// 	// printf("expected:NULL output:%s\n", ft_substr("ABCDEF", 6, 3));
// 	// char *result;
// 	// result = ft_substr("ABCDEF", 10, 3);
// 	// printf("expected:NULL output:%s\n", result);
// 	// if (result[0] == '\0')
// 	// 	printf("output is empty.\n");
// 	// else
// 	// 	printf("output is not empty.\n");
// }
