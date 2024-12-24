/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:48:14 by ninomiyasat       #+#    #+#             */
/*   Updated: 2024/04/24 01:48:18 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*source;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}

// #include "stdio.h"
// #include "string.h"

// int	main(void)
// {
// 	char	dst1[20] = "HelloWorld";
// 	char	src1[20] = "heyeverybody";
// 	char	dst2[20] = "HelloWorld";
// 	char	src2[20] = "heyeverybody";

// 	printf("-----------\n");
// 	// printf("%s\n", (char *)ft_memcpy(NULL, NULL, 10));
// 	printf("-----------\n");
// 	printf("%s\n", (char *)memcpy(NULL, NULL, 1));
//  //どっちもnullの時はnullが返ってくる
// 	printf("%s\n", (char *)memcpy(NULL, src1, 1));
// }
