/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninomiyasatoshi <ninomiyasatoshi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:37:28 by ninomiyakei       #+#    #+#             */
/*   Updated: 2024/12/24 13:30:15 by ninomiyasat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*dest_ptr;

	dest_ptr = dest;
	while (*src != '\0')
	{
		*dest_ptr = *src;
		dest_ptr++;
		src++;
	}
	*dest_ptr = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, const char *src)
{
	char	*dest_ptr;

	dest_ptr = dest;
	while (*dest_ptr != '\0')
	{
		dest_ptr++;
	}
	while (*src != '\0')
	{
		*dest_ptr = *src;
		dest_ptr++;
		src++;
	}
	*dest_ptr = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	buffer;
	int		i;
	int		read_bytes;

	line = (char *)malloc(10000);
	if (!line)
		return (NULL);
	i = 0;
	read_bytes = read(fd, &buffer, 1);
	while (read_bytes > 0)
	{
		line[i++] = buffer;
		if (buffer == '\n')
			break ;
		read_bytes = read(fd, &buffer, 1);
	}
	line[i] = '\0';
	if (read_bytes <= 0 && i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
