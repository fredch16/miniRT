/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:51:54 by fcharbon          #+#    #+#             */
/*   Updated: 2024/09/12 14:02:20 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "minirt_types.h"

//matrix_set - set identity matrix; set translation matrix, set scaling matrix
void		matrix_set_4(t_matrix *m);
void		matrix_set_3(t_matrix *m);
void		matrix_set_2(t_matrix *m);
void		matrix_set_translation(t_matrix *m, double x, double y, double z);
void		matrix_set_scaling(t_matrix *m, double x, double y, double z);

//matrix_rotation 
void		matrix_set_rotation_x(t_matrix *m, double r);
void		matrix_set_rotation_y(t_matrix *m, double r);
void		matrix_set_rotation_z(t_matrix *m, double r);
void		matrix_set_shearing(t_matrix *m, double *shearing);

//matrix multiplication:
void		matrix_multiply_matrix(t_matrix *a, t_matrix *b, t_matrix *result);
t_tuple		matrix_multiply_tuple(t_matrix *m, t_tuple *tuple);
t_matrix	matrix_multiply_imatrix(t_matrix *m);
t_tuple		tuple_mul_transm(t_tuple *tuple, t_matrix *tm);

// matrix determinant:
void		matrix_det_2(t_matrix *m);
void		matrix_det_3(t_matrix *m);
void		matrix_det_4(t_matrix *m);

//matrix submatrix:
t_matrix	matrix_sub_of4(t_matrix *m, int row, int col);
t_matrix	matrix_sub_of3(t_matrix *m, int row, int col);
t_matrix	matrix_insert_vals(double values[4][4], int i, int j);

//matrix_utils_2
void		matrix_print(t_matrix *mat);
t_matrix	matrix_transpose(t_matrix *m);
double		matrix_cofactor(t_matrix *m, int row, int col);
t_matrix	matrix_div_det(t_matrix *m, double det);
t_matrix	matrix_inverse(t_matrix *m);

#endif
