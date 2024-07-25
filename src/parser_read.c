/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:39:53 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/24 17:16:47 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

#include <fcntl.h>

void	ft_message_error(char *str)
{
	ft_printf("%s", str);
	exit(2);
}

static void	check_file_empty(char *map)
{
	if (map[0] == '\0')
		ft_message_error("File is empty");
}

static char	*read_file_contents(int fd)
{
	char	*line;
	char	*all_lines;
	char	*tmp;

	all_lines = ft_strdup("");
	if (all_lines == NULL)
		ft_message_error("Malloc error");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		tmp = ft_strjoin(all_lines, line);
		free(all_lines);
		all_lines = tmp;
		free(line);
	}
	return (all_lines);
}

static char	**split_lines(char *all_lines)
{
	char	**spt;

	spt = ft_split(all_lines, '\n');
	free(all_lines);
	return (spt);
}

char	**file_read(char *file)
{
	int		fd;
	char	*all_lines;
	char	**spt;

	if (file_check_rt(file) == true)
		ft_message_error("Error\nYou just need to pass a file with .rt extension.\n");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_message_error("Error while opening fd\nIt either doesn't exist or permission is denied.\n");
	all_lines = read_file_contents(fd);
	close(fd);
	check_file_empty(all_lines);
	spt = split_lines(all_lines);
	return (spt);
}