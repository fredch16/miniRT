/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_rgb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:59:37 by atyurina          #+#    #+#             */
/*   Updated: 2024/11/12 14:55:11 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

bool	set_rgb(char *rgb, t_colour *col)
{
	char	**a;

	if (!is_rgb(rgb))
	{
		ft_putstr_fd("Incorrect ambient lighting RGB\n", 2);
		return (false);
	}
	a = ft_split(rgb, ',');
	*col = colour_set(ft_atof(a[0]) / 255, \
	ft_atof(a[1]) / 255, ft_atof(a[2]) / 255);
	free_double_array(a);
	return (true);
}

bool	check_rbg_format(char *line)
{
	int	i;

	i = 0;
	while (line[i] >= '0' && line[i] <= '9' && line[i])
		i++;
	if (line[i] == ',' && line[i])
		i++;
	while (line[i] >= '0' && line[i] <= '9' && line[i])
		i++;
	if (line[i] == ',' && line[i])
		i++;
	while (line[i] >= '0' && line[i] <= '9' && line[i])
		i++;
	if (line[i] != '\0')
		return (false);
	return (true);
}

//check if line is rgb
bool	is_rgb(char *line)
{
	char	**rgb;
	int		num;
	int		i;
	bool	ret;

	if (check_rbg_format(line) == false)
		return (false);
	rgb = ft_split(line, ',');
	i = 0;
	ret = true;
	while (rgb[i])
	{
		num = ft_atoi(rgb[i]);
		if (num < 0 || num > 255)
			ret = false;
		i++;
	}
	if (i != 3)
		ret = false;
	free_double_array(rgb);
	return (ret);
}

void	free_double_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
