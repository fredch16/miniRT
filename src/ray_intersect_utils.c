/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:21:56 by fcharbon          #+#    #+#             */
/*   Updated: 2024/06/03 18:59:52 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

void	ray_create(t_ray *ray, t_tuple origin, t_tuple direction)
{
	ray->origin = origin;
	ray->direction = direction;
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
	quad->t1 = -quad->b - sqrt(quad->discriminant);
	quad->t1 = quad->t1 / (2 * quad->a);
	quad->t2 = -quad->b + sqrt(quad->discriminant);
	quad->t2 = quad->t2 / (2 * quad->a);
}

t_xs	get_intersects(t_ray *ray, /* t_obj *obj_sph, */t_data *data)
{
	t_tuple	sphere_to_ray;
	t_quadratic	quad;
	t_xs		xs;

	sphere_to_ray = tuple_sub(ray->origin, data->origin); 
	quad.a = tuple_dot(ray->direction, ray->direction);
	quad.b = 2 * tuple_dot(ray->direction, sphere_to_ray);
	quad.c = tuple_dot(sphere_to_ray, sphere_to_ray) - 1;
	quad.discriminant = (quad.b * quad.b) - (4 * quad.a * quad.c);

	if (quad.discriminant < 0)
		xs.count = 0;
	else 
	{
		xs.count = 2;
		solve_quadratic(&quad);
		xs.t_vals[0] = quad.t1;
		xs.t_vals[1] = quad.t2;
	}
	return (xs);
}

t_obj	*obj_create(enum e_obj_type ot)
{
	t_obj	*new;

	new = calloc(1, sizeof(t_obj));
	if (!new)
		return (NULL);
	new->type = ot;
	matrix_set_4(&new->transform);
	return (new);
}

void	obj_add_back(t_obj	**objlist, t_obj *n)
{
	t_obj	*tmp;

	if (!objlist || !n)
		return ;
	if (!*objlist)
		*objlist = n;
	else
	{
		tmp = *objlist;
		while (tmp -> next)
			tmp = tmp -> next;
		tmp -> next = n;
	}
}