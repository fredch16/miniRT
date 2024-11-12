/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:21:56 by fcharbon          #+#    #+#             */
/*   Updated: 2024/11/12 13:27:06 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

t_xsn	*intersect_sp(t_ray ray, t_obj *o)
{
	t_tuple		sphere_to_ray;
	t_quadratic	quad;
	t_xsn		*xs;

	ray = ray_transform(&ray, &o->transform);
	sphere_to_ray = tuple_sub(ray.origin, tuple_poi(0, 0, 0));
	quad.a = tuple_dot(ray.direction, ray.direction);
	quad.b = 2 * tuple_dot(ray.direction, sphere_to_ray);
	quad.c = tuple_dot(sphere_to_ray, sphere_to_ray) - 1;
	quad.d = (quad.b * quad.b) - (4 * quad.a * quad.c);
	xs = NULL;
	if (quad.d >= 0)
	{
		xs = x_new(o, ((-quad.b + sqrt(quad.d)) / (2 * quad.a)));
		if (quad.d > 0)
			xadd_back(&xs, x_new(o, ((-quad.b - sqrt(quad.d)) / (2 * quad.a))));
	}
	return (xs);
}

t_xsn	*intersect_pl(t_ray ray, t_obj *o)
{
	double	t;

	ray = ray_transform(&ray, &o->transform);
	if (fabs(ray.direction.y) < EPSILON)
		return (NULL);
	t = -ray.origin.y / ray.direction.y;
	if (t >= EPSILON)
		return (x_new(o, t));
	return (NULL);
}

t_xsn	*intersect_cy_body(t_ray ray, t_obj *cy, t_quadratic quad, t_xsn *xs)
{
	double	t;
	double	y;

	t = (-quad.b + sqrt(quad.d)) / (2 * quad.a);
	y = ray.origin.y + t * ray.direction.y;
	if ((cy->min < y) && (y < cy->max))
		xs = x_new(cy, t);
	if (quad.d > 0)
	{
		t = (-quad.b - sqrt(quad.d)) / (2 * quad.a);
		y = ray.origin.y + t * ray.direction.y;
		if ((cy->min < y) && (y < cy->max))
			xadd_back(&xs, x_new(cy, t));
	}
	return (xs);
}

t_xsn	*intersect_cy(t_ray ray, t_obj *cy)
{
	t_quadratic	quad;
	t_xsn		*xs;

	xs = NULL;
	ray = ray_transform(&ray, &cy->transform);
	quad.a = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
	if (quad.a < EPSILON)
		return (add_caps_cy(cy, ray, &xs));
	quad.b = 2 * ray.origin.x * ray.direction.x + 2 \
		* ray.origin.z * ray.direction.z;
	quad.c = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - 1;
	quad.d = pow(quad.b, 2) - (4 * quad.a * quad.c);
	if (quad.d >= 0)
		xs = intersect_cy_body(ray, cy, quad, xs);
	return (add_caps_cy(cy, ray, &xs));
}

t_xsn	*intersect_world(t_world *w, t_ray r)
{
	t_obj	*tmp_o;
	t_xsn	*xs;

	xs = NULL;
	tmp_o = *w->obj_list;
	while (tmp_o)
	{
		if (tmp_o->type == OT_PLANE)
			xadd_back(&xs, intersect_pl(r, tmp_o));
		else if (tmp_o->type == OT_CYLINDER)
			xadd_back(&xs, intersect_cy(r, tmp_o));
		else
			xadd_back(&xs, intersect_sp(r, tmp_o));
		tmp_o = tmp_o->next;
	}
	return (xs);
}
