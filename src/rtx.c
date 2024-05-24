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
//	t_data data;
	t_matrix matA;
	t_matrix matB;
	t_matrix matC;
	t_matrix matD;
	t_matrix matE;
	//t_3d_vector	vector;

	// vector.x = 1;
	// vector.y = 2;
	// vector.z = 3;
	// vector.w = 1;

	matrix_set_4(&matA);
matA.matrix[0][0] = 3;
matA.matrix[0][1] = -9;
matA.matrix[0][2] = 7;
matA.matrix[0][3] = 3;

matA.matrix[1][0] = 3;
matA.matrix[1][1] = -8;
matA.matrix[1][2] = 2;
matA.matrix[1][3] = -9;

matA.matrix[2][0] = -4;
matA.matrix[2][1] = 4;
matA.matrix[2][2] = 4;
matA.matrix[2][3] = 1;

matA.matrix[3][0] = -6;
matA.matrix[3][1] = 5;
matA.matrix[3][2] = -1;
matA.matrix[3][3] = 1;

matrix_set_4(&matB);
matB.matrix[0][0] = 8;
matB.matrix[0][1] = 2;
matB.matrix[0][2] = 2;
matB.matrix[0][3] = 2;

matB.matrix[1][0] = 3;
matB.matrix[1][1] = -1;
matB.matrix[1][2] = 7;
matB.matrix[1][3] = 0;

matB.matrix[2][0] = 7;
matB.matrix[2][1] = 0;
matB.matrix[2][2] = 5;
matB.matrix[2][3] = 4;

matB.matrix[3][0] = 6;
matB.matrix[3][1] = -2;
matB.matrix[3][2] = 0;
matB.matrix[3][3] = 5;
matrix_set_4(&matC);

//	double	cofactor;
	//cofactor = matrix_cofactor(&matA, 0, 3);
	matrix_det_4(&matA);
	matrix_det_4(&matB);
	matrix_set_4(&matD);
	matrix_set_4(&matE);
	matrix_multiply_matrix(&matA, &matB, &matC);
	matE = matrix_inverse(&matB);
	matrix_multiply_matrix(&matC, &matE, &matD);
	matrix_print(&matA);
	matrix_print(&matB);
	matrix_print(&matC);
	matrix_print(&matD);
	matrix_print(&matE);
	// matrix_det_4(&matB);
	// matC = matrix_inverse(&matA);
	// matrix_print(&matA);
	// matrix_print(&matB);
	// matrix_print(&matC);
	// matrix_multiply_matrix(&matA, &matB, &matC);
	//init_mlx(&data);
}

///////////////////COFACTOR and DETERMINANT
	// matrix_set_4(&matA);
	// matA.matrix[0][0] = -2;
    // matA.matrix[0][1] = -8;
    // matA.matrix[0][2] = 3;
	// matA.matrix[0][3] = 5;

    // matA.matrix[1][0] = -3;
    // matA.matrix[1][1] = 1;
    // matA.matrix[1][2] = 7;
	// matA.matrix[1][3] = 3;


    // matA.matrix[2][0] = 1;
    // matA.matrix[2][1] = 2;
    // matA.matrix[2][2] = -9;
	// matA.matrix[2][3] = 6;

    // matA.matrix[3][0] = -6;
    // matA.matrix[3][1] = 7;
    // matA.matrix[3][2] = 7;
	// matA.matrix[3][3] = -9;

	// double	cofactor;
	// cofactor = matrix_cofactor(&matA, 0, 3);
	// matrix_det_4(&matA);
	// matrix_print(&matA);
	// printf("determinant = %.2f\ncofactor = %.2f", matA.determinant, cofactor);
//determinant = %.2f\n
/// operations tests
	///////////////////////FIND SUBMATRIX OF 4X4
	// matrix_set_4(&matA);
    // matA.matrix[0][0] = -6;
    // matA.matrix[0][1] = 1;
    // matA.matrix[0][2] = 1;
    // matA.matrix[0][3] = 6;

    // matA.matrix[1][0] = -8;
    // matA.matrix[1][1] = 5;
    // matA.matrix[1][2] = 8;
    // matA.matrix[1][3] = 6;

    // matA.matrix[2][0] = -1;
    // matA.matrix[2][1] = 0;
    // matA.matrix[2][2] = 8;
    // matA.matrix[2][3] = 2;

    // matA.matrix[3][0] = -7;
    // matA.matrix[3][1] = 1;
    // matA.matrix[3][2] = -1;
    // matA.matrix[3][3] = 1;
	// matB = matrix_sub_of4(&matA, 2, 1);
	// matrix_print(&matA);
	// matrix_print(&matB);
	//////////////////////FIND DETERMINANT MATRIX 2X2
	// matrix_set_2(&matA);
	// matA.matrix[0][0] = 1;
	// matA.matrix[0][1] = 5;
	// matA.matrix[1][1] = 2;
	// matA.matrix[1][0] = -3;
	// matrix_det_2(&matA);
	// matrix_print(&matA);
	// printf("%.2f\n", matA.determinant);
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