/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:16:31 by fcharbon          #+#    #+#             */
/*   Updated: 2024/07/24 20:26:54 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

int	main(void)
{
	t_data	data;
	t_obj	*obj_list;
	t_world		w;
	t_matrix	translate_sp;
	t_matrix	scale_sp;

	data.w = &w;
	// (void)data;
	obj_list = NULL;

	matrix_set_4(&translate_sp);
	matrix_set_4(&scale_sp);
	
	//default1
	t_obj	*obj;
	w.obj_list = &obj;
	obj = obj_create(OT_SPHERE);
	obj_add_back(&obj_list, obj);
	obj->material.colour = colour_set(0.8, 1, 0.6);
	obj->material.diffuse = 0.7;
	obj->material.specular = 0.2;
	
	//default2
	t_obj	*obj2;
	obj2 = obj_create(OT_SPHERE);
	obj_add_back(&obj_list, obj2);
	matrix_set_scaling(&scale_sp, 0.5, 0.5, 0.5);
	obj2->material = material_set_default();
	sphere_set_transform(obj2, &scale_sp, &scale_sp);



	//TEST ENV

	w.point_light.position = tuple_poi(-10, 10, -10);
	w.point_light.intensity = colour_set(1, 1, 1);
	// bool shadow = in_shadow(&w, tuple_vec(-2, 2, -2));
	// shadow += 0;
	// if (shadow == true)
	// 	printf("in the shadow\n");
	// else
	// 	printf("NOT in the shadow\n");
	// t_colour res = lighting(&mat, &w.point_light, true);
	// printf("Colour is %.2f, %.2f, %.2f\n", res.r, res.g, res.b);

	t_camera	c = camera_construct(WIN_WIDTH, WIN_HEIGHT, PI / 3);
	pixel_size(&c);
	t_tuple	from = tuple_poi(0, 1.5, -5);
	t_tuple	to = tuple_poi(0, 1, 0);
	t_tuple	up = tuple_vec(0, 1, 0);
	c.transform = view_transform(from, to, up);
	matrix_det_4(&c.transform);
	c.trans_inverse = matrix_inverse(&c.transform);
	// matrix_print(&view);

	init_mlx(&data, c, &w);
}
