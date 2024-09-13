/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:06:30 by atyurina          #+#    #+#             */
/*   Updated: 2024/09/13 13:21:23 by atyurina         ###   ########.fr       */
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
