/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:05:52 by fcharbon          #+#    #+#             */
/*   Updated: 2024/05/22 17:25:27 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include <stdint.h>
# define WIN_WIDTH 1600 
# define WIN_HEIGHT	900 
# define EPSILON 0.00001
# include "../includes/libft/libft.h"
# include "../includes/mlx_linux/mlx.h"
# include <math.h>
# include <errno.h>
# include <X11/keysym.h>
#include <stdio.h>

typedef struct s_rgb
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
}	t_rgb;

typedef struct s_matrix
{
	double	matrix[4][4];
	double	determinant;
	int	columns;
	int	rows;

}	t_matrix;

typedef struct s_colour
{
	double	red;
	double	green;
	double	blue;
}	t_colour;

typedef struct s_3d_vector
{
	double		x;
	double		y;
	double		z;
	int			w;
}	t_3d_vector;

typedef struct s_data
{
	void	*mlx;
	void	*img;
	void	*addr;
	void	*win;
	int		bpp;
	int		endian;
	int		line_len;
	t_3d_vector velocity;
}	t_data;

//vector utils;
int			equal(double a, double b);
t_3d_vector vector_add(t_3d_vector a, t_3d_vector b);
t_3d_vector vector_sub(t_3d_vector a, t_3d_vector b);
t_3d_vector vector_neg(t_3d_vector a);
void		vector_mul(double mutliplier, t_3d_vector *a);
double		vector_abs(t_3d_vector v);
void		vector_print(t_3d_vector v);
t_3d_vector vector_norm(t_3d_vector v);
double		vector_dot(t_3d_vector a, t_3d_vector b);

//colour utils
t_colour	colour_add(t_colour c1, t_colour c2);
t_colour	 colour_sub(t_colour c1, t_colour c2);
t_colour	 colour_sca_mul(double multiplier, t_colour c1);
t_colour	 colour_mul(t_colour c1, t_colour c2);

//mlx utils
void		put_pixel_img(t_data *data, int x, int y, int colour);
void		init_mlx(t_data *data);

//drawing
void		draw_circle(t_data *data, int	radius);
void		draw_projectile(t_data *data, int startx, int starty, t_3d_vector velocity);

//matrix_utils - set identity matrix
void		matrix_set_4(t_matrix *m);
void		matrix_set_3(t_matrix *m);
void		matrix_set_2(t_matrix *m);

//matrix multiplication:
void		matrix_multiply_matrix(t_matrix *a, t_matrix *b, t_matrix *result);
t_3d_vector	matrix_multiply_vector(t_matrix *m, t_3d_vector *vector);
t_matrix	matrix_multiply_imatrix(t_matrix *m);

//matrix_utils_2
void		matrix_print(t_matrix *mat);
void		matrix_transpose(t_matrix *m);
void		matrix_det_2(t_matrix *m);
t_matrix	matrix_sub_of4(t_matrix *m, int row, int col);
t_matrix	matrix_sub_of3(t_matrix *m, int row, int col);

#endif
