/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_rgb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:59:37 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/27 14:42:38 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

bool	set_rgb(char *line, int e, int s, t_colour *col)
{
	char	**a;
	char	*rgb;

	rgb = (char *)malloc((e - s + 1) * sizeof(char));
	ft_strlcpy(rgb, line + s, e - s + 1);
	if (!is_rgb(rgb))
	{
		free(rgb);
		ft_putstr_fd("Incorrect ambient lighting RGB\n", 2);
		return (false);
	}
	a = ft_split(rgb, ',');
	*col = colour_set(ft_atoi(a[0]), ft_atoi(a[1]), ft_atoi(a[2]));
	free_double_array(a);
	free(rgb);
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
