/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:10:51 by ninomiyasat       #+#    #+#             */
/*   Updated: 2024/04/24 13:27:41 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*source;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	if (dest < source)
		ft_memcpy(dst, src, len);
	else
	{
		i = len;
		while (i > 0)
		{
			i--;
			dest[i] = source[i];
		}
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	sResult[] = "abcdefg";
// 	char	str[] = "memmove can be very useful.";

// 	printf("%s\n", memmove(sResult + 1, sResult, 2));
// 	printf("%s\n", ft_memmove(sResult + 1, sResult, 2));
// 	printf("%s\n", memmove(str + 10, str + 5, 10));
// 	printf("%s\n", ft_memmove(str + 10, str + 5, 10));
// 	printf("%s\n", ft_memmove(NULL, NULL, 10));
// }
