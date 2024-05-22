/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:21:56 by fcharbon          #+#    #+#             */
/*   Updated: 2024/05/22 21:32:22 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

void	ray_create(t_ray *ray, t_3d_vector origin, t_3d_vector direction)
{
	ray->origin = origin;
	ray->direction = direction;
}

t_3d_vector	ray_position(t_ray *ray, double scalar)
{
	t_3d_vector	position;
	t_3d_vector	distance;

	distance = ray->direction;
	vector_mul(scalar, &distance);
	position = vector_add(ray->origin, distance);
	return (position);
}
