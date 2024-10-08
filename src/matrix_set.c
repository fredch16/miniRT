/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:08:51 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/19 21:45:01 by fcharbon         ###   ########.fr       */
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
	m->rows = 4;
	m->columns = 4;
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

void	matrix_set_3(t_matrix *m)
{
	int			i;
	int			j;

	m->rows = 3;
	m->columns = 3;
	double values[3][3] = 
	{
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}

	};
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

	m->rows = 2;
	m->columns = 2;
	double values[2][2] = 
	{
		{1, 0},
		{0, 1}
	};
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

void	matrix_set_translation(t_matrix *m, double x, double y, double z)
{
	matrix_set_4(m);
	m->matrix[0][3] = x;
	m->matrix[1][3] = y;
	m->matrix[2][3] = z;
}

void	matrix_set_scaling(t_matrix *m, double x, double y, double z)
{
	matrix_set_4(m);
	m->matrix[0][0] = x;
	m->matrix[1][1] = y;
	m->matrix[2][2] = z;
}
