/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_element.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:37:12 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/15 12:44:28 by atyurina         ###   ########.fr       */
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

int	times_met(char **text, char a)
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
		ft_putstr_fd("Error\nElements which are defined by a capital", 2);
		ft_putstr_fd(" letter have to be declared once in the scene.\n", 2);
		return (false);
	}
	else
		return (true);
}

bool	file_check_line(char **line)
{
	int	i;

	i = 0;
	while (line[i] != NULL)
	{
        /**
         * functions for each line format check
        */
		i++;
	}
	return (true);
}

int	is_space(int c)
{
	if (((c >= 9 && c <= 13) || c == 32))
		return (1);
	else
		return (0);
}
