/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:00:38 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/25 15:26:11 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

t_tuple	sphere_normal_at(t_obj *s, t_tuple *o_point)
{
	t_tuple		obj_normal;
	t_tuple		w_normal;
	t_matrix	t_m;
	t_tuple		point;

	point = tuple_poi(0, 0, 0);
	obj_normal = tuple_sub(*o_point, point);
	obj_normal.w = 0;
	t_m = matrix_transpose(&s->transform);
	w_normal = matrix_multiply_tuple(&t_m, &obj_normal);
	w_normal.w = 0;
	return (tuple_norm(w_normal));
}

t_tuple	plane_normal_at(t_obj *pl, t_tuple *w_point)
{
	t_matrix	t_m;
	t_tuple		obj_normal;
	t_tuple		w_normal;

	(void)w_point;
	obj_normal = tuple_vec(0, 1, 0);

	t_m = matrix_transpose(&pl->transform);
	w_normal = matrix_multiply_tuple(&t_m, &obj_normal);
	w_normal.w = 0;
	return (tuple_norm(w_normal));
}

t_tuple	obj_normal(t_obj *o, t_tuple *w_point)
{
	t_tuple o_point;

	matrix_det_4(&o->transform);
	o_point = matrix_multiply_tuple(&o->transform, w_point);
	if (o->type == OT_PLANE)
		return(plane_normal_at(o, &o_point));
	else
		return(sphere_normal_at(o, &o_point));
}

t_tuple	world_normal_at(t_obj *o, t_tuple *w_point)
{
	t_tuple		o_normal;
	t_tuple		w_normal;
	t_matrix	t_m;

	o_normal = tuple_norm(obj_normal(o, w_point));

	t_m = matrix_transpose(&o->transform);
	w_normal = matrix_multiply_tuple(&t_m, &o_normal);
	w_normal.w = 0;
	return (tuple_norm(w_normal));
}

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

// create point_light by setting intensity and position:
t_point_light	point_light_set(t_colour *intensity, t_tuple	*position)
{
	t_point_light	pl;

	pl.intensity = *intensity;
	pl.position = *position;
	return (pl);
}

// set material structure to default:
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
