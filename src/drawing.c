/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:31:48 by fcharbon          #+#    #+#             */
/*   Updated: 2024/06/11 16:32:06 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

void	draw_circle(t_data *data, t_world *w)
{
	t_ray	fake_ray;
	t_tuple	ray_p;
	t_tuple	ray_dir;
	t_xsn	*intersects;
	t_xsn	*hit;
	t_obj	*obj;
	t_lighting_atr	l_atr;
	obj = *w->obj_list;
	int	x, y = 0;
	printf("HELLO\n");

	ray_p = tuple_poi(0, 0, -1.5);
	ray_dir = tuple_norm(tuple_vec(-2, 2, 1));

	double xdif, ydif;

	xdif = 0.005;
	ydif = 0.005;
	
	while (++y < 800)
	{
		x = 0;
		xdif = 0.005;
		while (++x < 800)
		{
			ray_dir = tuple_norm(tuple_vec(-2 + xdif, 2 - ydif, 1));
			ray_create(&fake_ray, ray_p, ray_dir);
			intersects = intersect_world(w, fake_ray);
			hit = intersect_hit(&intersects);
			if (hit)
			{
				t_tuple	pos;
				pos = position_of_hit(&fake_ray, hit->x);
				t_tuple	norm;
				norm = sphere_normal_at(obj, &pos);
				t_tuple	eye;
				eye = tuple_neg(fake_ray.direction);
				t_colour	colour;
				l_atr.point = pos;
				l_atr.eyev = eye;
				l_atr.normalv = norm;
				colour = lighting(&obj->material, &w->point, &l_atr);
				// tuple_print(ray_dir);
				// printf("HIT, printing at %d, %d\n", x, y);
				u_int32_t col_code;
				col_code = col_to_rgb(colour);
				put_pixel_img(data, x, y, col_code);
			}
			xdif += 0.005;
		}
		ydif += 0.005;
	}
}

void	draw_projectile(t_data *data, int startx, int starty, t_tuple velocity)
{
	t_tuple gravity;

	t_tuple currentpoint;
	currentpoint.x = startx;
	currentpoint.y = starty;

	gravity.x = 0;
	gravity.y = 0.05;
	gravity.z = 0;

	t_tuple wind;
	wind.x = -0.04;
	wind.y = 0;
	wind.z = 0;

	while (currentpoint.x <= WIN_WIDTH && currentpoint.y <= WIN_HEIGHT)
	{
		put_pixel_img(data, currentpoint.x, currentpoint.y, 0xFF0000);
		velocity = tuple_add(velocity, gravity);
		velocity = tuple_add(velocity, wind);
		currentpoint = tuple_add(currentpoint, velocity);
	}
}

void	draw_clock(t_data *data)
{
	t_matrix matA;
	t_matrix matB;
	//t_matrix matC;
	// t_matrix matD;
	// t_matrix matE;
	t_tuple	tuple;
	t_tuple	point;
	int	colour = 0xFF00FF;
	int	radius;

	radius = 200;
	tuple.x = 0;
	tuple.y = 0;
	tuple.z = 0;
	tuple.w = 1;

	put_pixel_img(data,  tuple.x, tuple.y, colour);
	// tuple_print(tuple);
	matrix_set_translation(&matA, 0, -radius, 0);
	// matrix_print(&matA);
	point = matrix_multiply_tuple(&matA, &tuple);
	// tuple_print(point);
	put_pixel_img(data, point.x, point.y, colour);
	matrix_set_rotation_z(&matB, PI / 6);
	// matrix_print(&matB);
	int y = 0;
	while (y < 11)
	{
		point = matrix_multiply_tuple(&matB, &point);
		tuple_print(point);
		put_pixel_img(data,  point.x, point.y, colour);
		y++;
	}
}
