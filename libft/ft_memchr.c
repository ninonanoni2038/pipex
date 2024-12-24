/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sninomiy <sninomiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:30:30 by sninomiy          #+#    #+#             */
/*   Updated: 2024/05/01 14:27:19 by sninomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char s[] = {0, 1, 2 ,3 ,4 ,5};

// 	printf("%p\n",ft_memchr(s, 0, 0));
// 	printf("%p\n",ft_memchr(s, 0, 1));
// 	printf("%p\n",ft_memchr(s, 2, 3));
// 	printf("%p\n",ft_memchr(s, 6, 6));
// 	printf("%p\n",ft_memchr(s, 2 + 256, 3));

// 	printf("-------\n");

// 	printf("%p\n",memchr(s, 0, 0));
// 	printf("%p\n",memchr(s, 0, 1));
// 	printf("%p\n",memchr(s, 2, 3));
// 	printf("%p\n",memchr(s, 6, 6));
// 	printf("%p\n",memchr(s, 2 + 256, 3));
// }
