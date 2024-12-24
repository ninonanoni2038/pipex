/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:26:43 by sninomiy          #+#    #+#             */
/*   Updated: 2024/04/24 17:34:37 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

// #include <stdio.h>
// #include <sys/fcntl.h>
// #include <unistd.h>

// int	main(void)
// {
// 	int		file_fd;

// 	ft_putendl_fd("Hello", 1);
// 	ft_putendl_fd("Hello", 2);
// 	return (0);
// }
