/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_submatrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:48:28 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/19 17:39:07 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*A submatrix is what is left when you delete
a single row and column from a matrix.*/

#include "../../includes/rtx.h"

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
