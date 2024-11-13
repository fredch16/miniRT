/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:37:57 by atyurina          #+#    #+#             */
/*   Updated: 2024/11/12 17:45:44 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING_H
# define LIGHTING_H

#include "minirt_types.h"
#include <sys/types.h>

//sphere_normal:
t_tuple		normal_at_sp(t_obj *s, t_tuple *o_point);
t_tuple		normal_at_pl(t_obj *pl, t_tuple *o_point, t_tuple eyev, t_tuple lightv);
t_tuple		normal_at_cy(t_obj *cy, t_tuple *o_point);
t_tuple		reflect(t_tuple *in, t_tuple *normal);
t_material	material_set_default(void);
t_tuple		world_normal_at(t_obj *o, t_tuple *w_point, t_tuple eyev, t_world *w);
t_tuple		obj_normal(t_obj *o, t_tuple *w_point, t_tuple eyev, t_world *w);

//lighting:
t_colour	lighting(t_material *material, t_point_light *light, bool shadow);
t_tuple		position_on_ray(t_ray *ray, double t);
u_int32_t	col_to_rgb(t_colour col);
bool		in_shadow(t_world *w, t_tuple point, t_obj *obj);

#endif
