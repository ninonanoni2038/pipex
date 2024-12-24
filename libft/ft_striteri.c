/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:08:01 by sninomiy          #+#    #+#             */
/*   Updated: 2024/04/22 13:26:27 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	char			*ptr;
	unsigned int	str_i;

	if (!s)
		return ;
	ptr = s;
	str_i = 0;
	while (*ptr)
	{
		f(str_i, ptr);
		str_i++;
		ptr++;
	}
}

// void	ft_replace_odd(unsigned int i, char *str)
// {
// 	if (i % 2 == 0)
// 		*str = ' ';
// }

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str1;

// 	str1 = ft_strdup("abcdef");
// 	ft_striteri(str1, ft_replace_odd);
// 	printf("Expected:{ b d f}  Output:{%s}\n", str1);
// 	return (0);
// }
