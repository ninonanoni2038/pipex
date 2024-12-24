/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sninomiy <sninomiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:45:33 by sninomiy          #+#    #+#             */
/*   Updated: 2024/05/17 20:38:39 by sninomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			total_size;
	void			*ptr;
	size_t			i;
	unsigned char	*p;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	total_size = count * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
	{
		free (ptr);
		return (NULL);
	}
	i = 0;
	p = (unsigned char *) ptr;
	while (i < total_size)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}
// #include <stdio.h>
// #include <stdlib.h>
// void	print_nums_memory(const int *nums, size_t size)
// {
// 	for (size_t i = 0; i < size; i++)
// 	{
// 		printf("%d ", nums[i]);
// 	}
// 	printf("\n");
// }
// void	print_str_memory(const char *str, size_t size)
// {
// 	for (size_t i = 0; i < size; i++)
// 	{
// 		printf("%d ", str[i]);
// 	}
// 	printf("\n");
// }
// int	main(void)
// {
// 	int		*nums1 = (int *)calloc(10, sizeof(int));
// 	char	*str1 = (char *)calloc(10, sizeof(char));
// 	print_nums_memory(nums1, 10);
// 	print_str_memory(str1, 10);
// 	free(nums1);
// 	free(str1);
// 	int		*nums2 = (int *)ft_calloc(10, sizeof(int));
// 	char	*str2 = (char *)ft_calloc(10, sizeof(char));
// 	print_nums_memory(nums2, 10);
// 	print_str_memory(str2, 10);
// 	free(nums2);
// 	free(str2);
// 	return (0);
// }
