/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:17:41 by fcharbon          #+#    #+#             */
/*   Updated: 2024/08/19 20:26:39 by fcharbon         ###   ########.fr       */
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

t_tuple	tuple_add(t_tuple a, t_tuple b)
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

t_tuple	tuple_sub(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	result.w = a.w - b.w;
	if (result.w == -1)
		ft_printf("Cannot subtract a point from tuple.\n");
	return (result);
}

t_tuple	tuple_neg(t_tuple a)
{
	t_tuple	result;

	result.x = -a.x;
	result.y = -a.y;
	result.z = -a.z;
	result.w = -a.w;
	return (result);
}

void	tuple_mul(double mutliplier, t_tuple *a)
{
	a->x = mutliplier * a->x;
	a->y = mutliplier * a->y;
	a->z = mutliplier * a->z;
	a->w = mutliplier * a->w;
}
