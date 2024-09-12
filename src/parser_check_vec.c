/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_vec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:42:46 by atyurina          #+#    #+#             */
/*   Updated: 2024/09/12 12:49:13 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

bool	set_vec(const char *line, int i, int j, t_tuple *tuple)
{
	char	*vec;
	char	**a;
	bool	ret;

	ret = true;
	vec = (char *)malloc((j - i + 1) * sizeof(char));
	ft_strlcpy(vec, line + i, j - i + 1);
	if (!is_vec(vec))
	{
		ft_putstr_fd("Incorrect vector coordinates\n", 2);
		ret = false;
	}
	a = ft_split(vec, ',');
	*tuple = tuple_vec(ft_atof(a[0]), ft_atof(a[1]), ft_atof(a[2]));
	if (!in_range(tuple->x) || !in_range(tuple->y) || !in_range(tuple->z))
		ret = false;
	if (fabs(tuple_abs(*tuple) - 1.0) > EPSILON)
	{
		ft_putstr_fd("Incorrect vector coordinates\nThe vector ", 2);
		ft_putstr_fd("is not normalized (magnitude is not 1)\n\n", 2);
		ret = false;
	}
	free_double_array(a);
	free(vec);
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
			ret = false;
		i++;
	}
	if (i != 3)
		ret = false;
	free_double_array(coord);
	return (ret);
}
