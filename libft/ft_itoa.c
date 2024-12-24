/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:49:15 by sninomiy          #+#    #+#             */
/*   Updated: 2024/04/24 18:08:13 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_dig(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	char	is_nega;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = count_dig(n);
	is_nega = 0;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		is_nega = 1;
		str[0] = '-';
	}
	str[len] = '\0';
	while ((len > 0 && is_nega == 0) || (len > 1 && is_nega == 1))
	{
		len--;
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("1:%d\n", count_dig(0));
// 	printf("2:%d\n", count_dig(10));
// 	printf("3:%d\n", count_dig(123));
// 	printf("2:%d\n", count_dig(-1));
// 	printf("3:%d\n", count_dig(-10));
// 	printf("4:%d\n", count_dig(-123));
// 	printf("11:%d\n", count_dig(-2147483648));
// 	printf("10:%d\n", count_dig(2147483647));
// 	printf("4:{%s}\n", ft_itoa(4));
// 	printf("42:{%s}\n", ft_itoa(42));
// 	printf("1234:{%s}\n", ft_itoa(1234));
// 	printf("2147483647:{%s}\n", ft_itoa(2147483647));
// 	printf("0:{%s}\n", ft_itoa(0));
// 	printf("-4:{%s}\n", ft_itoa(-4));
// 	printf("-42:{%s}\n", ft_itoa(-42));
// 	printf("-2147483647:{%s}\n", ft_itoa(-2147483647));
// 	printf("-2147483648:{%s}\n", ft_itoa(-2147483648));
// }
