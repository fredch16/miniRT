/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:43:34 by fcharbon          #+#    #+#             */
/*   Updated: 2024/05/22 23:55:27 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

t_sphere	shape_create_sphere(t_data *data)
{
	t_sphere	new_sphere;

	data->shapes[0] = new_sphere;
	new_sphere.centre = data->origin;
	new_sphere.radius = 1;
	return (new_sphere);
}

// double	*sphere_intersects(t_sphere sphere, t_ray ray)
// {
// 	
// }
