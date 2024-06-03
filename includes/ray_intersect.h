/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:50:14 by fcharbon          #+#    #+#             */
/*   Updated: 2024/05/24 14:19:55 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_INTERSECT_H
# define RAY_INTERSECT_H

# include "minirt_types.h"

void		ray_create(t_ray *ray, t_tuple origin, t_tuple direction);
t_tuple		ray_position(t_ray *ray, double scalar);

#endif
