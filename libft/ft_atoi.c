/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:11:52 by sninomiy          #+#    #+#             */
/*   Updated: 2024/04/24 17:57:32 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_long_overflow(long num, long next_num)
{
	long	on_div;
	long	on_mod;

	on_div = LONG_MAX / 10;
	on_mod = LONG_MAX % 10;
	if (num > on_div)
		return (1);
	else if (num == on_div && next_num > on_mod)
		return (1);
	return (0);
}

int	is_long_underflow(long num, long next_num)
{
	long	on_div;
	long	on_mod;

	on_div = 922337203685477580;
	on_mod = 7;
	if (num > on_div)
		return (1);
	else if (num == on_div && next_num > on_mod)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	num;
	long	i;
	long	nega;

	num = 0;
	i = 0;
	nega = 1;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		nega = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (is_long_overflow(num, str[i] - '0') && nega == 1)
			return ((int)LONG_MAX);
		if (is_long_underflow(num, str[i] - '0') && nega == -1)
			return ((int)LONG_MIN);
		num = num * 10 + str[i++] - '0';
	}
	return ((int)(num * nega));
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	printf("%d\n", ft_atoi("-9223372036854775807"));
// 	printf("%d\n", atoi("-9223372036854775807"));

// 	printf("%d\n", ft_atoi("-9223372036854775808"));
// 	printf("%d\n", atoi("-9223372036854775808"));

// 	printf("%d\n", ft_atoi("-9223372036854775809"));
// 	printf("%d\n", atoi("-9223372036854775809"));
// }
