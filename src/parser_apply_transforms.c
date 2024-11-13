/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_apply_transforms.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:12:17 by atyurina          #+#    #+#             */
/*   Updated: 2024/11/13 18:13:01 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

t_matrix	get_rotator(t_tuple defa, t_tuple na)
{
	t_tuple		axis;
	t_trigon	tr;
	t_matrix	trans;

	axis = tuple_cro(defa, na);
	if (tuple_abs(axis) > EPSILON)
		axis = tuple_norm(axis);
	tr.c = tuple_dot(defa, na);
	tr.angle = acos(tr.c);
	tr.c = cos(tr.angle);
	tr.s = sin(tr.angle);
	tr.t = 1 - cos(tr.angle);
	matrix_set_4(&trans);
	trans.matrix[0][0] = tr.c + na.x * na.x * tr.t;
	trans.matrix[0][1] = (na.x * na.y * tr.t) - (na.z * tr.s);
	trans.matrix[0][2] = (na.x * na.z * tr.t) + (na.y * tr.s);
	trans.matrix[1][0] = (na.y * na.x * tr.t) + (na.z * tr.s);
	trans.matrix[1][1] = tr.c + (na.y * na.y * tr.t);
	trans.matrix[1][2] = (na.y * na.z * tr.t) - (na.x * tr.s);
	trans.matrix[2][0] = (na.z * na.x * tr.t) - (na.y * tr.s);
	trans.matrix[2][1] = (na.z * na.y * tr.t) + (na.x * tr.s);
	trans.matrix[2][2] = tr.c + (na.z * na.z * tr.t);
	return (trans);
}

t_matrix	get_final_trans(t_matrix *trans, t_matrix *scal, t_matrix *rot)
{
	t_matrix	t1;
	t_matrix	ret;

	matrix_set_4(&t1);
	matrix_multiply_matrix(trans, scal, &t1);
	matrix_multiply_matrix(&t1, rot, &ret);
	return (ret);
}
