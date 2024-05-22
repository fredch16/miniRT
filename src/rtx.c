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
	//t_matrix matB;
	//t_matrix matC;
	//t_3d_vector	vector;

	// vector.x = 1;
	// vector.y = 2;
	// vector.z = 3;
	// vector.w = 1;
	data.velocity.x = 1;
	data.velocity.y = -1.7;
	data.velocity.z = 0;
	data.velocity.w = 1;

	data.velocity = vector_norm(data.velocity);
	vector_mul(9, &data.velocity);
	
	//init_mlx(&data);
}

/// operations tests
	//////////////////////////////////TRANSPOSING
	// matrix_set(&matA);
	// matA.matrix[0][1] = 3;
	// matA.matrix[0][2] = 4;
	// matA.matrix[0][3] = 5;
	// matA.matrix[1][0] = 8;
	// matrix_print(&matA);
	// matrix_transpose(&matA);
	// matrix_print(&matA);
	/////////////////// MULTIBLICATION BY I MATRIX
	// matrix_set(&matA);
	// matB = matrix_multiply_imatrix(&matA);
	// matrix_print(&matB);
	//////////////////////////////////
	// vector_print(vector_neg(a));
	// vector_print(vector_neg(b));
	// printf("%.4f\n", vector_abs(a));
	// printf("%.4f\n", (vector_abs(b)));
	///////////////////////////////////
	// matrix_set(&matA);
	// matrix_set(&matB);
	// matrix_multiply_matrix(&matA, &matB, &matC);
	// vector = matrix_multiply_vector(&matA, &vector);
	// vector_print(vector);
	/////////////////////////////////////////////////////
	//matrix_print(matA);
	//matrix_print(matB);
	//matrix_print(matC);