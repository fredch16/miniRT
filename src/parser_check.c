/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:34:02 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/25 13:11:15 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

bool	file_check_rt(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 3] != '.' || file[len - 2] != 'r' || file[len - 1] != 't')
		return (true);
	else
		return (false);
}

static int	times_met(char **text, char a)
{
	int	i;
	int	j;
	int	res;

	res = 0;
	i = 0;
	while (text[i] != NULL)
	{
		j = 0;
		while (text[i][j])
		{
			if (text[i][j] == a)
				res++;
			j++;
		}
		i++;
	}
	return (res);
}

bool	file_check_capital(char **text)
{
	int	a;
	int	c;
	int	l;

	a = times_met(text, 'A');
	c = times_met(text, 'C');
	l = times_met(text, 'L');
	if (a != 1 || c != 1 || l != 1)
	{
		ft_putstr_fd("Error\nElements which are defined by a capital letter have to be declared once in the scene.\n", 2);
		return (false);
	}
	else
		return (true);
}

bool	file_check_error(char **text)
{
	if (file_check_capital(text) == false)
		return (false);
	return (true);
}

/**
 * 1) check if A, C, L, pl, sp, cy or line with spaces. If smth else -> Error
 * 2) check separately data of each: A, C, L, pl, sp, cy. If wrong data -> Error
*/

// Program must take as a first argument a scene description file with the .rt
// extension.
// ◦ Each type of element can be separated by one or more line break(s).
// ◦ Each type of information from an element can be separated by one or more
// space(s).
// ◦ Each type of element can be set in any order in the file.
// ◦ Elements which are defined by a capital letter can only be declared once in
// the scene.
