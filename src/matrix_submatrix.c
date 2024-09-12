/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_submatrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:48:28 by atyurina          #+#    #+#             */
/*   Updated: 2024/09/12 14:20:56 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*A submatrix is what is left when you delete
a single row and column from a matrix.*/

#include "../includes/rtx.h"

t_matrix	matrix_sub_of4(t_matrix *m, int row, int col)
{
	t_subm_attr	sub;

	sub.i = 0;
	sub.j = 0;
	matrix_set_3(&sub.s);
	while (sub.i < 4)
	{
		sub.j = 0;
		while (sub.j < 4)
		{
			if (sub.i != row && sub.j != col)
			{
				sub.si = sub.i;
				sub.sj = sub.j;
				if (sub.i > row)
					sub.si--;
				if (sub.j > col)
					sub.sj--;
				sub.s.matrix[sub.si][sub.sj] = m->matrix[sub.i][sub.j];
			}
			sub.j++;
		}
		sub.i++;
	}
	return (sub.s);
}

t_matrix	matrix_sub_of3(t_matrix *m, int row, int col)
{
	t_subm_attr	sub;

	sub.i = 0;
	sub.j = 0;
	matrix_set_2(&sub.s);
	while (sub.i < 3)
	{
		sub.j = 0;
		while (sub.j < 3)
		{
			if (sub.i != row && sub.j != col)
			{
				sub.si = sub.i;
				sub.sj = sub.j;
				if (sub.i > row)
					sub.si--;
				if (sub.j > col)
					sub.sj--;
				sub.s.matrix[sub.si][sub.sj] = m->matrix[sub.i][sub.j];
			}
			sub.j++;
		}
		sub.i++;
	}
	return (sub.s);
}

t_matrix	matrix_insert_vals(double values[4][4], int i, int j)
{
	t_matrix	m;

	m.rows = 4;
	m.columns = 4;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m.matrix[i][j] = values[i][j];
			j++;
		}
		i++;
	}
	return (m);
}
