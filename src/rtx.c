/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:16:31 by fcharbon          #+#    #+#             */
/*   Updated: 2024/09/11 22:06:38 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"
#include <stdbool.h>

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
	}
	//ok here we start to move things from parser to useable info 
	//ambient lighting
	//camera related

	t_camera	c = camera_construct(WIN_WIDTH, WIN_HEIGHT, (parser.camera.fov * (PI / 180)));
	t_tuple	from = parser.camera.view_point;
	t_tuple	to = tuple_add(from, parser.camera.orientation_vector);
	// t_tuple	from = tuple_poi(-5, 20.5, -17);
	// t_tuple	to = tuple_poi(0, 2, 0);
	t_tuple	up = tuple_vec(0, 1, 0);
	pixel_size(&c);
	c.transform = view_transform(from, to, up);
	matrix_det_4(&c.transform);
	c.trans_inverse = matrix_inverse(&c.transform);
	w.c = c;

	//lighting

	// tuple_print(parser.light.light_point);
	// printf("light brightness = %f\n", parser.light.brightness);
	w.point_light.position = parser.light.light_point;
	//remember to include brightness
	w.point_light.intensity = colour_set(1, 1, 1);

	data.w = &w;
	t_obj	*obj_list;
	obj_list = NULL;
	data.w->obj_list = &obj_list;
	data_for_obj(&parser, &data);
	t_obj	*testobj;
	testobj = *w.obj_list;
	while (testobj->next)
	{
		printf("2\n");
		testobj = testobj->next;
	}

	free_objects_memory(&parser);
	init_mlx(&data, c, &w);
	return (1);
}

