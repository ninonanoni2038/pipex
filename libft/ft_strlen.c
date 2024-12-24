/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sninomiy <sninomiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:10:50 by ninomiyasat       #+#    #+#             */
/*   Updated: 2024/05/01 18:33:36 by sninomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

// #include <stdio.h>

// int main()
// {
// 	// printf("%zu\n", ft_strlen(NULL));
// 	printf("%zu\n", ft_strlen(""));
// }
