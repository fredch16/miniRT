/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_set_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:00:47 by atyurina          #+#    #+#             */
/*   Updated: 2024/11/12 15:51:07 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

int	set_ambient(char *line, t_parser *parser)
{
	char	**tokens;
	int		success;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	success = tokens[0] && set_dbl(tokens[0], &parser->ambient.val) \
				&& parser->ambient.val >= 0.0 && parser->ambient.val <= 1.0 \
				&& tokens[1] && set_rgb(tokens[1], &parser->ambient.col);
	if (!success)
		ft_putstr_fd("Ambient lighting ratio is out of range\n", 2);
	free_tokens(tokens);
	return (success);
}

int	set_camera(char *line, t_parser *parser)
{
	char	**tokens;
	int		success;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	success = tokens[0] && set_coord(tokens[0], &parser->camera.view_point) \
				&& tokens[1] && set_vec(tokens[1], \
				&parser->camera.orientation_vector) \
				&& tokens[2] && set_dbl(tokens[2], &parser->camera.fov) \
				&& parser->camera.fov >= 0.0 && parser->camera.fov <= 180.0;
	if (!success)
		ft_putstr_fd("Camera FOV (field of view) is out of range [0,180]\n", 2);
	free_tokens(tokens);
	return (success);
}

int	set_light(char *line, t_parser *parser)
{
	char	**tokens;
	int		success;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	success = tokens[0] && set_coord(tokens[0], &parser->light.light_point) \
				&& tokens[1] && set_dbl(tokens[1], &parser->light.brightness) \
				&& parser->light.brightness >= 0.0 \
				&& parser->light.brightness <= 1.0;
	if (!success)
		ft_putstr_fd("Light brightness ratio is out of range [0.0,1.0]\n", 2);
	free_tokens(tokens);
	return (success);
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
			count += set_ambient(scene[i] + 2, parser);
		else if (ft_strncmp(scene[i], "C ", 2) == 0)
			count += set_camera(scene[i] + 2, parser);
		else if (ft_strncmp(scene[i], "L ", 2) == 0)
			count += set_light(scene[i] + 2, parser);
		else if (ft_strncmp(scene[i], "sp ", 3) == 0)
			count += set_sphere(scene[i] + 2, parser);
		else if (ft_strncmp(scene[i], "pl ", 3) == 0)
			count += set_plane(scene[i] + 3, parser);
		else if (ft_strncmp(scene[i], "cy ", 3) == 0)
			count += set_cylinder(scene[i] + 3, parser);
		i++;
		if (count != i)
			return (false);
	}
	return (true);
}
