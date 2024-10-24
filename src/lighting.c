/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:05:00 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/24 18:16:00 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"
#include <stdbool.h>

void	l_calc(t_l_vars *v, t_material *material, t_point_light *light)
{
	double		reflect_dot_eye;
	t_tuple		lightv_neg;
	t_tuple		reflectv;
	double		factor;

	v->l.diffuse = colour_sca_mul(v->light_dot_normal,
			colour_sca_mul(material->diffuse, v->effective_colour));
	lightv_neg = tuple_neg(v->lightv);
	reflectv = reflect(&lightv_neg, &light->latr->normalv);
	reflect_dot_eye = tuple_dot(reflectv, light->latr->eyev);
	if (reflect_dot_eye <= 0)
		v->l.specular = colour_set(0, 0, 0);
	else
	{
		factor = pow(reflect_dot_eye, material->shininess);
		v->l.specular = colour_sca_mul(factor,
				colour_sca_mul(material->specular, light->intensity));
	}
}

t_colour	lighting(t_material *material, t_point_light *light, bool shadow)
{
	t_colour	res;
	t_l_vars	v;
	double		eye_dot_normal = tuple_dot(light->latr->eyev, light->latr->normalv);

	v.effective_colour = colour_mul(material->colour, light->intensity);
	v.lightv = tuple_norm(tuple_sub(light->position, light->latr->point));
	v.l.ambient = colour_sca_mul(material->ambient, v.effective_colour);
	v.light_dot_normal = tuple_dot(v.lightv, light->latr->normalv);
	if (v.light_dot_normal < 0 || eye_dot_normal < 0)
	{
		v.l.diffuse = colour_set(0, 0, 0);
		v.l.specular = colour_set(0, 0, 0);
	}
	else
		l_calc(&v, material, light);
	res = colour_set(0, 0, 0);
	if (shadow == false)
		res = colour_add(v.l.specular, v.l.diffuse);
	res = colour_add(res, v.l.ambient);
	return (res);
}

t_tuple	position_on_ray(t_ray *ray, double t)
{
	t_tuple	res;
	t_tuple	dir;

	dir = ray->direction;
	tuple_mul(t, &dir);
	res = tuple_add(ray->origin, dir);
	return (res);
}

u_int32_t	col_to_rgb(t_colour col)
{
	t_rgb		out_col;
	uint32_t	rgb_code;

	rgb_code = 0;
	if (col.r > 1)
		out_col.r = 255;
	else
		out_col.r = col.r * 255;
	if (col.g > 1)
		out_col.g = 255;
	else
		out_col.g = col.g * 255;
	if (col.b > 1)
		out_col.b = 255;
	else
		out_col.b = col.b * 255;
	rgb_code |= (out_col.r << 16);
	rgb_code |= (out_col.g << 8);
	rgb_code |= out_col.b;
	return (rgb_code);
}

bool	in_shadow(t_world *w, t_tuple point, t_obj *obj)
{
	t_ray		r;
	t_xsn		*x;
	t_xsn		*xhit;
	t_shadow	sh;

	obj += 0;
	sh.v = tuple_sub(w->point_light.position, point);
	sh.distance = tuple_abs(sh.v);
	sh.direction = tuple_norm(sh.v);
	ray_create(&r, point, sh.direction);
	x = intersect_world(w, r);
	if (!x)
		return (free_xs(&x), false);
	xhit = intersect_hit(&x);
	if ((xhit && xhit->x < sh.distance) && (xhit->xs_obj != obj))
		return (free_xs(&x), true);
	return (free_xs(&x), false);
}
