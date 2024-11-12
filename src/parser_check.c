/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:34:02 by atyurina          #+#    #+#             */
/*   Updated: 2024/11/12 14:38:45 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

void	free_text(char **text)
{
	int	i;

	i = 0;
	while (text[i] != NULL)
	{
		free(text[i]);
		i++;
	}
	free(text);
}

bool	file_check_error(char **text)
{
	if (file_check_capital(text) == false || file_wrong_element(text) == false)
	{
		free_text(text);
		exit(EXIT_FAILURE);
	}
	return (true);
}

bool	find_needle(char *line)
{
	if ((ft_strncmp(line, "A ", 2) != 0) && \
	(ft_strncmp(line, "C ", 2) != 0) && \
	(ft_strncmp(line, "L ", 2) != 0) && \
	(ft_strncmp(line, "sp ", 3) != 0) && \
	(ft_strncmp(line, "pl ", 3) != 0) && \
	(ft_strncmp(line, "cy ", 3) != 0))
		return (false);
	else
		return (true);
}

bool	file_wrong_element(char **text)
{
	int	i;

	i = 0;
	while (text[i] != NULL)
	{
		if (find_needle(text[i]) == false)
		{
			ft_putstr_fd("Error\nThere is a wrong element name in file\n", 2);
			return (false);
		}
		i++;
	}
	return (true);
}
