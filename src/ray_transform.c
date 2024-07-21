/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:25:35 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/18 23:58:11 by fcharbon         ###   ########.fr       */
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

t_ray	ray_transform(t_ray *ray, t_matrix *transform)
{
	t_ray		ret;

	ret.origin = matrix_multiply_tuple(transform, &ray->origin);
	ret.direction = matrix_multiply_tuple(transform, &ray->direction);
	return (ret);
}

// set changes
void	sphere_set_transform(t_obj *sphere, t_matrix *translate, t_matrix *scale)
{
	// t_matrix	changes;
	t_matrix	inversed;

	// matrix_multiply_matrix(scale, translate, &changes);
	scale += 0;
	
	matrix_det_4(translate);
	inversed = matrix_inverse(translate);
	sphere->transform = inversed;
}
