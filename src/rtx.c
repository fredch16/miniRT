/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:16:31 by fcharbon          #+#    #+#             */
/*   Updated: 2024/05/20 20:14:09 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

int	main(void)
{
	t_3d_vector a;
	t_3d_vector b;

	a.x = 1;
	a.y = 2;
	a.z = 3;
	b.x = 4;
	b.y = -5;
	b.z = 6;

	// vector_print(vector_neg(a));
	// vector_print(vector_neg(b));
	printf("%.4f\n", vector_abs(a));
	printf("%.4f\n", (vector_abs(b)));
}
