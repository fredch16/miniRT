/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:29:28 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/03 15:13:36 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

// t_ray	ray_create(t_tuple point, t_tuple tuple)
// {
// 	t_ray	ray;
//
// 	ray.origin = point;
// 	ray.direction = tuple;
// 	return (ray);
// }
//
// // ray position = ray.origin + ray.direction * t
// // it is he point at the given distance t along the ray
// t_tuple	ray_position(t_ray *ray, double t)
// {
// 	t_tuple	position;
// 	tuple_mul(t, &ray->direction);
// 	position = tuple_add(ray->origin, ray->direction);
// 	return (position);
// }
//
//create a sphere with a center at 0.0.0
// t_sphere	sphere_create(double	radius, int id)
// {
// 	t_sphere	s;
//
// 	s.center.x = 0;
// 	s.center.y = 0;
// 	s.center.z = 0;
// 	s.center.w = 1;
// 	s.radius = radius;
// 	s.id = id;
// 	return (s);
// }
//
// void	sphere_intersect(t_ray *ray, t_tuple *tuple)
// {
//
// }
