/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_set_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:26:05 by atyurina          #+#    #+#             */
/*   Updated: 2024/09/11 13:57:44 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

int	set_sphere(char *line, t_parser *parser)
{
	t_sp	*new_sphere;

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
		while (parser->sphere->next != NULL)
			parser->sphere = parser->sphere->next;
		parser->sphere->next = new_sphere;
	}
	parser->sphere_nbr++;
	return (1);
}

int	set_plane(char *line, t_parser *parser)
{
	t_pl	*new_plane;

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
		while (parser->plane->next != NULL)
			parser->plane = parser->plane->next;
		parser->plane->next = new_plane;
	}
	parser->plane_nbr++;
	return (1);
}

int	set_cylinder(char *line, t_parser *parser)
{
	t_cy	*new_cylinder;

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
		while (parser->cylinder->next != NULL)
			parser->cylinder = parser->cylinder->next;
		parser->cylinder->next = new_cylinder;
	}
	parser->cylinder_nbr++;
	return (1);
}
