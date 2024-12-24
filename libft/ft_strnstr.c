/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:52:59 by sninomiy          #+#    #+#             */
/*   Updated: 2024/04/24 17:52:42 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] != '\0' && (i + j) < len
				&& haystack[i + j] == needle[j])
			{
				j++;
			}
			if (needle[j] == '\0')
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char *heystack;
// 	heystack = NULL;
// 	printf("%p\n", &heystack[0]);
// 	printf("%c\n", heystack[0]);
	// printf("0:%s\n", ft_strnstr(NULL, "Wor", 15));
	// printf("1:%s\n", strnstr("Hello World", "Wor", 15));
	// printf("2:%s\n", strnstr("World World", "Wor", 15));
	// printf("3:%s\n", strnstr("Hello World", "Wor", 5));
	// printf("4:%s\n", strnstr("Hello World", "", 5));
	// printf("5:%s\n", strnstr("Hello World", "or", 20));
	// printf("6:%s\n", strnstr("", "Wor", 15));
	// printf("-------\n");
	// printf("1:%s\n", ft_strnstr("Hello World", "Wor", 15));
	// printf("2:%s\n", ft_strnstr("World World", "Wor", 15));
	// printf("3:%s\n", ft_strnstr("Hello World", "Wor", 5));
	// printf("4:%s\n", ft_strnstr("Hello World", "", 5));
	// printf("5:%s\n", ft_strnstr("Hello World", "or", 20));
	// printf("6:%s\n", ft_strnstr("", "Wor", 15));
// }
