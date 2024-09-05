/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:47:42 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/19 17:39:17 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*the determinant of a matrix is a single numerical value 
which is used when calculating the inverse or 
when solving systems of linear equations.*/

#include "../../includes/rtx.h"

void	matrix_det_2(t_matrix *m)
{
	m->determinant = (m->matrix[0][0] * m->matrix[1][1]) \
	- (m->matrix[0][1] * m->matrix[1][0]);
}

void	matrix_det_3(t_matrix *m)
{
	m->determinant = (m->matrix[0][0] * matrix_cofactor(m, 0, 0)) \
	+ (m->matrix[0][1] * matrix_cofactor(m, 0, 1)) \
	+ (m->matrix[0][2] * matrix_cofactor(m, 0, 2));
}

void	matrix_det_4(t_matrix *m)
{
	m->determinant = (m->matrix[0][0] * matrix_cofactor(m, 0, 0)) \
	+ (m->matrix[0][1] * matrix_cofactor(m, 0, 1)) \
	+ (m->matrix[0][2] * matrix_cofactor(m, 0, 2)) \
	+ (m->matrix[0][3] * matrix_cofactor(m, 0, 3));
}
