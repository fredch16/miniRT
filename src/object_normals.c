/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_normals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:00:38 by atyurina          #+#    #+#             */
/*   Updated: 2024/09/12 14:27:15 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

t_tuple	normal_at_sp(t_obj *s, t_tuple *o_point)
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

t_tuple	normal_at_pl(t_obj *pl, t_tuple *o_point, t_tuple eyev, t_tuple lightv)
{
	t_matrix	t_m;
	t_tuple		obj_normal;
	t_tuple		w_normal;
	double		doteye;
	double		dotlight;	

	(void)o_point;
	obj_normal = tuple_vec(0, 1, 0);
	t_m = matrix_transpose(&pl->transform);
	w_normal = matrix_multiply_tuple(&t_m, &obj_normal);
	w_normal.w = 0;
	doteye = tuple_dot(w_normal, eyev);
	dotlight = tuple_dot(w_normal, lightv);
	if ((doteye * dotlight) > 0)
	{
		if (doteye < 0 && dotlight < 0)
			w_normal = tuple_neg(w_normal);
	}
	return (tuple_norm(w_normal));
}

t_tuple	normal_at_cy(t_obj *cy, t_tuple *o_point)
{
	t_normal_cy	ncy;

	ncy.obj_normal = tuple_vec(0, 1, 0);
	ncy.t_m = matrix_transpose(&cy->transform);
	ncy.w_normal = matrix_multiply_tuple(&ncy.t_m, &obj_normal);
	ncy.w_normal.w = 0;
	ncy.dist = pow(o_point->x, 2) + pow(o_point->z, 2);
	if ((ncy.dist < 1) && (o_point->y >= cy->max - EPSILON))
	{
		ncy.obj_normal = tuple_vec(0, 1, 0);
		ncy.t_m = matrix_transpose(&cy->transform);
		ncy.w_normal = matrix_multiply_tuple(&ncy.t_m, &obj_normal);
		ncy.w_normal.w = 0;
		return (tuple_norm(ncy.w_normal));
	}
	if ((ncy.dist < 1) && (o_point->y <= cy->min + EPSILON))
	{
		ncy.obj_normal = tuple_vec(0, -1, 0);
		ncy.t_m = matrix_transpose(&cy->transform);
		ncy.w_normal = matrix_multiply_tuple(&ncy.t_m, &obj_normal);
		ncy.w_normal.w = 0;
		return (tuple_norm(ncy.w_normal));
	}
	ncy.w_normal = tuple_vec(o_point->x, 0, o_point->z);
	return (tuple_norm(ncy.w_normal));
}

t_tuple	obj_normal(t_obj *o, t_tuple *w_point, t_tuple eyev, t_world *w)
{
	t_tuple	o_point;
	t_tuple	lightv;

	matrix_det_4(&o->transform);
	lightv = tuple_sub(w->point_light.position, *w_point);
	o_point = matrix_multiply_tuple(&o->transform, w_point);
	if (o->type == OT_PLANE)
		return (normal_at_pl(o, &o_point, eyev, lightv));
	else if (o->type == OT_CYLINDER)
		return (normal_at_cy(o, &o_point));
	else
		return (normal_at_sp(o, &o_point));
}

t_tuple	world_normal_at(t_obj *o, t_tuple *w_point, t_tuple eyev, t_world *w)
{
	t_tuple		w_normal;

	w_normal = obj_normal(o, w_point, eyev, w);
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
