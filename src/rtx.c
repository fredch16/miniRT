/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:16:31 by fcharbon          #+#    #+#             */
/*   Updated: 2024/07/18 19:54:11 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

int	main(void)
{
	t_data	data;
	t_obj	*obj;
	t_obj	*obj2;
	t_obj	*obj3;
	t_obj	*obj_list;
	// t_xsn	*xs_list;
	t_tuple		p;
	t_tuple		d;
	t_ray		ray;
	// t_comps		comps;
	t_world		w;
	t_matrix	translate_sp;
	t_matrix	scale_sp;

	obj_list = NULL;

	matrix_set_translation(&translate_sp, 0, 0, 0);
	// matrix_set_4(&translate_sp);
	matrix_set_scaling(&scale_sp, 0.5, 0.5, 0.5);
	// matrix_set_4(&scale_sp);

	p = tuple_poi(0, 0, -5);
	d = tuple_vec(0, 0, 1);
	// p = tuple_poi(10, 10, -5);
	// d = tuple_vec(1, 1, 0);
	ray_create(&ray, p, d);
	
	w.obj_list = &obj;
	obj = obj_create(OT_SPHERE);
	obj_add_back(&obj_list, obj);
	obj->material.colour = colour_set(0.1764, 0.005, 0.6);
	// obj->material.diffuse = 0.7;
	// obj->material.specular = 0.2;
	obj->material.ambient = 0.6;
	obj->material.shininess = 50;
	obj->material.specular = 0.6;
	matrix_set_translation(&translate_sp, 0, 0, 11);
	matrix_set_scaling(&scale_sp, 3, 3, 3);
	sphere_set_transform(obj, &translate_sp, &scale_sp);

	obj2 = obj_create(OT_SPHERE);
	obj_add_back(&obj_list, obj2);
	obj2->material.colour = colour_set(0.4078, 0.3921, 0.4588);
	obj2->material.ambient = 0.5;
	obj2->material.shininess = 50;
	obj2->material.specular = 0;
	matrix_set_translation(&translate_sp, 4, 1, 9);
	matrix_set_scaling(&scale_sp, 1, 1, 1);
	sphere_set_transform(obj2, &translate_sp, &scale_sp);

	obj3 = obj_create(OT_SPHERE);
	obj_add_back(&obj_list, obj3);
	obj3->material.colour = colour_set(1, 0.32, 0.005);
	obj3->material.ambient = 1;
	obj3->material.shininess = 200;
	obj3->material.specular = 0.2;
	matrix_set_translation(&translate_sp, -2, 3, 6);
	matrix_set_scaling(&scale_sp, 0.75, 0.35, 0.35);
	sphere_set_transform(obj3, &translate_sp, &scale_sp);

	w.point_light.position = tuple_poi(-10, 10, -10);
	w.point_light.intensity = colour_set(1, 1, 1);
	// xs_list = intersect_world(&w, ray);
	// while (xs_list)
	// {
	// 	comps = prep_comps(xs_list, ray);
	// 	// printf("\n\nInside = %d\n", comps.inside);
	// 	// printf("xs = %.2f\nPoint is \n", xs_list->x);
	// 	// tuple_print(comps.point);
	// 	// printf("Eye vector is \n");
	// 	// tuple_print(comps.eyev);
	// 	// printf("Normal vector is \n");
	// 	// tuple_print(comps.normalv);
	// 	t_colour col = shade_hit(&w, comps);
	// 	printf("R: %.5f, G: %.5f, B: %.5f\n", col.r, col.g, col.b);
	// 	xs_list = xs_list->next;
	// 	printf("\n\n");
	// }
	t_colour col = colour_at(&w, ray);
	// ray_print(&ray);
	// printf("world light position:\n");
	// tuple_print(w.point_light.position);
	// printf("world light intensity:\n");
	// printf("R: %.5f, G: %.5f, B: %.5f\n", w.point_light.intensity.r, w.point_light.intensity.g, w.point_light.intensity.b);
	//printf("xs[0] = %.2f", a->x);
	//intersects_print(a);

	//test test
	t_camera	c = camera_construct(800, 800, PI / 4);
	pixel_size(&c);

	// t_matrix	rotate;
	// t_matrix	translate;
	// matrix_set_rotation_y(&rotate, PI / 4);
	// matrix_set_translation(&translate, 0, -2, 5);
	// matrix_multiply_matrix(&rotate, &translate, &c.transform);
	// t_ray	ray_pix = ray_for_pixel(c, 100, 50);
	// ray_print(&ray_pix);
	/// (root2)/2 = 0.70711...
	//printf("c.pixel_size = %.3f\n\n", c.pixel_size);


	t_tuple	from = tuple_poi(0, 0, -5);
	t_tuple	to = tuple_poi(0, 0, 0);
	t_tuple	up = tuple_vec(0, 1, 0);
	c.transform = view_transform(from, to, up);
	// matrix_print(&view);
	printf("R: %.5f, G: %.5f, B: %.5f\n", col.r, col.g, col.b);

	init_mlx(&data, c, &w);
}
