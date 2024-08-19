/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:25:11 by fcharbon          #+#    #+#             */
/*   Updated: 2024/08/19 20:59:31 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

double	tuple_abs(t_tuple v)
{
	double	temp;

	temp = (v.x * v.x) + (v.y * v.y) + (v.z * v.z);
	return (sqrt(temp));
}

void	tuple_print(t_tuple v)
{
	printf("tuple is (%.5f, %.5f, %.5f) w = %i\n", v.x, v.y, v.z, v.w);
}

t_tuple	tuple_norm(t_tuple v)
{
	t_tuple	result;

	result.x = v.x / tuple_abs(v);
	result.y = v.y / tuple_abs(v);
	result.z = v.z / tuple_abs(v);
	result.w = v.w / tuple_abs(v);
	return (result);
}

double	tuple_dot(t_tuple a, t_tuple b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_tuple	tuple_cro(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result.x = (a.y * b.z) - (a.z * b.y);
	result.y = (a.z * b.x) - (a.x * b.z);
	result.z = (a.x * b.y) - (a.y * b.x);
	result.w = 0;
	return (result);
}

