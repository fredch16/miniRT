/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_vec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:42:46 by atyurina          #+#    #+#             */
/*   Updated: 2024/11/13 20:49:17 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

bool	check_vec(char *vec, bool	ret, t_tuple *tuple)
{
	char	**a;

	if (!is_vec(vec))
	{
		ft_putstr_fd("Incorrect vector coordinates\n It is not a vector\n", 2);
		ft_putstr_fd("Wrong formatting\n", 2);
		ret = false;
	}
	else
	{
		a = ft_split(vec, ',');
		*tuple = tuple_vec(ft_atof(a[0]), ft_atof(a[1]), ft_atof(a[2]));
		if (!in_range(tuple->x) || !in_range(tuple->y) || !in_range(tuple->z))
			ret = false;
		if ((!equal(tuple_abs(*tuple), 1)))
		{
			ft_putstr_fd("Incorrect vector coordinates\nThe vector ", 2);
			ft_putstr_fd("is not normalized (magnitude is not 1)\n\n", 2);
			ret = false;
		}
		free_double_array(a);
	}
	return (ret);
}

bool	set_vec(char *vec, t_tuple *tuple)
{
	bool	ret;

	ret = true;
	ret = check_vec(vec, ret, tuple);
	return (ret);
}

bool	set_norm_vec(char *vec, t_tuple *tuple)
{
	bool	ret;

	ret = true;
	ret = check_norm_vec(vec, ret, tuple);
	return (ret);
}

//in range [-1,1] for each x,y,z axis:
bool	in_range(double d)
{
	if (d < -1 || d > 1)
	{
		ft_putstr_fd("Vector coordinates are out of range\n", 2);
		ft_putstr_fd("Please, set in range [-1,1] for each x,y,z axis\n", 2);
		return (false);
	}
	return (true);
}

//check if line contains norm vec 
bool	is_vec(char *line)
{
	char	**coord;
	int		i;
	bool	ret;

	ret = true;
	i = 0;
	coord = ft_split(line, ',');
	while (coord[i])
	{
		if (!is_dbl(coord[i]))
		{
			ret = false;
		}
		i++;
	}
	if (i != 3)
	{
		ret = false;
	}
	free_double_array(coord);
	return (ret);
}
