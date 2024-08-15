/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:34:02 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/15 15:51:56 by atyurina         ###   ########.fr       */
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
	if ((ft_strncmp(line, "A ", 2) != 0) &&\
	(ft_strncmp(line, "C ", 2) != 0) &&\
	(ft_strncmp(line, "L ", 2) != 0) &&\
	(ft_strncmp(line, "sp ", 3) != 0) &&\
	(ft_strncmp(line, "pl ", 3) != 0) &&\
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

/**
 *  check separately data of each line: A, C, L, pl, sp, cy. If wrong data -> Error
*/

// Program must take as a first argument a scene description file with the .rt
// extension.
// ◦ Each type of element can be separated by one or more line break(s).
// ◦ Each type of information from an element can be separated by one or more
// space(s).
// ◦ Each type of element can be set in any order in the file.
// ◦ Elements which are defined by a capital letter can only be declared once in
// the scene.
