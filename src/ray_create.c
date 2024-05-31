/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:29:28 by atyurina          #+#    #+#             */
/*   Updated: 2024/05/31 14:29:29 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

t_ray	ray_create(t_3d_vector point, t_3d_vector vector)
{
	t_ray	ray;

	ray.origin = point;
	ray.direction = vector;
	return (ray);
}

// ray position = ray.origin + ray.direction * t
// it is he point at the given distance t along the ray
t_3d_vector	ray_position(t_ray *ray, double t)
{
	t_3d_vector	position;
	vector_mul(t, &ray->direction);
	position = vector_add(ray->origin, ray->direction);
	return (position);
}

//create a sphere with a center at 0.0.0
t_sphere	sphere_create(double	radius, int id)
{
	t_sphere	s;

	s.center.x = 0;
	s.center.y = 0;
	s.center.z = 0;
	s.center.w = 1;
	s.radius = radius;
	s.id = id;
	return (s);
}

void	sphere_intersect(t_ray *ray, t_3d_vector *vector)
{

}