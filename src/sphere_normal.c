/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:00:38 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/11 13:00:40 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

t_tuple	sphere_normal_at(t_obj *s, t_tuple *w_point)
{
	t_tuple		obj_point;
	t_tuple		obj_normal;
	t_tuple		w_normal;
	t_matrix	t_m;
	t_tuple		point;

	point = tuple_poi(0, 0, 0);
	matrix_det_4(&s->transform);
	obj_point = matrix_multiply_tuple(&s->transform, w_point);
	obj_normal = tuple_sub(obj_point, point);
	obj_normal.w = 0;
	t_m = matrix_transpose(&s->transform);
	w_normal = matrix_multiply_tuple(&t_m, &obj_normal);
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

t_material	material_default(void)
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