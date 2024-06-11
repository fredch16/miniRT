/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:50:14 by fcharbon          #+#    #+#             */
/*   Updated: 2024/06/06 20:12:41 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_INTERSECT_H
# define RAY_INTERSECT_H

# include "minirt_types.h"

void		ray_create(t_ray *ray, t_tuple origin, t_tuple direction);
t_tuple		ray_position(t_ray *ray, double scalar);
void		ray_print(t_ray *ray);
void		obj_add_back(t_obj	**objlist, t_obj *n);
t_obj		*obj_create(enum e_obj_type ot);
t_xsn		*get_intersects(t_ray ray, t_obj *o);

t_ray		ray_translate(t_ray *ray, t_tuple translation);
t_ray		ray_scale(t_ray *ray, t_tuple scaling);
t_ray		ray_transform(t_ray *ray, t_matrix *transform);

void		sphere_set_transform(t_obj *sphere, t_matrix *translate, t_matrix *scale);
t_xsn		*intersect_world(t_world *w, t_ray r);
t_xsn		*intersect_hit(t_xsn **xslist);
t_xsn		*intersect_sp(t_ray ray, t_obj *o);

t_xsn		*x_new(t_obj *o, double x);
void		xadd_back(t_xsn	**xslist, t_xsn *n);

//LIGHT HEADER:
//sphere_normal:
t_tuple	sphere_normal_at(t_obj *s, t_tuple *w_point);
t_tuple	reflect(t_tuple *in, t_tuple *normal);

#endif
