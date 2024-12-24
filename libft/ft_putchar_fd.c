/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sninomiy <sninomiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:26:43 by sninomiy          #+#    #+#             */
/*   Updated: 2024/04/25 20:13:06 by sninomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <stdio.h>
// #include <sys/fcntl.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char	c;
// 	int		fd;

// 	c = 'X';
// 	ft_putchar_fd(c, 1);
// 	ft_putchar_fd(c, 2);
// 	ft_putchar_fd(c, 1024);
// 	fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	printf("%zd\n", write(2, "Hello", 6));
// 	printf("%zd\n", write(3, "Hello", 6));
// 	printf("%zd\n", write(255, "Hello", 6));
// 	printf("%zd\n", write(256, "Hello", 6));
// 	close(fd);
// 	return (0);
// }
