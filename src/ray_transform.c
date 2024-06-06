/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:25:35 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/04 16:25:37 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

t_ray	ray_translate(t_ray *ray, t_tuple translation)
{
	ray->origin = tuple_add(ray->origin, translation);
	ray->direction = tuple_add(ray->direction, translation);
	return (*ray);
}

t_ray	ray_scale(t_ray *ray, t_tuple scaling)
{
	ray->origin.x = ray->origin.x * scaling.x;
	ray->origin.y = ray->origin.x * scaling.y;
	ray->origin.z = ray->origin.x * scaling.z;
	ray->direction.x = ray->direction.x * scaling.x;
	ray->direction.y = ray->direction.y * scaling.y;
	ray->direction.z = ray->direction.z * scaling.z;
	return (*ray);
}

void	sphere_transform(t_obj *sphere, t_matrix *changes)
{
	sphere->transform = *changes;
}

