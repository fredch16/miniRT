/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:17:41 by fcharbon          #+#    #+#             */
/*   Updated: 2024/05/22 17:11:17 by fcharbon         ###   ########.fr       */
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

t_3d_vector vector_add(t_3d_vector a, t_3d_vector b)
{
	t_3d_vector	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	result.w = a.w + b.w;
	if (result.w == 2)
		printf("Vector Addition Error. Two vectors cannot be added\n");
	return (result);
}

t_3d_vector vector_sub(t_3d_vector a, t_3d_vector b)
{
	t_3d_vector	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	result.w = a.w - b.w;
	if (result.w == -1)
		printf("Vector Subtraction Error. Cannoy subtract a point from vector.\n");
	return (result);
}

t_3d_vector vector_neg(t_3d_vector a)
{
	t_3d_vector	result;

	result.x = -a.x;
	result.y = -a.y;
	result.z = -a.z;
	result.w = -a.w;
	return (result);
}

void vector_mul(double mutliplier, t_3d_vector *a) 
{
	a->x = mutliplier * a->x;
	a->y = mutliplier * a->y;
	a->z = mutliplier * a->z;
	a->w = mutliplier * a->w;
}

double	vector_abs(t_3d_vector v)
{
	double	temp;

	temp = (v.x * v.x) + (v.y * v.y) + (v.z * v.z);
	return (sqrt(temp));
}

void	vector_print(t_3d_vector v)
{
	printf("Vector is (%.2f, %.2f, %.2f)\n", v.x, v.y, v.z);
}

t_3d_vector vector_norm(t_3d_vector v)
{
	t_3d_vector	result;

	result.x = v.x / vector_abs(v);
	result.y = v.y / vector_abs(v);
	result.z = v.z / vector_abs(v);
	return (result);
}

double	vector_dot(t_3d_vector a, t_3d_vector b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_3d_vector	vector_cro(t_3d_vector a, t_3d_vector b)
{
	t_3d_vector	result;

	result.x = (a.y * b.z) - (a.z * b.y);
	result.y = (a.z * b.x) - (a.x * b.z);
	result.x = (a.x * b.y) - (a.y * b.x);
	return (result);
}
