/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:05:00 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/25 21:28:17 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"
#include <stdbool.h>

t_colour	lighting(t_material *material, t_point_light *light, bool shadow)
{
	double		light_dot_normal;
	double		reflect_dot_eye;
	double		factor;
	t_colour	res;
	t_tuple		lightv;
	t_tuple		lightv_neg;
	t_tuple		reflectv;
	t_colour	effective_colour;
	t_lighting	l;

	effective_colour = colour_mul(material->colour, light->intensity);
	lightv = tuple_norm(tuple_sub(light->position, light->latr->point));
	//printer
	// tuple_print(light->latr->point);
	l.ambient = colour_sca_mul(material->ambient, effective_colour);
	//printer
	// tuple_print(lightv);
	// tuple_print(light->latr->normalv);
	light_dot_normal = tuple_dot(lightv, light->latr->normalv);
	// tuple_print(light->latr->normalv);
	if (light_dot_normal < 0)
	{
		l.diffuse = colour_set(0, 0, 0);
		l.specular = colour_set(0, 0, 0);
	}
	else
	{
		l.diffuse = colour_sca_mul(light_dot_normal, 
							 colour_sca_mul(material->diffuse, effective_colour));
		//print diffuse
		// printf("colour at is %.3f, %.3f, %.3f\n",  l.diffuse.r, l.diffuse.g, l.diffuse.b);
		lightv_neg = tuple_neg(lightv);
		reflectv = reflect(&lightv_neg, &light->latr->normalv);
		reflect_dot_eye = tuple_dot(reflectv, light->latr->eyev);
		if (reflect_dot_eye <= 0){
			// printf("TRIGGER DOT EYE REFLECT\n");
			l.specular = colour_set(0, 0, 0);
		}
		else
		{
			factor = pow(reflect_dot_eye, material->shininess);
			l.specular = colour_sca_mul(factor, 
							   colour_sca_mul(material->specular, light->intensity));
			// printf("DOT EYE GREATER THAN ZERO\n");
		}
	}
	res = colour_set(0, 0, 0);
	if (shadow == false)
	{
		res = colour_add(l.specular, l.diffuse);
	}
	res = colour_add(res, l.ambient);
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
	t_rgb out_col;
	uint32_t rgb_code;

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
	t_tuple	v;
	t_tuple	direction;
	double	distance;
	t_ray	r;
	t_xsn	*x;
	t_xsn	*xhit;

	obj += 0;
	v = tuple_sub(w->point_light.position, point);
	distance = tuple_abs(v);
	direction = tuple_norm(v);
	ray_create(&r, point, direction);
	
	x = intersect_world(w, r);
	if (!x)
		return (free_xs(&x), false);
	xhit = intersect_hit(&x);
	if ((xhit && xhit->x < distance) && (xhit->xs_obj != obj))
		return (free_xs(&x), true);
	return(free_xs(&x), false);
}
