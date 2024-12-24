/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:49:29 by sninomiy          #+#    #+#             */
/*   Updated: 2024/04/24 17:49:38 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (65 <= c && c <= 90)
	{
		c += 32;
	}
	return (c);
}

// #include <stdio.h>

// int main()
// {
// 	int c1 = 'A';
// 	int c2;
// 	c2 = ft_tolower(c1);
// 	printf("%c\n", c2);
// }
