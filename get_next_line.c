/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:28:56 by ldeplace          #+#    #+#             */
/*   Updated: 2025/12/09 14:36:08 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#ifndef MAX_FD
# define MAX_FD 1024
#endif

char	*ft_freeall(char *buffer, char *s)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, s);
	if (!tmp)
	{
		free(s);
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (tmp);
}

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*str;
	int		o;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	o = 0;
	while (buffer[o] != '\n' && buffer[o] != '\0')
		o++;
	if (buffer[o] == '\n')
		o = 1;
	else
		o = 0;
	str = ft_substr(buffer, 0, i + o);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*ft_new_str(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return (str);
}

char	*ft_read_str(int fd, char *buffer)
{
	char	*s;
	int		bytes;

	s = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!s)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buffer, '\n') && bytes > 0)
	{
		bytes = read(fd, s, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(s);
			free(buffer);
			return (NULL);
		}
		s[bytes] = '\0';
		buffer = ft_freeall(buffer, s);
		if (!buffer)
			break ;
	}
	free(s);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffers[MAX_FD];

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (0);
	buffers[fd] = ft_read_str(fd, buffers[fd]);
	if (!buffers[fd])
		return (NULL);
	line = ft_get_line(buffers[fd]);
	buffers[fd] = ft_new_str(buffers[fd]);
	return (line);
}
