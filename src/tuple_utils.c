/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:17:41 by fcharbon          #+#    #+#             */
/*   Updated: 2024/06/06 20:07:51 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"
int	equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (1);
	else
		return (0);
}

t_tuple tuple_add(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	result.w = a.w + b.w;
	if (result.w == 2)
		printf("tuple Addition Error. Two tuples cannot be added\n");
	return (result);
}

t_tuple tuple_sub(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	result.w = a.w - b.w;
	if (result.w == -1)
		printf("tuple Subtraction Error. Cannoy subtract a point from tuple.\n");
	return (result);
}

t_tuple tuple_neg(t_tuple a)
{
	t_tuple	result;

	result.x = -a.x;
	result.y = -a.y;
	result.z = -a.z;
	result.w = -a.w;
	return (result);
}

void tuple_mul(double mutliplier, t_tuple *a) 
{
	a->x = mutliplier * a->x;
	a->y = mutliplier * a->y;
	a->z = mutliplier * a->z;
	a->w = mutliplier * a->w;
}

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

t_tuple tuple_norm(t_tuple v)
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
	result.x = (a.x * b.y) - (a.y * b.x);
	return (result);
}

t_tuple	tuple_poi(double x, double y, double z)
{
	t_tuple result;

	result.x = x;
	result.y = y;
	result.z = z;
	result.w = 1;
	return (result);
}

t_tuple	tuple_vec(double x, double y, double z)
{
	t_tuple result;

	result.x = x;
	result.y = y;
	result.z = z;
	result.w = 0;
	return (result);
}
