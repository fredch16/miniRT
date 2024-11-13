/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_set_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:26:05 by atyurina          #+#    #+#             */
/*   Updated: 2024/11/13 20:51:42 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

int	set_sphere(char *line, t_parser *parser)
{
	t_sp	*new_sphere;
	t_sp	*ptr;

	ptr = parser->sphere;
	new_sphere = malloc(sizeof(t_sp));
	if (fill_sphere(line, new_sphere) == 0)
	{
		free (new_sphere);
		return (0);
	}
	new_sphere->next = NULL;
	if (parser->sphere_nbr == 0)
		parser->sphere = new_sphere;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new_sphere;
	}
	parser->sphere_nbr++;
	return (1);
}

int	set_plane(char *line, t_parser *parser)
{
	t_pl	*new_plane;
	t_pl	*ptr;

	ptr = parser->plane;
	new_plane = malloc(sizeof(t_pl));
	if (fill_plane(line, new_plane) == 0)
	{
		free(new_plane);
		return (0);
	}
	new_plane->next = NULL;
	if (parser->plane_nbr == 0)
		parser->plane = new_plane;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new_plane;
	}
	parser->plane_nbr++;
	return (1);
}

int	set_cylinder(char *line, t_parser *parser)
{
	t_cy	*new_cylinder;
	t_cy	*ptr;

	ptr = parser->cylinder;
	new_cylinder = malloc(sizeof(t_cy));
	if (fill_cylinder(line, new_cylinder) == 0)
	{
		free(new_cylinder);
		return (0);
	}
	new_cylinder->next = NULL;
	if (parser->cylinder_nbr == 0)
		parser->cylinder = new_cylinder;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new_cylinder;
	}
	parser->cylinder_nbr++;
	return (1);
}

bool	check_norm_vec(char *vec, bool	ret, t_tuple *tuple)
{
	char	**a;

	if (!is_vec(vec))
	{
		ft_putstr_fd("Wrong n-vector coordinates\n It is not a vector\n", 2);
		ft_putstr_fd("Wrong formatting\n", 2);
		ret = false;
	}
	else
	{
		a = ft_split(vec, ',');
		*tuple = tuple_vec(ft_atof(a[2]), ft_atof(a[1]), ft_atof(a[0]));
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
