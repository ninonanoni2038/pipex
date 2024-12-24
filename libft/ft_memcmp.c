/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:33:12 by sninomiy          #+#    #+#             */
/*   Updated: 2024/04/24 01:21:51 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src1;
	unsigned char	*src2;
	size_t			i;

	i = 0;
	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	while (i < n)
	{
		if (src1[i] != src2[i])
			return (src1[i] - src2[i]);
		i++;
	}
	return (0);
}

// #include <libc.h>
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	buf1[] = "Hello World";
// 	char	buf2[] = "Hello World";
// 	char	buf3[] = "Hello there";
// 	char	s[] = {-128, 0, 127, 0};
// 	char	sCpy[] = {-128, 0, 127, 0};
// 	char	s2[] = {0, 0, 127, 0};
// 	char	s3[] = {0, 0, 42, 0};

// 	printf("1:%d\n", memcmp(buf1, buf2, sizeof(buf1)));
// 	printf("2:%d\n", memcmp(buf1, buf3, 5));
// 	printf("3:%d\n", memcmp(buf1, buf3, sizeof(buf1)));
// 	printf("4:%d\n", memcmp(buf3, buf1, sizeof(buf3)));
// 	printf("5:%d\n", memcmp(s, s2, 1));
// 	printf("6:%d\n", memcmp(s2, s, 1));
// 	printf("7:%d\n", memcmp(s2, s3, 4));
// 	printf("8:%d\n", memcmp(s, s2, 1));
// 	printf("9:%d\n", memcmp(s2, s, 1));
// 	printf("10:%d\n", memcmp(s2, s3, 4));
// 	printf("------\n");
// 	printf("1:%d\n", ft_memcmp(buf1, buf2, sizeof(buf1)));
// 	printf("2:%d\n", ft_memcmp(buf1, buf3, 5));
// 	printf("3:%d\n", ft_memcmp(buf1, buf3, sizeof(buf1)));
// 	printf("4:%d\n", ft_memcmp(buf3, buf1, sizeof(buf3)));
// 	printf("5:%d\n", ft_memcmp(s, s2, 1));
// 	printf("6:%d\n", ft_memcmp(s2, s, 1));
// 	printf("7:%d\n", ft_memcmp(s2, s3, 4));
// 	printf("8:%d\n", ft_memcmp(s, s2, 1));
// 	printf("9:%d\n", ft_memcmp(s2, s, 1));
// 	printf("10:%d\n", ft_memcmp(s2, s3, 4));
// 	return (0);
// }
