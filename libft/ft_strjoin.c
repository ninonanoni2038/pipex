/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyakei <ninomiyakei@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:17:37 by sninomiy          #+#    #+#             */
/*   Updated: 2024/11/15 20:21:10 by ninomiyakei      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*handle_null_input(const char *s1, const char *s2)
{
	if (s1)
		return (ft_strdup(s1));
	if (s2)
		return (ft_strdup(s2));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	i;
	size_t	j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!s1 || !s2)
		return (handle_null_input(s1, s2));
	joined_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (joined_str == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		joined_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		joined_str[i + j] = s2[j];
		j++;
	}
	joined_str[i + j] = '\0';
	return (joined_str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s\n", ft_strjoin("Hello", "World"));
// }
