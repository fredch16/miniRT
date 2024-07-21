/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:37:57 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/18 19:15:19 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING_H
# define LIGHTING_H

#include "minirt_types.h"
#include <sys/types.h>

//sphere_normal:
t_tuple		sphere_normal_at(t_obj *s, t_tuple *w_point);
t_tuple		reflect(t_tuple *in, t_tuple *normal);
t_material	material_set_default(void);

//lighting:
t_colour	lighting(t_material *material, t_point_light *light, t_lighting_atr *latr);
t_tuple	position_on_ray(t_ray *ray, double t);
u_int32_t	col_to_rgb(t_colour col);

#endif
