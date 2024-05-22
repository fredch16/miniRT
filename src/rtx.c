/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:16:31 by fcharbon          #+#    #+#             */
/*   Updated: 2024/05/22 17:35:31 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

int	main(void)
	{
	t_data data;
	t_matrix matA;
	t_matrix matB;
	t_matrix matC;

	data.velocity.x = 1;
	data.velocity.y = -1.7;
	data.velocity.z = 0;
	data.velocity.w = 1;

	data.velocity = vector_norm(data.velocity);
	vector_mul(9, &data.velocity);
	
	// vector_print(vector_neg(a));
	// vector_print(vector_neg(b));
	// printf("%.4f\n", vector_abs(a));
	// printf("%.4f\n", (vector_abs(b)));
	set_matrix(&matA);
	set_matrix(&matB);
	matrix_multiply(&matA, &matB, &matC);
	print_matrix(matA);
	print_matrix(matB);
	print_matrix(matC);
	init_mlx(&data);
}
