/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:18:43 by atyurina          #+#    #+#             */
/*   Updated: 2024/09/12 13:48:30 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

//multiplies matrix a by matrix b and puts the result in matrix c:

void	matrix_multiply_matrix(t_matrix *a, t_matrix *b, t_matrix *c)
{
	int			row;
	int			col;

	row = 0;
	col = 0;
	c->columns = 4;
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

//returns tuple multiplied by matrix:
t_tuple	matrix_multiply_tuple(t_matrix *m, t_tuple *tuple)
{
	t_tuple	ret;

	ret.x = (m->matrix[0][0] * tuple->x) \
	+ (m->matrix[0][1] * tuple->y) \
	+ (m->matrix[0][2] * tuple->z) \
	+ (m->matrix[0][3] * tuple->w);
	ret.y = (m->matrix[1][0] * tuple->x) \
	+ (m->matrix[1][1] * tuple->y) \
	+ (m->matrix[1][2] * tuple->z) \
	+ (m->matrix[1][3] * tuple->w);
	ret.z = (m->matrix[2][0] * tuple->x) \
	+ (m->matrix[2][1] * tuple->y) \
	+ (m->matrix[2][2] * tuple->z) \
	+ (m->matrix[2][3] * tuple->w);
	ret.w = (m->matrix[3][0] * tuple->x) \
	+ (m->matrix[3][1] * tuple->y) \
	+ (m->matrix[3][2] * tuple->z) \
	+ (m->matrix[3][3] * tuple->w);
	return (ret);
}

//returns given matrix multiplied by identity matrix:
t_matrix	matrix_multiply_imatrix(t_matrix *m)
{
	t_matrix	im;
	t_matrix	res;

	if (m->columns == 4 && m->rows == 4)
		matrix_set_4(&im);
	matrix_multiply_matrix(m, &im, &res);
	return (res);
}
