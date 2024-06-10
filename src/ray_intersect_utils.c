/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:21:56 by fcharbon          #+#    #+#             */
/*   Updated: 2024/06/06 20:18:23 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

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
