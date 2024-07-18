/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:33:10 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/18 18:35:36 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

t_camera	camera_construct(double h, double v, double view)
{
	t_camera	c;

	c.hsize = h;
	c.vsize = v;
	c.field_of_view = view;
	matrix_set_4(&c.transform);
	matrix_det_4(&c.transform);
	return (c);
}

void	pixel_size(t_camera *c)
{
	double	half_view;
	double	aspect;

	half_view = tan(c->field_of_view / 2);
	aspect = c->hsize / c->vsize;
	if (aspect >= 1)
	{
		c->half_width = half_view;
		c->half_height = half_view / aspect;
	}
	else
	{
		c->half_width = half_view * aspect;
		c->half_height = half_view;
	}
	c->pixel_size = (c->half_width * 2) / c->hsize;
}

t_ray	ray_for_pixel(t_camera c, double px, double py)
{
	double		xoffset;
	double		yoffset;
	double		world_x;
	double		world_y;
	t_tuple		pixel;
	t_tuple		point;
	t_matrix	inversed;
	t_ray	ray;

	xoffset = (px + 0.5) * c.pixel_size;
	yoffset = (py + 0.5) * c.pixel_size;

	world_x = c.half_width - xoffset;
	world_y = c.half_height - yoffset;

	point = tuple_poi(world_x, world_y, -1);
	inversed = matrix_inverse(&c.transform);
	pixel = matrix_multiply_tuple(&inversed, &point);

	point = tuple_poi(0, 0, 0);
	ray.origin = matrix_multiply_tuple(&inversed, &point);
	ray.direction = tuple_norm(tuple_sub(pixel, ray.origin));
	return (ray);
}