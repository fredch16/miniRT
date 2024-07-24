/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:21:56 by fcharbon          #+#    #+#             */
/*   Updated: 2024/07/24 20:43:49 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"
#include <stdbool.h>

void	ray_create(t_ray *ray, t_tuple origin, t_tuple direction)
{
	ray->origin = origin;
	ray->direction = direction;
}

void	ray_print(t_ray *ray)
{
	printf("ray origin:\n");
	tuple_print(ray->origin);
	printf("ray direction:\n");
	tuple_print(ray->direction);
}

t_tuple	ray_position(t_ray *ray, double scalar)
{
	t_tuple	position;
	t_tuple	distance;

	distance = ray->direction;
	tuple_mul(scalar, &distance);
	position = tuple_add(ray->origin, distance);
	return (position);
}

void	solve_quadratic(t_quadratic *quad)
{
	quad->t1 = -quad->b - sqrt(quad->d);
	quad->t1 = quad->t1 / (2 * quad->a);
	quad->t2 = -quad->b + sqrt(quad->d);
	quad->t2 = quad->t2 / (2 * quad->a);
}

t_xsn	*intersect_sp(t_ray ray, t_obj *o)
{
	t_tuple	sphere_to_ray;
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

t_xsn	*intersect_world(t_world *w, t_ray r)
{
	t_obj	*tmp_o;
	t_xsn	*xs;

	xs = NULL;
	tmp_o = *w->obj_list;
	while (tmp_o)
	{
		xadd_back(&xs, intersect_sp(r, tmp_o));
		tmp_o = tmp_o->next;
	}
	return (xs);
}

t_xsn	*intersect_hit(t_xsn **xslist)
{
	t_xsn	*tmp;
	t_xsn	*hit;
	double	lowestnn;

	lowestnn = DBL_MAX; 
	tmp = *xslist;
	hit	= NULL;
	while(tmp)
	{
		if (tmp->x >= 0 && tmp->x < lowestnn)
		{
			lowestnn = tmp->x;
			hit = tmp;
		}
		tmp = tmp -> next;
	}
	return (hit);
}

t_comps	prep_comps(t_xsn *x, t_ray ray)
{
	t_comps	comps;
	t_tuple	shadow_offset;

	comps.inside = 0;
	comps.t = x->x;
	comps.obj = x->xs_obj;
	comps.point = position_on_ray(&ray, comps.t);
	comps.eyev = tuple_neg(ray.direction);
	comps.normalv = sphere_normal_at(comps.obj, &comps.point);
	if (tuple_dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = 1;
		comps.normalv = tuple_neg(comps.normalv);
	}
	shadow_offset = comps.normalv;
	tuple_mul(EPSILON, &shadow_offset);
	comps.point = tuple_add(comps.point, shadow_offset);
	return (comps);
}

t_colour shade_hit(t_world *w, t_comps comps)
{

	t_lighting_atr	latr;
	bool			shadow;

	shadow = in_shadow(w, comps.point);
	w->point_light.latr = &latr;
	latr.point = comps.point;
	latr.normalv = comps.normalv;
	latr.eyev = comps.eyev;
	return (lighting(&comps.obj->material, &w->point_light, shadow));
}

t_colour colour_at(t_world *w, t_ray r)
{
	t_xsn		*x;	
	t_xsn		*xhit;	
	t_comps		comps;
	t_colour	col;

	x = intersect_world(w, r);
	if (!x)
		return (free_xs(&x), colour_set(0, 0, 0));
	xhit = intersect_hit(&x);
	if (xhit)
		comps = prep_comps(xhit, r);
	col = shade_hit(w, comps);
	return (free_xs(&x), col);
}

t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple		forward;
	t_tuple		upn;
	t_tuple		left;
	t_tuple		true_up;
	t_matrix	orientation;
	t_matrix	translation;
	t_matrix	result;

	forward = tuple_norm(tuple_sub(to, from));
	upn = tuple_norm(up);
	left = tuple_cro(forward, upn);
	true_up = tuple_cro(left, forward);
	matrix_set_4(&orientation);
	orientation.matrix[0][0] = left.x;
	orientation.matrix[0][1] = left.y;
	orientation.matrix[0][2] = left.z;
	orientation.matrix[1][0] = true_up.x;
	orientation.matrix[1][1] = true_up.y;
	orientation.matrix[1][2] = true_up.z;
	orientation.matrix[2][0] = -forward.x;
	orientation.matrix[2][1] = -forward.y;
	orientation.matrix[2][2] = -forward.z;
	matrix_set_4(&translation);
	matrix_set_translation(&translation, -from.x, -from.y, -from.z);
	matrix_multiply_matrix(&orientation, &translation, &result);
	return (result);
}
