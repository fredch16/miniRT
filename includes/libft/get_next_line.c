/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:15:54 by fcharbon          #+#    #+#             */
/*   Updated: 2024/03/19 18:25:04 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> 
#include <errno.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			flag;
	int			read_result;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= FOPEN_MAX)
		return (NULL);
	while (1)
	{
		if (buffer[0] == '\0')
		{
			read_result = read(fd, buffer, BUFFER_SIZE);
			if (read_result == -1)
				return (free_line(&line));
			if (read_result == 0)
				return (line);
		}
		flag = line_updater(&line, buffer);
		buffer_clear(buffer);
		if (flag == 1)
			return (line);
		if (flag == -1)
			return (NULL);
	}
}
