/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:06:30 by atyurina          #+#    #+#             */
/*   Updated: 2024/11/13 15:03:45 by fcharbon         ###   ########.fr       */
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
	quad->t1 = -quad->b - sqrt(quad->d);
	quad->t1 = quad->t1 / (2 * quad->a);
	quad->t2 = -quad->b + sqrt(quad->d);
	quad->t2 = quad->t2 / (2 * quad->a);
}

t_xsn	*intersect_hit(t_xsn **xslist)
{
	t_xsn	*tmp;
	t_xsn	*hit;
	double	lowestnn;

	lowestnn = DBL_MAX;
	tmp = *xslist;
	hit = NULL;
	while (tmp)
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
