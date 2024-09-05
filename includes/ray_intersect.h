/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:50:14 by fcharbon          #+#    #+#             */
/*   Updated: 2024/08/19 20:06:32 by fcharbon         ###   ########.fr       */
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

void		sphere_set_transform(t_obj *sphere, t_matrix *translate);
t_xsn		*intersect_world(t_world *w, t_ray r);
t_xsn		*intersect_hit(t_xsn **xslist);
t_xsn		*intersect_sp(t_ray ray, t_obj *o);
t_xsn		*intersect_pl(t_ray ray, t_obj *o);
t_xsn		*intersect_cy(t_ray ray, t_obj *o);
t_xsn		*add_caps_cy(t_obj *cy, t_ray ray, t_xsn **xs);
t_xsn		*x_new(t_obj *o, double x);
void		xadd_back(t_xsn	**xslist, t_xsn *n);
void		free_xs(t_xsn **xslist);
void		free_obj(t_obj **objlist);

t_comps		prep_comps(t_xsn *x, t_ray ray, t_world *w);
t_colour	shade_hit(t_world *w, t_comps comps);
t_colour	colour_at(t_world *w, t_ray r);
t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up);

#endif
