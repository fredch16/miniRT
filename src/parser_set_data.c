/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_set_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:00:47 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/24 16:51:34 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"
/*
//checks if line is an rgb line
//returns 1 if success, 0 otherwise
int	is_rgb(char *line)
{
	char	**rgb;
	int		num;
	int		i;
	int		ret;

	rgb = ft_split(line, ',');
	i = 0;
	ret = 1;
	while (rgb[i])
	{
		num = ft_atoi(rgb[i]);
		if (num < 0 || num > 255)
			ret = 0;
		i++;
	}
	if (i != 3)
		ret = 0;
	free_double_array(rgb);
	return (ret);
}
*/


/**
 * это сделано ->
 * здесь нужно проверить дабл перед передачи его в ft_atof
 * (пробелы, знаки, любые другие рандомные не подходяшие буквы и тд)
 * и собственно так установить значение
 * затем пройти еще пробелы и проверить rgb и установить
 * return 0 if failed, return 1 if success
*/

// int	set_ambient(char *line, t_parser *parser)
// {
// 	int		i;
// 	int		j;

// 	i = 2; //start after "A ";
// 	while (is_space(line[i]) && line[i] != '\0')//i is beginning, j is end
// 		i++;
// 	j = i;
// 	while (!is_space(line[j]) && line[j] != '\0')
// 		j++;
// 	if (i == j || set_dbl(line, i, j, &parser->ambient.val) == false)
// 		return (0);
// 	if (parser->ambient.val < 0.0 || parser->ambient.val > 1)
// 		{
// 			ft_putstr_fd("Ambient lighting ratio is out of range\n", 2);
// 			return (0);
// 		}
// 	while (is_space(line[j]) && line[j] != '\0') ///j is beginning, i is end
// 		j++;
// 	i = j;
// 	while (!is_space(line[i]) && line[i] != '\0')
// 		i++;
// 	if (i != j && set_rgb(line, i, j, &parser->ambient.col))
// 		return (1);
// 	return (0);
// }

int	set_ambient(char *line, t_parser *parser)
{
	int		s;
	int		e;

	s = get_start(line, 2); // after "A "
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
	if (s == e || !set_coord(line, s, e, parser->camera.view_point))
		return (0);
	s = get_start(line, e);
	e = get_end(line, s);
	if (s == e || !set_vec(line, s, e, parser->camera.orientation_vector))
		return (0);
	s = get_start(line, e);
	e = get_end(line, s);
	if (s == e || !set_dbl(line, s, e, parser->camera.fov))
		return (0)
	if (parser->camera.fov < 0 || parser->camera.fov > 180)
	{
		ft_putstr_fd("Camera FOV (field of view) is out of range [0,180]\n", 2);
		return (0)
	}
	return(1);
}

int	set_light(char *line, t_parser *parser)
{
	int	s;
	int	e;

	s = get_start(line, 2);
	e = get_end(line, s);
	if (s == e || !set_coord(line, s, e, parser->light.light_point))
		return (0);
	s = get_start(line, e);
	e = get_end(line, s);
	if (s == e || !set_dbl(line, s, e, parser->light.brightness))
		return (0)
	if (parser->light.brightness < 0 || parser->light.brightness > 1)
	{
		ft_putstr_fd("Light brightness ratio is out of range [0.0,1.0]\n", 2);
		return (0)
	}
	return(1);
}

void	set_next_null(t_parser *parser)
{
	parser->sphere->next = NULL;
	parser->plane->next = NULL;
	parser->cylinder->next = NULL;
}

bool	set_data(char **scene, t_parser *parser)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	set_next_null(parser);
	while (scene[i] != NULL && i == 0)
	{
		if (ft_strncmp(scene[i], "A ", 2) == 0)
			count += set_ambient(scene[i], parser);
		// printf("count = %i", count);
		// printf("ambient val = %f. r = %f, g = %f, b = %f", parser->ambient.val, parser->ambient.col.r, parser->ambient.col.g, parser->ambient.col.b);
		else if (ft_strncmp(scene[i], "C ", 2) == 0)
			count += set_camera(scene[i], parser);
		else if (ft_strncmp(scene[i], "L ", 2) == 0)
			count += set_light(scene[i], parser);
		// else if(ft_strncmp(scene[i], "sp ", 3) == 0)
		// 	count += set_sphere(scene[i], parser);
		// else if (ft_strncmp(scene[i], "pl ", 3) == 0)
		// 	count += set_plane(scene[i], parser);
		// else if (ft_strncmp(scene[i], "cy ", 3) == 0)
		// 	count += set_cylinder(scene[i], parser);
		i++;
		if (count != i)
			return (false);
	}
	return (true);
}