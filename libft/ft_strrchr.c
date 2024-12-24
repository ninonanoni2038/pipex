/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sninomiy <sninomiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:09:44 by sninomiy          #+#    #+#             */
/*   Updated: 2024/04/17 17:33:23 by sninomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*ptr;
	char			*last_occurrence;
	unsigned char	uc;

	ptr = (char *)s;
	last_occurrence = NULL;
	uc = (unsigned char)c;
	if (uc == '\0')
		return (ptr + ft_strlen(s));
	while (*ptr)
	{
		if (*ptr == uc)
			last_occurrence = ptr;
		ptr++;
	}
	return (last_occurrence);
}

// #include "stdio.h"

// int	main(void)
// {
// 	char	*result1;
// 	char	*result2;

// 	result1 = ft_strrchr("abcdbef",'b');
// 	result2 = ft_strrchr("Hello World!",'W');
// 	printf("%s\n", result1);
// 	printf("%s\n", result2);
// 	return (0);
// }