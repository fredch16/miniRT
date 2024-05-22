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

void	set_matrix(t_matrix *m)
{
	int			i;
	int			j;

	m->rows = 4;
	m->columns = 4;

	double values[4][4] = 
	{
		{1, 2, 3, 4},
		{2, 4, 4, 2},
		{8, 6, 4, 1},
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

void	matrix_multiply(t_matrix *a, t_matrix *b, t_matrix *c)
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

t_3d_vector	matrix_multiply_by_vector(t_matrix *m, t_3d_vector *vector)
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

void print_matrix(t_matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.columns; j++) {
            printf("%.2f ", m.matrix[i][j]);
        }
        printf("\n");
    }
}

// int main() {
//     t_matrix a = set_matrix();
// 	t_matrix b = set_matrix();
// 	t_matrix c = matrix_multiply(&a, &b);
//     print_matrix(c);
//     return 0;
// }
// void	matrix_print(t_matrix	*mat)
// {
// 	int	i;
// 	int	j;
//
// 	i = 0;
// 	j = 0;
//
// 	while (i < 4)
// 	{
// 		j = 0;
// 		while(j < 4)
// 		{
// 			printf("%.1f ", mat->M[i][j++]);
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }
//
// void	matrix_create(t_matrix *mat)
// {
// 	int	i;
// 	int	j;
//
// 	i = 0;
// 	j = 0;
//
// 	while (i < 4)
// 	{
// 		j = 0;
// 		while(j < 4)
// 		{
// 			mat->M[i][j++] = 0;
// 		}
// 		i++;
// 	}
// }
//
// void	matrix_fill(t_matrix *mat, double	*nums)
// {
// 	int	i;
// 	int	j;
//
// 	i = 0;
// 	j = 0;
//
// 	while (i < 4)
// 	{
// 		j = 0;
// 		while(j < 4)
// 		{
// 			mat->M[i][j++] = nums[k];
// 		}
// 		i++;
// 	}
// }
