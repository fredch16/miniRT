/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:40:35 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/18 15:46:27 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

//printinf a matrix values:
void	matrix_print(t_matrix *m)
{
	for (int i = 0; i < m->rows; i++) {
		for (int j = 0; j < m->columns; j++) {
			printf("%.5f ", m->matrix[i][j]);
		}
		printf("\n");
	}
}

//transpose a matrix
//it turns its rows into columns and its columns into rows
t_matrix	matrix_transpose(t_matrix *m)
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
			copy1.matrix[j][i] = m->matrix[i][j];
			j++;
		}
		i++;
	}
	return (copy1);
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

t_matrix	matrix_copy(t_matrix m)
{
	t_matrix copy;

	copy = m;
	return (copy);
}

t_matrix	matrix_cofactor_matrix(t_matrix *m)
{
	t_matrix	c_m;
	int			i;
	int			j;

	matrix_set_4(&c_m);
	c_m = *m;
	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c_m.matrix[i][j] = matrix_cofactor(m, i, j);
			j++;
		}
		i++;	
	}
	return (c_m);
}

t_matrix	matrix_div_det(t_matrix *m, double det)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m->matrix[i][j] = m->matrix[i][j] / det;
			j++;
		}
		i++;	
	}
	return (*m);
}

// dont forget to set a determinant
// before trying to inverse!!!
t_matrix	matrix_inverse(t_matrix *m)
{
	t_matrix	im;

	// matrix_det_4(m);
	if (m->determinant == 0)
		return(*m);
	im = matrix_cofactor_matrix(m);
	im = matrix_transpose(&im);
	im = matrix_div_det(&im, m->determinant);
	return (im);
}
