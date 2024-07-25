/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:16:31 by fcharbon          #+#    #+#             */
/*   Updated: 2024/07/25 15:11:14 by fcharbon         ###   ########.fr       */
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

	
	//green
	t_obj	*obj;
	w.obj_list = &obj;
	obj = obj_create(OT_SPHERE);
	obj_add_back(&obj_list, obj);
	matrix_set_translation(&translate_sp, -0.5, 1, 0.5);
	obj->material.colour = colour_set(0.1, 1, 0.5);
	obj->material.diffuse = 0.7;
	obj->material.specular = 0.3;
	sphere_set_transform(obj, &translate_sp, &scale_sp);
	
	//lime
	t_obj	*obj2;
	t_matrix endlime;
	obj2 = obj_create(OT_SPHERE);
	obj_add_back(&obj_list, obj2);
	matrix_set_translation(&translate_sp, 1.5, 0.5, -0.5);
	matrix_set_scaling(&scale_sp, 0.5, 0.5, 0.5);
	matrix_multiply_matrix(&translate_sp, &scale_sp, &endlime);
	obj2->material.colour = colour_set(0.5, 1, 0.1);
	obj2->material.diffuse = 0.7;
	obj2->material.specular = 0.3;
	sphere_set_transform(obj2, &endlime, &scale_sp);

	//gray floor
	// t_obj *obj3;
	// obj3 = obj_create(OT_SPHERE);
	// obj_add_back(&obj_list, obj3);
	// obj3->material.colour = colour_set(1, 0.9, 0.9);
	// obj3->material.specular = 0;
	// matrix_set_scaling(&scale_sp, 10, 0.01, 10);
	// sphere_set_transform(obj3, &scale_sp, &translate_sp);

	//gray floor but as plane
	t_obj *obj3;
	obj3 = obj_create(OT_PLANE);
	obj_add_back(&obj_list, obj3);
	obj3->material.colour = colour_set(1, 0.9, 0.9);
	obj3->material.specular = 0;
	
	//beige right wall
	// t_obj *obj4;
	// t_matrix yrota;
	// t_matrix xrota;
	// t_matrix out1;
	// t_matrix out2;
	// t_matrix out3;
	// obj4 = obj_create(OT_SPHERE);
	// obj_add_back(&obj_list, obj4);
	// obj4->material.colour = colour_set(1, 0.9, 0.9);
	// obj4->material.specular = 0;
	// matrix_set_scaling(&scale_sp, 10, 0.01, 10);
	// matrix_set_translation(&translate_sp, 0, 0, 5);
	// matrix_set_rotation_y(&yrota, PI / 4);
	// matrix_set_rotation_x(&xrota, PI / 2);
	// matrix_multiply_matrix(&translate_sp, &yrota, &out1);
	// matrix_multiply_matrix(&out1, &xrota, &out2);
	// matrix_multiply_matrix(&out2, &scale_sp, &out3);
	// sphere_set_transform(obj4, &out3, &translate_sp);

	//beige right wall
	// t_obj *obj5;
	// obj5 = obj_create(OT_SPHERE);
	// obj_add_back(&obj_list, obj5);
	// obj5->material.colour = colour_set(1, 0.9, 0.9);
	// obj5->material.specular = 0;
	// matrix_set_scaling(&scale_sp, 10, 0.01, 10);
	// matrix_set_translation(&translate_sp, 0, 0, 5);
	// matrix_set_rotation_y(&yrota, -PI / 4);
	// matrix_set_rotation_x(&xrota, PI / 2);
	// matrix_multiply_matrix(&translate_sp, &yrota, &out1);
	// matrix_multiply_matrix(&out1, &xrota, &out2);
	// matrix_multiply_matrix(&out2, &scale_sp, &out3);
	// sphere_set_transform(obj5, &out3, &translate_sp);

	//yellow
	t_obj	*obj6;
	obj6 = obj_create(OT_SPHERE);
	obj_add_back(&obj_list, obj6);
	matrix_set_translation(&translate_sp, -1.5, 0.33, -0.75);
	matrix_set_scaling(&scale_sp, 0.33, 0.33, 0.33);
	matrix_multiply_matrix(&translate_sp, &scale_sp, &endlime);
	obj6->material.colour = colour_set(1, 0.8, 0.1);
	obj6->material.diffuse = 0.7;
	obj6->material.specular = 0.3;
	sphere_set_transform(obj6, &endlime, &scale_sp);


	//TEST ENV
	

	w.point_light.position = tuple_poi(-10, 10, -10);
	w.point_light.intensity = colour_set(1, 1, 1);
	// t_material mat;
	// mat = material_set_default();
	// t_colour res = lighting(&mat, &w.point_light, true);
	// printf("Colour is %.2f, %.2f, %.2f\n", res.r, res.g, res.b);

	// t_ray ray;
	// ray_create(&ray, tuple_poi(0, -1, 0), tuple_vec(0, 1, 0));
	// t_xsn *xs;
	// xs = intersect_pl(ray, obj3);
	// if (xs == NULL)
	// 	printf("No intersect!\n");
	// else
	// {
	// 	printf("Intesect! Found at: t = %.3f\n", xs->x);
	// }

	t_tuple	n1;
	t_tuple	n2;
	t_tuple	n3;

	t_tuple	p1;
	t_tuple	p2;
	t_tuple	p3;

	p1 = tuple_poi(0, 0, 0);
	p2 = tuple_poi(10, 0, -18);
	p3 = tuple_poi(-35, 0, 65);
	n1 = plane_normal_at(obj3, &p1);
	n2 = plane_normal_at(obj3, &p2);
	n3 = plane_normal_at(obj3, &p3);
	tuple_print(n1);
	tuple_print(n2);
	tuple_print(n3);
	t_camera	c = camera_construct(WIN_WIDTH, WIN_HEIGHT, PI / 3);
	pixel_size(&c);
	t_tuple	from = tuple_poi(0, 1.5, -10);
	t_tuple	to = tuple_poi(0, 1, 0);
	t_tuple	up = tuple_vec(0, 1, 0);
	c.transform = view_transform(from, to, up);
	matrix_det_4(&c.transform);
	c.trans_inverse = matrix_inverse(&c.transform);
	// matrix_print(&view);

	init_mlx(&data, c, &w);
}
