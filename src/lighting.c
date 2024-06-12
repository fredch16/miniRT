/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:05:00 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/12 14:05:01 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

t_lighting	lighting(t_material *material, t_point_light *light, t_lighting_atr *latr)
{
	double		light_dot_normal;
	double		reflect_dot_eye;
	double		factor;
	t_tuple		lightv;
	t_tuple		lightv_neg;
	t_tuple		reflectv;
	t_colour	effective_colour;
	t_lighting	l;

	//combine the surface color with the light's color/intensity
	effective_colour = colour_mul(material->colour, light->intensity);
	//find the direction to the light source
	lightv = tuple_norm(tuple_sub(light->position, latr->point));
	//compute the ambient contribution
	l.ambient = colour_sca_mul(material->ambient, effective_colour);
	/*light_dot_normal represents the cosine of the angle between the
	light vector and the normal vector. A negative number means the
	light is on the other side of the surface*/
	light_dot_normal = tuple_dot(lightv, latr->normalv);
	if (light_dot_normal < 0)
	{
		l.diffuse = colour_set(0, 0, 0);
		l.specular = colour_set(0, 0, 0);
	}
	else
	{
		//compute the diffuse contribution
		l.diffuse = colour_sca_mul(light_dot_normal, \
		colour_sca_mul(material->diffuse, effective_colour));
		/*reflect_dot_eye represents the cosine of the angle between the
		reflection vector and the eye vector. A negative number means the
		light reflects away from the eye.*/
		lightv_neg = tuple_neg(lightv);
		reflectv = reflect(&lightv_neg, &latr->normalv);
		reflect_dot_eye = tuple_dot(reflectv, latr->eyev);
		if (reflect_dot_eye <= 0)
			l.specular = colour_set(0, 0, 0);
		else
		{
			//compute the specular contribution
			factor = pow(reflect_dot_eye, material->shininess);
			l.specular = colour_sca_mul(factor, \
			colour_sca_mul(material->specular, light->intensity));
		}
	}
	return (l);
}