/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sninomiy <sninomiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:09:44 by sninomiy          #+#    #+#             */
/*   Updated: 2024/04/30 22:18:01 by sninomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*ptr;
	unsigned char	uc;

	ptr = (char *)s;
	uc = (unsigned char)c;
	if (uc == '\0')
		return (ptr + ft_strlen(s));
	while (*ptr)
	{
		if (*ptr == uc)
			return (ptr);
		ptr++;
	}
	return (NULL);
}

// #include "stdio.h"
// #include "string.h"

// int	main(void)
// {
// 	printf("%s\n", strchr("abcdef",'g'));
// 	printf("%s\n", strchr("Hello World!",'W'));

// 	printf("---------");

// 	printf("%s\n", ft_strchr("abcdef",'g'));
// 	printf("%s\n", ft_strchr("Hello World!",'W'));
// 	return (0);
// }
