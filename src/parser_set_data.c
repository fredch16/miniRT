/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_set_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:00:47 by atyurina          #+#    #+#             */
/*   Updated: 2024/09/13 17:05:43 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

int	set_ambient(char *line, t_parser *parser)
{
	int		s;
	int		e;

	s = get_start(line, 2);
	e = get_end(line, s);
	if (s == e || set_dbl(line, s, e, &parser->ambient.val) == false)
		return (0);
	if (parser->ambient.val < 0.0 || parser->ambient.val > 1)
	{
		ft_putstr_fd("Ambient lighting ratio is out of range\n", 2);
		return (0);
	}
	s = get_start(line, e);
	e = get_end(line, s);
	if (s != e && set_rgb(line, e, s, &parser->ambient.col))
		return (1);
	return (0);
}

int	set_camera(char *line, t_parser *parser)
{
	int	s;
	int	e;

	s = get_start(line, 2);
	e = get_end(line, s);
	if (s == e || !set_coord(line, s, e, &parser->camera.view_point))
		return (0);
	s = get_start(line, e);
	e = get_end(line, s);
	if (s == e || !set_vec(line, s, e, &parser->camera.orientation_vector))
		return (0);
	s = get_start(line, e);
	e = get_end(line, s);
	if (s == e || !set_dbl(line, s, e, &parser->camera.fov))
		return (0);
	if (parser->camera.fov < 0 || parser->camera.fov > 180)
	{
		ft_putstr_fd("Camera FOV (field of view) is out of range [0,180]\n", 2);
		return (0);
	}
	return (1);
}

int	set_light(char *line, t_parser *parser)
{
	int	s;
	int	e;

	s = get_start(line, 2);
	e = get_end(line, s);
	if (s == e || !set_coord(line, s, e, &parser->light.light_point))
		return (0);
	s = get_start(line, e);
	e = get_end(line, s);
	if (s == e || !set_dbl(line, s, e, &parser->light.brightness))
		return (0);
	if (parser->light.brightness < 0 || parser->light.brightness > 1)
	{
		ft_putstr_fd("Light brightness ratio is out of range [0.0,1.0]\n", 2);
		return (0);
	}
	return (1);
}

void	set_zeros_obj(t_parser *parser)
{
	parser->sphere_nbr = 0;
	parser->plane_nbr = 0;
	parser->cylinder_nbr = 0;
	parser->sphere = NULL;
	parser->plane = NULL;
	parser->cylinder = NULL;
}

bool	set_data(char **scene, t_parser *parser)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	set_zeros_obj(parser);
	while (scene[i] != NULL)
	{
		if (ft_strncmp(scene[i], "A ", 2) == 0)
			count += set_ambient(scene[i], parser);
		else if (ft_strncmp(scene[i], "C ", 2) == 0)
			count += set_camera(scene[i], parser);
		else if (ft_strncmp(scene[i], "L ", 2) == 0)
			count += set_light(scene[i], parser);
		else if (ft_strncmp(scene[i], "sp ", 3) == 0)
			count += set_sphere(scene[i], parser);
		else if (ft_strncmp(scene[i], "pl ", 3) == 0)
			count += set_plane(scene[i], parser);
		else if (ft_strncmp(scene[i], "cy ", 3) == 0)
			count += set_cylinder(scene[i], parser);
		i++;
		if (count != i)
			return (false);
	}
	return (true);
}
