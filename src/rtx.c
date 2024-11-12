/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:16:31 by fcharbon          #+#    #+#             */
/*   Updated: 2024/11/12 13:05:06 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"
#include <stdbool.h>

void	set_objs(t_parser parser, t_world w, t_obj	*obj_list)
{
	t_data			data;
	t_view_params	v;
	t_camera		c;

	c = camera_construct(W_WIDTH, W_HEIGHT, (parser.camera.fov * (PI / 180)));
	v.from = parser.camera.view_point;
	v.to = tuple_add(v.from, parser.camera.orientation_vector);
	v.up = tuple_vec(0, 1, 0);
	if (parser.camera.orientation_vector.y == -1)
		v.up = tuple_vec(0, 0, 1);
	if (parser.camera.orientation_vector.y == 1)
		v.up = tuple_vec(0, 0, 1);
	pixel_size(&c);
	c.transform = view_transform(v.from, v.to, v.up);
	matrix_det_4(&c.transform);
	c.trans_inverse = matrix_inverse(&c.transform);
	w.c = c;
	w.point_light.position = parser.light.light_point;
	w.point_light.intensity = colour_set(1, 1, 1);
	data.w = &w;
	data.w->obj_list = &obj_list;
	data_for_obj(&parser, &data);
	free_objects_memory(&parser);
	init_mlx(&data, c, &w);
}

int	main(int argc, char **argv)
{
	char		**scene;
	t_parser	parser;
	t_world		w;
	t_obj		*obj_list;

	if (argc > 2 || argc < 2)
		ft_message_error("Error\nYou need to pass file with .rt extension.\n");
	if (argc == 2)
	{
		scene = file_read(argv[1]);
		file_check_error(scene);
		if (set_data(scene, &parser) == false)
		{
			printf("THERE WAS AN ERROR ON PARSER STAGE\n");
			free_text(scene);
			free_objects_memory(&parser);
			exit (2);
		}
		free_text(scene);
	}
	w.px_count = 0;
	obj_list = NULL;
	set_objs(parser, w, obj_list);
}

		/* output scene: */
		// int i = 0;
		// while (scene[i] != NULL)
		// {
		// 	ft_putstr_fd(scene[i], 1);
		// 	ft_putchar_fd('\n', 1);
		// 	i++;
		// }