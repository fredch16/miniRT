/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:35:21 by fcharbon          #+#    #+#             */
/*   Updated: 2024/11/09 20:02:31 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"
#include <stdbool.h>

bool	check_cap_cy(t_ray ray, double t)
{
	double	x;
	double	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	if (pow(x, 2) + pow(z, 2) <= 1)
		return (true);
	return (false);
}

t_xsn	*add_caps_cy(t_obj *cy, t_ray ray, t_xsn **xs)
{
	double	t;
	t_tuple	xs_point;
	double	t_offset;

	if (!cy->capped || equal(ray.direction.y, 0))
		return (*xs);
	t = (cy->min - ray.origin.y) / ray.direction.y;
	if (check_cap_cy(ray, t))
	{
		xs_point = position_on_ray(&ray, t);
		xs_point.y = cy->min + 0.000001;
		t_offset = (xs_point.y - ray.origin.y) / ray.direction.y;
		xadd_back(xs, x_new(cy, t_offset));
	}
	t = (cy->max - ray.origin.y) / ray.direction.y;
	if (check_cap_cy(ray, t))
	{
		xs_point = position_on_ray(&ray, t);
		xs_point.y = cy->max - 0.000001;
		t_offset = (xs_point.y - ray.origin.y) / ray.direction.y;
		xadd_back(xs, x_new(cy, t_offset));
	}
	return (*xs);
}
