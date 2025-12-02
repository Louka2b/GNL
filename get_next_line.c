/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:28:56 by ldeplace          #+#    #+#             */
/*   Updated: 2025/12/02 15:22:09 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 400
#endif

static void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	block;

	block = count * size;
	if (count && (size != (block / count)))
		return (NULL);
	str = (char *)malloc(size * count);
	if (!str)
		return (NULL);
	ft_bzero(str, size * count);
	return (str);
}

char	*fill_line_buffer(int fd, char *left, char *buffer)
{
	int	i;

	i = 1;
	while (i != BUFFER_SIZE)
	{
		read(fd, buffer, BUFFER_SIZE);
		if(ft_strchr(buffer, '\n') != NULL)
		{
			break;
		}
	}
	
}

char	*set_line(char *line_buffer)
{
	
}

char	*get_next_line(int fd)
{
	static char	*str;
	int			i;

	if (fd == 0 || read(fd))
		return (NULL);
	
}