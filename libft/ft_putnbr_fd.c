/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:26:43 by sninomiy          #+#    #+#             */
/*   Updated: 2024/04/24 17:37:29 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	digit = n % 10 + '0';
	write(fd, &digit, 1);
}

// // Additional helper function for demonstration
// void	ft_putnbr(int n)
// {
// 	ft_putnbr_fd(n, 1);
// }

// #include <libc.h>
// #include <stdio.h>
// #include <sys/fcntl.h>
// #include <unistd.h>

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q a.out");
// }

// int	main(void)
// {
// 	int	c;
// 	int	file_fd;

// 	c = 1234;
// 	file_fd = open("output.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
// 	ft_putnbr_fd(c, STDOUT_FILENO);
// 	ft_putnbr_fd(c, STDERR_FILENO);
// 	if (file_fd == -1)
// 	{
// 		perror("Failed to open file");
// 		return (1);
// 	}
// 	ft_putchar_fd(c, file_fd);
// 	if (close(file_fd) == -1)
// 	{
// 		perror("Failed to close file");
// 		return (1);
// 	}
// 	return (0);
// }
