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

// sets 4x4 identity matrix:
void	matrix_set_4(t_matrix *m)
{
	int			i;
	int			j;

	m->rows = 4;
	m->columns = 4;
	double values[4][4] = 
	{
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
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

// sets 3x3 identity matrix:
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

// sets 2x2 identity matrix:
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
