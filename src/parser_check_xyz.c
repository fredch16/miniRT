/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_xyz.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:02:41 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/23 17:23:25 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

bool	set_coord(const char *line, int i, int j, t_tuple *point)
{
	char	*coord;
	char	**a;

	coord = (char *)malloc((j - i + 1) * sizeof(char));
	ft_strlcpy(coord, line + i, j - i + 1);
	if (!is_coord(coord))
	{
		free(coord);
		ft_putstr_fd("Incorrect x,y,z coordinates\n", 2);
		return (false);
	}
	a = ft_split(coord, ',');
	*point = tuple_poi(ft_atoi(a[0]), ft_atoi(a[1]), ft_atoi(a[2]));
	free_double_array(a);
	free(coord);
	return (true);
}

//check if line is rgb
bool	is_coord(char *line)
{
	char	**coord;
	int		num;
	int		i;
	bool	ret;

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