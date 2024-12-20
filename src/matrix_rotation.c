/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:41:49 by atyurina          #+#    #+#             */
/*   Updated: 2024/09/12 14:13:27 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

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

void	matrix_set_translation(t_matrix *m, double x, double y, double z)
{
	matrix_set_4(m);
	m->matrix[0][3] = x;
	m->matrix[1][3] = y;
	m->matrix[2][3] = z;
}
