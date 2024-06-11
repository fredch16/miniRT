/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:16:31 by fcharbon          #+#    #+#             */
/*   Updated: 2024/06/11 16:32:37 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

int	main(void)
{
//	t_data	data;
	t_obj	*obj;
	t_obj	*obj_list;
	// t_ray	fake_ray;
	// t_tuple	ray_p;
	// t_tuple	ray_dir;
	//t_world w;
//	t_matrix	tr;
	t_matrix	scl;
	t_matrix	rot;
	t_tuple		point;
	t_tuple		normal;

//	ray_p = tuple_poi(0, 0, -5);
//	ray_dir = tuple_vec(0, 0, 1);
//	ray_create(&fake_ray, ray_p, ray_dir);
//	ray_print(&fake_ray);

//	matrix_set_translation(&tr, 0, 1, 0);
	matrix_set_scaling(&scl, 1, 0.5, 1);
	matrix_set_rotation_z(&rot, PI / 5);
	point = tuple_poi(0, (sqrt(2)) / 2, -(sqrt(2)) / 2);
	obj_list = NULL;
	obj = obj_create(OT_SPHERE);
	obj_add_back(&obj_list, obj);
	//w.obj_list = &obj;
	sphere_set_transform(obj, &scl, &rot);
	normal = sphere_normal_at(obj, &point);
	tuple_print(normal);
	//init_mlx(&data, &w);
}

