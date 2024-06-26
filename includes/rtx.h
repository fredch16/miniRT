/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:05:52 by fcharbon          #+#    #+#             */
/*   Updated: 2024/06/11 16:30:29 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include <stdint.h>
# define WIN_WIDTH 1000 
# define WIN_HEIGHT	1000 
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
# include "lighting.h"


//colour utils
t_colour	colour_add(t_colour c1, t_colour c2);
t_colour	 colour_sub(t_colour c1, t_colour c2);
t_colour	 colour_sca_mul(double multiplier, t_colour c1);
t_colour	 colour_mul(t_colour c1, t_colour c2);
t_colour	colour_set(double r, double g, double b);

//mlx utils
void	put_pixel_img(t_data *data, int x, int y, int colour);
void	init_mlx(t_data *data, t_world *w);
void	new_img(int w, int h, t_data *data);
int		close_and_destroy(t_data *data);
int 	keyboard_inputs(int keysym, t_data *data);

//drawing utils
void	draw_circle(t_data *data, t_world *w);
void	draw_projectile(t_data *data, int startx, int starty, t_tuple velocity);
void	draw_clock(t_data *data);

//matrix utils
// void		matrix_print(t_matrix *mat);

#endif
