/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:26:55 by fcharbon          #+#    #+#             */
/*   Updated: 2024/08/19 20:27:24 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

t_tuple	tuple_poi(double x, double y, double z)
{
	t_tuple	result;

	result.x = x;
	result.y = y;
	result.z = z;
	result.w = 1;
	return (result);
}

t_tuple	tuple_vec(double x, double y, double z)
{
	t_tuple	result;

	result.x = x;
	result.y = y;
	result.z = z;
	result.w = 0;
	return (result);
}
