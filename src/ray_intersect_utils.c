/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:21:56 by fcharbon          #+#    #+#             */
/*   Updated: 2024/05/31 12:21:51 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

void	ray_create(t_ray *ray, t_tuple origin, t_tuple direction)
{
	ray->origin = origin;
	ray->direction = direction;
}

t_tuple	ray_position(t_ray *ray, double scalar)
{
	t_tuple	position;
	t_tuple	distance;

	distance = ray->direction;
	tuple_mul(scalar, &distance);
	position = tuple_add(ray->origin, distance);
	return (position);
}

// t_obj	*obj_create(enum e_obj_type ot)
// {
// 	t_obj	*new;
// 	new = ft_calloc(1, sizeof(t_obj));
// 	if (!new)
// 		return (NULL);
// 	new	-> type = ot;
// 	return (new);
// }
//
// void	obj_add_back(t_obj	**objlist, t_obj *n)
// {
// 	t_obj	*tmp;
//
// 	if (!objlist || !n)
// 		return ;
// 	if (!*objlist)
// 		*objlist = n;
// 	else
// 	{
// 		tmp = *objlist;
// 		while (tmp -> next)
// 			tmp = tmp -> next;
// 		tmp -> next = n;
// 	}
// }
