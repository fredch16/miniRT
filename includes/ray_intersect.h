/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:50:14 by fcharbon          #+#    #+#             */
/*   Updated: 2024/06/03 18:48:43 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_INTERSECT_H
# define RAY_INTERSECT_H

# include "minirt_types.h"

void		ray_create(t_ray *ray, t_tuple origin, t_tuple direction);
t_tuple		ray_position(t_ray *ray, double scalar);
void		obj_add_back(t_obj	**objlist, t_obj *n);
t_obj		*obj_create(enum e_obj_type ot);
t_xs		get_intersects(t_ray *ray, t_data *data);

#endif
