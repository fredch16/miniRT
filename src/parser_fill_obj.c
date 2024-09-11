/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fill_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:28:54 by atyurina          #+#    #+#             */
/*   Updated: 2024/09/11 21:36:55 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

int	fill_sphere(char *line, t_sp *sphere)
{
	int	s;
	int	e;

	s = get_start(line, 3);
	e = get_end(line, s);
	if (s == e || !set_coord(line, s, e, &sphere->center))
		return (0);
	s = get_start(line, e);
	e = get_end(line, s);
	if (s == e || !set_dbl(line, s, e, &sphere->diameter))
		return (0);
	s = get_start(line, e);
	e = get_end(line, s);
	if (s == e || !set_rgb(line, e, s, &sphere->col))
		return (0);
	return (1);
}

int	fill_plane(char *line, t_pl	*plane)
{
	int	s;
	int	e;

	s = get_start(line, 3);
	e = get_end(line, s);
	if (s == e || !set_coord(line, s, e, &plane->point))
		return (0);
	s = get_start(line, e);
	e = get_end(line, s);
	if (s == e || !set_vec(line, s, e, &plane->norm_axis_vec))
		return (0);
	s = get_start(line, e);
	e = get_end(line, s);
	if (s == e || !set_rgb(line, e, s, &plane->col))
		return (0);
	return (1);
}

int	fill_cylinder(char *line, t_cy	*cylinder)
{
	int	s;
	int	e;

	s = get_start(line, 3);
	e = get_end(line, s);
	if (s == e || !set_coord(line, s, e, &cylinder->center))
		return (0);
	s = get_start(line, e);
	e = get_end(line, s);
	if (s == e || !set_vec(line, s, e, &cylinder->norm_axis_vec))
		return (0);
	s = get_start(line, e);
	e = get_end(line, s);
	if (s == e || !set_dbl(line, s, e, &cylinder->diameter))
		return (0);
	s = get_start(line, e);
	e = get_end(line, s);
	if (s == e || !set_dbl(line, s, e, &cylinder->height))
		return (0);
	s = get_start(line, e);
	e = get_end(line, s);
	if (s == e || !set_rgb(line, e, s, &cylinder->col))
		return (0);
	return (1);
}
