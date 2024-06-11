/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:00:38 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/11 13:00:40 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

t_tuple	sphere_normal_at(t_obj *s, t_tuple *w_point)
{
	t_tuple		obj_point;
	t_tuple		obj_normal;
	t_tuple		w_normal;
	t_matrix	i_m;
	t_matrix	t_m;
	t_tuple		point;

	tuple_poi(0, 0, 0);
	matrix_det_4(&s->transform);
	i_m = matrix_inverse(&s->transform);
	obj_point = matrix_multiply_tuple(&i_m, w_point);
	obj_normal = tuple_sub(obj_point, point);
	obj_normal.w = 0;
	t_m = matrix_transpose(&i_m);
	w_normal = matrix_multiply_tuple(&t_m, &obj_normal);
	w_normal.w = 0;
	return (tuple_norm(w_normal));
}