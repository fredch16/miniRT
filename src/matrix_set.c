/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:08:51 by atyurina          #+#    #+#             */
/*   Updated: 2024/09/12 14:13:23 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

void	matrix_set_4(t_matrix *m)
{
	int			i;
	int			j;
	double		values[4][4];

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i == j)
				values[i][j] = 1.0;
			else
				values[i][j] = 0.0;
		}
	}
	i = 0;
	j = 0;
	*m = matrix_insert_vals(values, i, j);
}

static void	init_values_3(double values[3][3])
{
	values[0][0] = 1;
	values[0][1] = 0;
	values[0][2] = 0;
	values[1][0] = 0;
	values[1][1] = 1;
	values[1][2] = 0;
	values[2][0] = 0;
	values[2][1] = 0;
	values[2][2] = 1;
}

void	matrix_set_3(t_matrix *m)
{
	int			i;
	int			j;
	double		values[3][3];

	init_values_3(values);
	m->rows = 3;
	m->columns = 3;
	i = 0;
	j = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			m->matrix[i][j] = values[i][j];
			j++;
		}
		i++;
	}
}

void	matrix_set_2(t_matrix *m)
{
	int			i;
	int			j;
	double		values[2][2];

	m->rows = 2;
	m->columns = 2;
	values[0][0] = 1;
	values[0][1] = 0;
	values[1][0] = 0;
	values[1][1] = 1;
	i = 0;
	j = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			m->matrix[i][j] = values[i][j];
			j++;
		}
		i++;
	}
}

void	matrix_set_scaling(t_matrix *m, double x, double y, double z)
{
	matrix_set_4(m);
	m->matrix[0][0] = x;
	m->matrix[1][1] = y;
	m->matrix[2][2] = z;
}
