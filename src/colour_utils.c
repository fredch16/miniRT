/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:12:27 by fcharbon          #+#    #+#             */
/*   Updated: 2024/05/21 15:48:15 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

t_colour colour_add(t_colour c1, t_colour c2)
{
	t_colour	result;

	result.r = c1.r + c2.r;
	result.b = c1.b + c2.b;
	result.g = c1.g + c2.g;
	return (result);
}

t_colour colour_sub(t_colour c1, t_colour c2)
{
	t_colour	result;

	result.r = c1.r - c2.r;
	result.b = c1.b - c2.b;
	result.g = c1.g - c2.g;
	return (result);
}

t_colour colour_sca_mul(double multiplier, t_colour c1)
{
	t_colour	result;

	result.r = c1.r * multiplier;
	result.b = c1.b * multiplier;
	result.g = c1.g * multiplier;
	return (result);
}

t_colour colour_mul(t_colour c1, t_colour c2)
{
	t_colour	result;

	result.r = c1.r * c2.r;
	result.b = c1.b * c2.b;
	result.g = c1.g * c2.g;
	return (result);
}

t_colour	colour_set(double r, double g, double b)
{
	t_colour	colour;

	colour.r = r;
	colour.g = g;
	colour.b = b;
	return (colour);
}
