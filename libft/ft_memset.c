/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sninomiy <sninomiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:08:18 by ninomiyasat       #+#    #+#             */
/*   Updated: 2024/04/25 20:13:26 by sninomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	str1[20] = "Hello World";
// 	char	str2[20] = "Hello World";

// 	printf("%s\n", ft_memset(str1, 65, 10));
// 	printf("%s\n", memset(str1, 65, 10));
// 	printf("%s\n", memset(str2, 65, 10));
// }
