/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sninomiy <sninomiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:13:02 by sninomiy          #+#    #+#             */
/*   Updated: 2024/05/01 14:54:50 by sninomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	printf("%d\n", ft_strncmp("abcde","abcdef",6));
// 	printf("%d\n", ft_strncmp("abcdef","abcdef",6));
// 	printf("%d\n", ft_strncmp("abcdef","abcdef",8));
// 	printf("%d\n", ft_strncmp("abcdef","abcdez",4));
// 	printf("%d\n", ft_strncmp("abcdef","abcdefghijk",15));
// 	printf("-----\n");

// 	printf("%d\n", strncmp("abcdez","abcdef",6));
// 	printf("%d\n", strncmp("abcdef","abcdef",6));
// 	printf("%d\n", strncmp("abcdef","abcdef",8));
// 	printf("%d\n", strncmp("abcdef","abcdez",4));
// 	printf("%d\n", strncmp("abcdef","abcdefghijk",15));
// }