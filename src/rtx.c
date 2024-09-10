/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:16:31 by fcharbon          #+#    #+#             */
/*   Updated: 2024/09/10 11:46:57 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"
#include <stdbool.h>

void	free_objects_memory(t_parser *parser)
{
	t_sp	*sp_tmp;
	t_pl	*pl_tmp;
	t_cy	*cy_tmp;

	while (parser->sphere_nbr > 0)
	{
		sp_tmp = parser->sphere;
		parser->sphere = parser->sphere->next;
		free (sp_tmp);
		parser->sphere_nbr--;
	}
	while (parser->plane_nbr > 0)
	{
		pl_tmp = parser->plane;
		parser->plane = parser->plane->next;
		free (pl_tmp);
		parser->plane_nbr--;
	}
	while (parser->cylinder_nbr > 0)
	{
		cy_tmp = parser->cylinder;
		parser->cylinder = parser->cylinder->next;
		free (cy_tmp);
		parser->cylinder_nbr--;
	}
}

int	main(int argc, char **argv)
{
	t_world w;
	t_data	data;

	char		**scene;
	t_parser	parser;

	if (argc > 2 || argc < 2)
	{
		ft_message_error("Error\nYou need to pass file with .rt extension.\n");
	}
	if (argc == 2)
	{
		scene = file_read(argv[1]);
		int i = 0;
		while (scene[i] != NULL)
		{
			ft_putstr_fd(scene[i], 1);
			ft_putchar_fd('\n', 1);
			i++;
		}
		file_check_error(scene);
		set_data(scene, &parser);
		// if (set_data(scene, &parser) == true)
		// 	execute_rt(parser);
		free_text(scene);
		free_objects_memory(&parser);
	}

	//ok here we start to move things from parser to useable info 
	
	//camera related
	t_camera	c = camera_construct(WIN_WIDTH, WIN_HEIGHT, (parser.camera.fov * (PI / 180)));
	t_tuple	from = parser.camera.view_point;
	t_tuple	to = tuple_add(from, parser.camera.orientation_vector);
	t_tuple	up = tuple_vec(0, 1, 0);
	pixel_size(&c);
	c.transform = view_transform(from, to, up);
	matrix_det_4(&c.transform);
	c.trans_inverse = matrix_inverse(&c.transform);
	w.c = c;

	//lighting
	w.point_light.position = parser.light.light_point;
	//remember to include brightness
	w.point_light.intensity = colour_set(1, 1, 1);

	init_mlx(&data, c, &w);
	return (1);
}
