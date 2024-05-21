/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:05:52 by fcharbon          #+#    #+#             */
/*   Updated: 2024/05/20 20:03:22 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include <stdint.h>
# define WINDOW_WIDTH 1700
# define WINDOW_HEIGHT 900
# define EPSILON 0.00001
# include "../includes/libft/libft.h"
# include "../includes/mlx_linux/mlx.h"
# include <math.h>
# include <errno.h>
# include <X11/keysym.h>

typedef struct s_rgb
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
}	t_rgb;

typedef struct s_3d_vector
{
	double		x;
	double		y;
	double		z;
	int			w;
}	t_3d_vector;

typedef struct s_data
{
}	t_data;


int			equal(double a, double b);
t_3d_vector vector_add(t_3d_vector a, t_3d_vector b);
t_3d_vector vector_sub(t_3d_vector a, t_3d_vector b);
t_3d_vector vector_neg(t_3d_vector a);
t_3d_vector vector_mul(double mutliplier, t_3d_vector a);
double	vector_abs(t_3d_vector v);
void		vector_print(t_3d_vector v);
t_3d_vector vector_norm(t_3d_vector v);
double		vector_dot(t_3d_vector a, t_3d_vector b);

#endif
