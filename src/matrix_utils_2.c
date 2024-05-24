/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:40:35 by atyurina          #+#    #+#             */
/*   Updated: 2024/05/22 21:40:36 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

//printinf a matrix values:
void	matrix_print(t_matrix *m)
{
	for (int i = 0; i < m->rows; i++) {
		for (int j = 0; j < m->columns; j++) {
			printf("%.2f ", m->matrix[i][j]);
		}
		printf("\n");
	}
}

//transpose a matrix // TODO return t_matrix of the tranposed one
//it turns its rows into columns and its columns into rows
void	matrix_transpose(t_matrix *m)
{
	t_matrix	copy1;
	int			i;
	int			j;

	copy1 = *m;
	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m->matrix[i][j] = copy1.matrix[j][i];
			j++;
		}
		i++;
	}
}

/*The minor of an element at row i and column j
is the determinant of the sub-matrix at (i,j). */
double	matrix_minor(t_matrix *m, int row, int col)
{
	t_matrix	sub;

	if (m->rows == 4 && m->columns == 4)
	{
		sub = matrix_sub_of4(m, row, col);
		matrix_det_3(&sub);
	}
	else if (m->rows == 3 && m->columns == 3)
	{
		sub = matrix_sub_of3(m, row, col);
		matrix_det_2(&sub);
	}
	return(sub.determinant);
}

/*They’re minors that have (possibly) had their sign changed.
if row + column is an odd number, then you negate the minor. 
Otherwise, you just return theminor as is.*/
double	matrix_cofactor(t_matrix *m, int row, int col)
{
	double	minor;

	minor = matrix_minor(m, row, col);
	if ((row + col) % 2 == 0)
		return(minor);
	else
		return(minor * (-1));
}
