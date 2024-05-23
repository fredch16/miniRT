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

//transpose a matrix 
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

/*the determinant of a matrix 
is a single numerical value 
which is used when calculating 
the inverse or when solving systems
 of linear equations.*/

//finding a determinant of 2x2 matrix:
void	matrix_det_2(t_matrix *m)
{
	m->determinant = (m->matrix[0][0] * m->matrix[1][1]) \
	- (m->matrix[0][1] * m->matrix[1][0]);
}

t_matrix	matrix_sub_of4(t_matrix *m, int row, int col)
{
	t_matrix	s;
	int			i;
	int			j;
	int			si;
	int			sj;

	i = 0;
	j = 0;
	matrix_set_3(&s);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i != row && j != col)
			{
				si = i;
				sj = j;
				if (i > row)
					si--;
				if (j > col)
					sj--;
				s.matrix[si][sj] = m->matrix[i][j];
			}
			j++;
		}
		i++;	
	}
	return (s);
}

t_matrix	matrix_sub_of3(t_matrix *m, int row, int col)
{
	t_matrix	s;
	int			i;
	int			j;
	int			si;
	int			sj;

	i = 0;
	j = 0;
	matrix_set_2(&s);
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (i != row && j != col)
			{
				si = i;
				sj = j;
				if (i > row)
					si--;
				if (j > col)
					sj--;
				s.matrix[si][sj] = m->matrix[i][j];
			}
			j++;
		}
		i++;	
	}
	return (s);
}

double	matrix_minor(t_matrix *m, int row, int col)
{
	t_matrix	sub;

	if (m->rows == 4 && m->columns == 4)
	{
		sub = matrix_sub_of4(m, row, col); //TODO детерминант 3
	}
	else if (m->rows == 3 && m->columns == 3)
	{
		sub = matrix_sub_of3(m, row, col);
		matrix_det_2(&sub);
	}
	return(sub.determinant);
}

double	matrix_cofactor(t_matrix *m, int row, int col)
{
	double	minor;
	double	sum;

	sum = (double)(row + col);
	minor = matrix_minor(m, row, col);
	if (sum % 2 == 0)
		return(minor);
	else
		return(minor * (-1));
}
