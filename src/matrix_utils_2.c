/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:40:35 by atyurina          #+#    #+#             */
/*   Updated: 2024/11/12 11:58:03 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

t_matrix	matrix_copy(t_matrix m)
{
	t_matrix	copy;

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

	if (m->determinant == 0)
		return (*m);
	im = matrix_cofactor_matrix(m);
	im = matrix_transpose(&im);
	im = matrix_div_det(&im, m->determinant);
	return (im);
}
