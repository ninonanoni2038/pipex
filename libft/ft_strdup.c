/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:19:35 by sninomiy          #+#    #+#             */
/*   Updated: 2024/05/24 17:33:34 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	s1_len;
	size_t	i;

	s1_len = 0;
	while (s1[s1_len] != '\0')
		s1_len++;
	str = malloc(s1_len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char *str1 = strdup("abcdefg");
// 	char *str2 = ft_strdup("abcdefg");

// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// }
