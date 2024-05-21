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

	result.red = c1.red + c2.red;
	result.blue = c1.blue + c2.blue;
	result.green = c1.green + c2.green;
	return (result);
}

t_colour colour_sub(t_colour c1, t_colour c2)
{
	t_colour	result;

	result.red = c1.red - c2.red;
	result.blue = c1.blue - c2.blue;
	result.green = c1.green - c2.green;
	return (result);
}

t_colour colour_sca_mul(double multiplier, t_colour c1)
{
	t_colour	result;

	result.red = c1.red * multiplier;
	result.blue = c1.blue * multiplier;
	result.green = c1.green * multiplier;
	return (result);
}

t_colour colour_mul(t_colour c1, t_colour c2)
{
	t_colour	result;

	result.red = c1.red * c2.red;
	result.blue = c1.blue * c2.blue;
	result.green = c1.green * c2.green;
	return (result);
}
