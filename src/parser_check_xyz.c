/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_xyz.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:02:41 by atyurina          #+#    #+#             */
/*   Updated: 2024/11/12 15:34:54 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

bool	set_coord(char *coord, t_tuple *point)
{
	char	**a;

	if (!is_coord(coord))
	{
		ft_putstr_fd("Incorrect x,y,z coordinates\n", 2);
		return (false);
	}
	a = ft_split(coord, ',');
	*point = tuple_poi(ft_atof(a[0]), ft_atof(a[1]), ft_atof(a[2]));
	free_double_array(a);
	return (true);
}

//check if line contains x,y,z coordinates
bool	is_coord(char *line)
{
	char	**coord;
	int		i;
	bool	ret;

	i = 0;
	ret = true;
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
