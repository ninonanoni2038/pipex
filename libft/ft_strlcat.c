/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sninomiy <sninomiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:28:01 by sninomiy          #+#    #+#             */
/*   Updated: 2024/05/16 16:57:20 by sninomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	copy_size;
	size_t	i;

	src_len = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	copy_size = dstsize - dst_len - 1;
	if (src_len < copy_size)
		copy_size = src_len;
	i = 0;
	while (i < copy_size && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + copy_size] = '\0';
	return (dst_len + src_len);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*dst1;
// 	char	*dst2;

// 	dst1 = ft_strdup("Hello");
// 	dst2 = ft_strdup("Hello");
// 	printf("Total length: %zu\n", ft_strlcat(NULL, "World", 0));
// 	printf("%s\n", dst1);
// 	printf("Total length: %zu\n", strlcat(NULL, "World", 0));
// 	printf("%s\n", dst2);
// 	return (0);
// }
