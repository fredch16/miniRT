/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:05:52 by fcharbon          #+#    #+#             */
/*   Updated: 2024/06/06 19:56:35 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include <stdint.h>
# define WIN_WIDTH 1600 
# define WIN_HEIGHT	900 
# define EPSILON 0.00001
# define PI 3.14159265358979323846
# include "../includes/libft/libft.h"
# include "../includes/mlx_linux/mlx.h"
# include <math.h>
# include <errno.h>
# include <X11/keysym.h>
# include <float.h>
# include "tuples.h"
# include "minirt_types.h"
# include "ray_intersect.h"
# include "matrix.h"


//colour utils
t_colour	colour_add(t_colour c1, t_colour c2);
t_colour	 colour_sub(t_colour c1, t_colour c2);
t_colour	 colour_sca_mul(double multiplier, t_colour c1);
t_colour	 colour_mul(t_colour c1, t_colour c2);

//mlx utils
void	put_pixel_img(t_data *data, int x, int y, int colour);
void	init_mlx(t_data *data);

//drawing utils
void	draw_circle(t_data *data, int	radius);
void	draw_projectile(t_data *data, int startx, int starty, t_tuple velocity);
void	draw_clock(t_data *data);

//matrix utils
// void		matrix_print(t_matrix *mat);

#endif
