/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:20:07 by ninomiyasat       #+#    #+#             */
/*   Updated: 2024/12/24 13:29:56 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_printstr(const char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	print_error(int exit_code, const char *fmt, ...)
{
	va_list	args;
	char	*str;
	char	*ptr;

	va_start(args, fmt);
	ptr = (char *)fmt;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == 's')
			{
				str = va_arg(args, char *);
				if (str)
					ft_printstr(str);
			}
		}
		else
			write(2, ptr, 1);
		ptr++;
	}
	va_end(args);
	exit(exit_code);
}
