/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:55:01 by atyurina          #+#    #+#             */
/*   Updated: 2024/09/13 12:55:47 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

t_tuple	reflect(t_tuple *in, t_tuple *normal)
{
	double	dot;
	t_tuple	res;

	dot = tuple_dot(*in, *normal);
	tuple_mul(2, normal);
	tuple_mul(dot, normal);
	res = tuple_sub(*in, *normal);
	return (res);
}

t_point_light	point_light_set(t_colour *intensity, t_tuple	*position)
{
	t_point_light	pl;

	pl.intensity = *intensity;
	pl.position = *position;
	return (pl);
}

t_material	material_set_default(void)
{
	t_material	m;

	m.colour.r = 1;
	m.colour.g = 1;
	m.colour.b = 1;
	m.ambient = 0.1;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200.0;
	return (m);
}
