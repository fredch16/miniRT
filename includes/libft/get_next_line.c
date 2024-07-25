/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:08:45 by atyurina          #+#    #+#             */
/*   Updated: 2023/11/22 14:48:56 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	index_nl(char *buffer)
{
	ssize_t	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	if (ft_strchr(buffer, '\n') == NULL)
		return (ft_strlen(buffer));
	return (0);
}

ssize_t	index_nl_tr(char *buffer)
{
	ssize_t	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*trim_tail(char *tail)
{
	char	*tr_tail;
	int		nl;

	nl = index_nl_tr(tail);
	if (nl == -1)
	{
		free(tail);
		return (NULL);
	}
	tr_tail = ft_substr(tail, nl + 1, ft_strlen(tail) - nl);
	if (!tr_tail)
	{
		free(tail);
		return (NULL);
	}
	free(tail);
	return (tr_tail);
}

char	*read_fd(int fd, char *tail)
{
	char	*temp_buffer;
	int		bytes_read;

	bytes_read = 1;
	temp_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_buffer)
	{
		free(tail);
		return (NULL);
	}
	while (ft_strchr(tail, '\n') == NULL && bytes_read != 0)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp_buffer);
			free(tail);
			return (NULL);
		}
		temp_buffer[bytes_read] = '\0';
		tail = dop_func(tail, temp_buffer);
	}
	free(temp_buffer);
	return (tail);
}

char	*get_next_line(int fd)
{
	static char	*tail = NULL;
	char		*line;

	if (fd == -1 || fd > 4095 || BUFFER_SIZE < 1)
		return (NULL);
	if (!tail)
	{
		tail = (char *)malloc(sizeof(char) * 1);
		if (!tail)
			return (NULL);
		*tail = '\0';
	}
	tail = read_fd(fd, tail);
	if (!tail || tail[0] == '\0')
	{
		free(tail);
		tail = NULL;
		return (NULL);
	}
	line = ft_substr(tail, 0, index_nl(tail) + 1);
	tail = trim_tail(tail);
	return (line);
}
