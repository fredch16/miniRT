/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:16:31 by fcharbon          #+#    #+#             */
/*   Updated: 2024/07/26 15:49:51 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"
#include <stdbool.h>

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
	
	//cylinder green
	t_obj		*obj;
	w.obj_list = &obj;
	obj = obj_create(OT_SPHERE);
	obj_add_back(&obj_list, obj);
	obj->material.colour = colour_set(0.1, 1, 0.5);
	obj->material.diffuse = 0.7;
	obj->material.specular = 0.3;
	obj->min = 0;
	obj->max = 2;
	t_matrix bigger;
	// matrix_set_scaling(&bigger, 2, 0.7, 2);
	matrix_set_translation(&bigger, 9, 0, 0);
	sphere_set_transform(obj, &bigger, &bigger);
	// obj->capped = false;

	//green
	// t_obj	*obj;
	// w.obj_list = &obj;
	// obj = obj_create(OT_SPHERE);
	// obj_add_back(&obj_list, obj);
	// matrix_set_translation(&translate_sp, -0.5, 1, 0.5);
	// obj->material.colour = colour_set(0.1, 1, 0.5);
	// obj->material.diffuse = 0.7;
	// obj->material.specular = 0.3;
	// sphere_set_transform(obj, &translate_sp, &scale_sp);
	
	//lime
	// t_obj	*obj2;
	t_matrix endlime;
	// obj2 = obj_create(OT_SPHERE);
	// obj_add_back(&obj_list, obj2);
	// matrix_set_translation(&translate_sp, 1.5, 0.5, -0.5);
	// matrix_set_scaling(&scale_sp, 0.5, 0.5, 0.5);
	// matrix_multiply_matrix(&translate_sp, &scale_sp, &endlime);
	// obj2->material.colour = colour_set(0.5, 1, 0.1);
	// obj2->material.diffuse = 0.7;
	// obj2->material.specular = 0.3;
	// sphere_set_transform(obj2, &endlime, &scale_sp);

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

	// t_matrix rotate_pl;
	//red right wall
	// t_obj *obj4;
	// obj4 = obj_create(OT_PLANE);
	// obj_add_back(&obj_list, obj4);
	// obj4->material.colour = colour_set(1, 0, 0);
	// obj4->material.specular = 0;
	// matrix_set_translation(&translate_sp, 5, 0, 3);
	// matrix_set_4(&rotate_pl);
	// matrix_set_rotation_z(&rotate_pl, -PI / 2);
	// matrix_multiply_matrix(&translate_sp, &rotate_pl, &endlime);
	// sphere_set_transform(obj4, &endlime, &scale_sp);

	//back red wall
	// t_obj *obj5;
	// obj5 = obj_create(OT_PLANE);
	// obj_add_back(&obj_list, obj5);
	// obj5->material.colour = colour_set(1, 0, 0);
	// obj5->material.specular = 0;
	// matrix_set_translation(&translate_sp, 0, 0, 5);
	// matrix_set_rotation_x(&rotate_pl, -PI / 2);
	// matrix_multiply_matrix(&translate_sp, &rotate_pl, &endlime);
	// sphere_set_transform(obj5, &endlime, &scale_sp);

	// t_obj *obj7;
	// obj7 = obj_create(OT_PLANE);
	// obj_add_back(&obj_list, obj7);
	// obj7->material.colour = colour_set(0, 1, 0);
	// obj7->material.specular = 0;
	// matrix_set_translation(&translate_sp, 0, 11, 0);
	// sphere_set_transform(obj7, &translate_sp, &scale_sp);

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
	// t_obj	*obj6;
	// obj6 = obj_create(OT_SPHERE);
	// obj_add_back(&obj_list, obj6);
	// matrix_set_translation(&translate_sp, -1.5, 0.33, -0.75);
	// matrix_set_scaling(&scale_sp, 0.33, 0.33, 0.33);
	// matrix_multiply_matrix(&translate_sp, &scale_sp, &endlime);
	// obj6->material.colour = colour_set(1, 0.8, 0.1);
	// obj6->material.diffuse = 0.7;
	// obj6->material.specular = 0.3;
	// sphere_set_transform(obj6, &endlime, &scale_sp);

	//yellow test point sphere
	t_obj	*obj6;
	obj6 = obj_create(OT_SPHERE);
	obj_add_back(&obj_list, obj6);
	matrix_set_translation(&translate_sp, 0, 1, 0);
	matrix_set_scaling(&scale_sp, 1, 1, 1);
	matrix_multiply_matrix(&translate_sp, &scale_sp, &endlime);
	obj6->material.colour = colour_set(1, 0.8, 0.1);
	obj6->material.diffuse = 0.7;
	obj6->material.specular = 0.3;
	sphere_set_transform(obj6, &endlime, &scale_sp);

	w.point_light.position = tuple_poi(0, 10, -5);
	w.point_light.intensity = colour_set(1, 1, 1);

	// t_ray		ray;
	// t_tuple	p;
	// t_tuple	d;
	// p = tuple_poi(0, -1, -2);
	// d = tuple_vec(0, 1, 1);
	// ray_create(&ray, p, d);
	// ray_print(&ray);
	// 
	// t_xsn *x = intersect_cy(ray, obj);
	// if (x)
	// {
	// 	printf("found 1\n");
	// 	printf("first at %.3f, second at %.3f\n", x->x, x->next->x);
	// }
	// else
	// 	printf("nope mf missed\n");
	// t_tuple poi = tuple_poi(0, 1, 0);
	// t_tuple normal = normal_at_cy(obj, &poi);
	// tuple_print(normal);

	t_camera	c = camera_construct(WIN_WIDTH, WIN_HEIGHT, PI / 2);
	pixel_size(&c);
	t_tuple	from = tuple_poi(5, 10.5, -10);
	t_tuple	to = tuple_poi(0, 2, 0);
	t_tuple	up = tuple_vec(0, 1, 0);
	c.transform = view_transform(from, to, up);
	matrix_det_4(&c.transform);
	c.trans_inverse = matrix_inverse(&c.transform);
	w.c = c;
	// (void)data;
	init_mlx(&data, c, &w);
}
