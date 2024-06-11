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
	t_world w;
	(void)data;
	t_matrix	tr;
	t_matrix	scl;
	int	colour = 0xFF00FF;
	double x = 0;
	double y = 0;
	double	a;
	double	b;
	ray_p = tuple_poi(0, 0, -5);
	ray_dir = tuple_vec(x, y, 1);

	ray_create(&fake_ray, ray_p, ray_dir);
	ray_print(&fake_ray);

//	matrix_set_translation(&tr, 10, 0.5, 1);
//	matrix_set_4(&tr);
	double shearing[6];
	shearing[0] = 1;
	shearing[1] = 0;
	shearing[2] = 0;
	shearing[3] = 0;
	shearing[4] = 0;
	shearing[5] = 0;
	matrix_set_shearing(&tr, shearing);
	matrix_set_scaling(&scl, 0.5, 0.5, 1);
	obj_list = NULL;
	obj = obj_create(OT_SPHERE);
	obj_add_back(&obj_list, obj);
	w.obj_list = &obj;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "GTX");
	new_img(WIN_WIDTH, WIN_HEIGHT, &data);
	a = 0.004;
	b = 0.004;
	while(y < 1000)
	{
		x = 0;
		while (x < 1000)
		{
			ray_p = tuple_poi(0, 0, -10);
			ray_dir = tuple_vec(-2 + (x * a), 2 - (y * b), 1);
			ray_create(&fake_ray, ray_p, ray_dir);
			sphere_set_transform(obj, &tr, &scl);
			intersects = intersect_world(&w, fake_ray);
			tmp = intersects;
			while (tmp)
			{
				printf("Intersect is: %.3f\n", tmp->x);
				tmp = tmp->next;
			}
			hit = intersect_hit(&intersects);
			if (hit)
			{
				printf("Hit is at: %.3f\n", hit->x);
				put_pixel_img(&data, x, y, colour);
			}
			x++;
		}
		y++;
	}
	mlx_hook(data.win, 17, 0, close_and_destroy, &data);
	mlx_hook(data.win, 2, 1L << 0, keyboard_inputs, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
}

	//init_mlx(&data);