/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:35:21 by fcharbon          #+#    #+#             */
/*   Updated: 2024/08/01 21:30:49 by fcharbon         ###   ########.fr       */
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

	if (!cy->capped || equal(ray.direction.y, 0))
		return (*xs);
	t = (cy->min - ray.origin.y) / ray.direction.y;
	if (check_cap_cy(ray, t))
		xadd_back(xs, x_new(cy, t));
	t = (cy->max - ray.origin.y) / ray.direction.y;
	if (check_cap_cy(ray, t))
		xadd_back(xs, x_new(cy, t));
	return (*xs);
}
