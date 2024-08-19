/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:41:49 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/19 17:39:00 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtx.h"

void	matrix_set_rotation_x(t_matrix *m, double r)
{
	matrix_set_4(m);
	m->matrix[1][1] = cos(r);
	m->matrix[1][2] = -sin(r);
	m->matrix[2][1] = sin(r);
	m->matrix[2][2] = cos(r);
}

void	matrix_set_rotation_y(t_matrix *m, double r)
{
	matrix_set_4(m);
	m->matrix[0][0] = cos(r);
	m->matrix[0][2] = sin(r);
	m->matrix[2][0] = -sin(r);
	m->matrix[2][2] = cos(r);
}

void	matrix_set_rotation_z(t_matrix *m, double r)
{
	matrix_set_4(m);
	m->matrix[0][0] = cos(r);
	m->matrix[0][1] = -sin(r);
	m->matrix[1][0] = sin(r);
	m->matrix[1][1] = cos(r);
}

void	matrix_set_shearing(t_matrix *m, double *shearing)
{
	matrix_set_4(m);
	m->matrix[0][1] = shearing[0];
	m->matrix[0][2] = shearing[1];
	m->matrix[1][0] = shearing[2];
	m->matrix[1][2] = shearing[3];
	m->matrix[2][0] = shearing[4];
	m->matrix[2][1] = shearing[5];
}
