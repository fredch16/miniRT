/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_computation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:05:06 by atyurina          #+#    #+#             */
/*   Updated: 2024/09/13 13:13:31 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

t_comps	prep_comps(t_xsn *x, t_ray ray, t_world *w)
{
	t_comps	comps;
	t_tuple	shadow_offset;

	comps.inside = 0;
	comps.t = x->x;
	comps.obj = x->xs_obj;
	comps.point = position_on_ray(&ray, comps.t);
	comps.eyev = tuple_neg(ray.direction);
	comps.normalv = world_normal_at(comps.obj, &comps.point, comps.eyev, w);
	if ((tuple_dot(comps.normalv, comps.eyev) < -1) \
		&& comps.obj->type != OT_PLANE)
	{
		printf("       YO WE INSIDE");
		comps.inside = 1;
		comps.normalv = tuple_neg(comps.normalv);
	}
	shadow_offset = comps.normalv;
	tuple_mul(EPSILON, &shadow_offset);
	comps.point = tuple_add(comps.point, shadow_offset);
	return (comps);
}

t_colour	shade_hit(t_world *w, t_comps comps)
{
	t_lighting_atr	latr;
	bool			shadow;

	shadow = in_shadow(w, comps.point, comps.obj);
	w->point_light.latr = &latr;
	latr.point = comps.point;
	latr.normalv = comps.normalv;
	latr.eyev = comps.eyev;
	return (lighting(&comps.obj->material, &w->point_light, shadow));
}

t_colour	colour_at(t_world *w, t_ray r)
{
	t_xsn		*x;	
	t_xsn		*xhit;	
	t_comps		comps;
	t_colour	col;

	x = intersect_world(w, r);
	if (!x)
		return (free_xs(&x), colour_set(0, 0, 0));
	xhit = intersect_hit(&x);
	if (xhit)
		comps = prep_comps(xhit, r, w);
	col = shade_hit(w, comps);
	return (free_xs(&x), col);
}

t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple		forward;
	t_tuple		upn;
	t_tuple		left;
	t_tuple		true_up;
	t_transform	tr;

	forward = tuple_norm(tuple_sub(to, from));
	upn = tuple_norm(up);
	left = tuple_cro(forward, upn);
	true_up = tuple_cro(left, forward);
	matrix_set_4(&tr.orientation);
	tr.orientation.matrix[0][0] = left.x;
	tr.orientation.matrix[0][1] = left.y;
	tr.orientation.matrix[0][2] = left.z;
	tr.orientation.matrix[1][0] = true_up.x;
	tr.orientation.matrix[1][1] = true_up.y;
	tr.orientation.matrix[1][2] = true_up.z;
	tr.orientation.matrix[2][0] = -forward.x;
	tr.orientation.matrix[2][1] = -forward.y;
	tr.orientation.matrix[2][2] = -forward.z;
	matrix_set_4(&tr.translation);
	matrix_set_translation(&tr.translation, -from.x, -from.y, -from.z);
	matrix_multiply_matrix(&tr.orientation, &tr.translation, &tr.result);
	return (tr.result);
}
