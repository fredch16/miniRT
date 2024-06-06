/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:16:31 by fcharbon          #+#    #+#             */
/*   Updated: 2024/06/06 21:23:49 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

int	main(void)
{
	t_data	data;
	t_obj	*obj;
	t_obj	*obj_list;
	t_ray	fake_ray;
	t_tuple	ray_p;
	t_tuple	ray_dir;
	t_xsn	*intersects;
	t_xsn	*tmp;
	t_xsn	*hit;
	// t_tuple	scaling;
	t_world w;
	(void)data;
	t_matrix	tr;

	ray_p = tuple_poi(-3, 4, 5);
	ray_dir = tuple_vec(0, 0, 1);

	matrix_set_translation(&tr, 5, -3, 2);
	ray_p = matrix_multiply_tuple(&tr, &ray_p);
	tuple_print(ray_p);

	obj_list = NULL;

	// scaling.x = -2;
	// scaling.y = -2;
	// scaling.z = -2;
	// scaling.w = 1;
	ray_create(&fake_ray, ray_p, ray_dir);
	// fake_ray = ray_scale(&fake_ray, scaling);
	obj = obj_create(OT_SPHERE);
	obj_add_back(&obj_list, obj);
	w.obj_list = &obj;
	intersects = intersect_world(&w, fake_ray);
	tmp = intersects;
	while (tmp)
	{
		printf("Intersect is: %.3f\n", tmp->x);
		tmp = tmp->next;
	}
	hit = intersect_hit(&intersects);
	if (hit)
		printf("Hit is at: %.3f\n", hit->x);
	// init_mlx(&data);	
}
