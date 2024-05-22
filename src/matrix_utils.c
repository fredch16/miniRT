/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:22:07 by fcharbon          #+#    #+#             */
/*   Updated: 2024/05/22 17:25:30 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"
#include <stdio.h>

// sets 4x4 matrix to identity matrix:
void	matrix_set(t_matrix *m)
{
	int			i;
	int			j;

	m->rows = 4;
	m->columns = 4;

	double values[4][4] = 
	{
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m->matrix[i][j] = values[i][j];
			j++;
		}
		i++;	
	}
}

//multiplies matrix a by matrix b and puts the result in matrix c:
void	matrix_multiply_matrix(t_matrix *a, t_matrix *b, t_matrix *c)
{
	int			row;
	int			col;

	row = 0;
	col = 0;
	c->columns  = 4;
	c->rows = 4;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			c->matrix[row][col] = (a->matrix[row][0] * b->matrix[0][col]) \
			+ (a->matrix[row][1] * b->matrix[1][col]) \
			+ (a->matrix[row][2] * b->matrix[2][col]) \
			+ (a->matrix[row][3] * b->matrix[3][col]);
			col++;
		}
		row++;
	}
}

//returns matrix multiplied by vector:
t_3d_vector	matrix_multiply_vector(t_matrix *m, t_3d_vector *vector)
{
	t_3d_vector	ret;

	ret.x = (m->matrix[0][0] * vector->x) \
	+ (m->matrix[0][1] * vector->y) \
	+ (m->matrix[0][2] * vector->z) \
	+ (m->matrix[0][3] * vector->w);
	ret.y = (m->matrix[1][0] * vector->x) \
	+ (m->matrix[1][1] * vector->y) \
	+ (m->matrix[1][2] * vector->z) \
	+ (m->matrix[1][3] * vector->w);
	ret.z = (m->matrix[2][0] * vector->x) \
	+ (m->matrix[2][1] * vector->y) \
	+ (m->matrix[2][2] * vector->z) \
	+ (m->matrix[2][3] * vector->w);
	ret.w = (m->matrix[3][0] * vector->x) \
	+ (m->matrix[3][1] * vector->y) \
	+ (m->matrix[3][2] * vector->z) \
	+ (m->matrix[3][3] * vector->w);
	return (ret);
}

//returns given matrix multiplied by identity matrix:
t_matrix	matrix_multiply_imatrix(t_matrix *m)
{
	t_matrix	im;
	t_matrix	res;

	matrix_set(&im);
	matrix_multiply_matrix(m, &im, &res);
	return (res);
}

void matrix_print(t_matrix *m)
{
	for (int i = 0; i < m->rows; i++) {
		for (int j = 0; j < m->columns; j++) {
			printf("%.2f ", m->matrix[i][j]);
		}
		printf("\n");
	}
}
