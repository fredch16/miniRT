/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:16:31 by fcharbon          #+#    #+#             */
/*   Updated: 2024/06/03 19:00:29 by fcharbon         ###   ########.fr       */
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
	t_xs	intersects;
	t_tuple	scaling;

	ray_p.x = 0;
	ray_p.y = 0;
	ray_p.z = -5;

	ray_dir.x = 0;
	ray_dir.y = 0;
	ray_dir.z = 1;

	obj_list = NULL;

	scaling.x = -2;
	scaling.y = -2;
	scaling.z = -2;
	scaling.w = 1;
	ray_create(&fake_ray, ray_p, ray_dir);
	fake_ray = ray_scale(&fake_ray, scaling);
	obj = obj_create(OT_SPHERE);
	obj_add_back(&obj_list, obj);
	intersects = get_intersects(&fake_ray, &data);
	printf("Num of xs = %d\n", intersects.count);
	printf("Intersect 1: %.3f\n", intersects.t_vals[0]);
	printf("Intersect 2: %.3f\n", intersects.t_vals[1]);

	init_mlx(&data);	
}
