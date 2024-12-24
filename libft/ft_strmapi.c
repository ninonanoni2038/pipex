/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sninomiy <sninomiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:32:37 by sninomiy          #+#    #+#             */
/*   Updated: 2024/05/16 16:42:57 by sninomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*ptr;
	unsigned int	str_i;

	if (!s)
		return (NULL);
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	ptr = str;
	str_i = 0;
	while (*ptr)
	{
		*ptr = f(str_i, *ptr);
		str_i++;
		ptr++;
	}
	return (str);
}

// char	ft_replace_odd(unsigned int i, char c)
// {
// 	if (i % 2 == 1)
// 		return (c);
// 	else
// 		return (' ');
// }

// #include <stdio.h>

// int	main(void)
// {
// 	printf("Expected:{ b d f}  Output:{%s}\n", ft_strmapi("abcdef",
			// ft_replace_odd));
// 	return (0);
// }
