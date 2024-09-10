/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:05:52 by fcharbon          #+#    #+#             */
/*   Updated: 2024/09/10 17:58:32 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdint.h>
# include <stdbool.h>
# define WIN_WIDTH 1800
# define WIN_HEIGHT	800
# define EPSILON 0.00001
# define PI 3.14159265358979323846
# include "../includes/libft/libft.h"
# include "../includes/mlx_linux/mlx.h"
# include <math.h>
# include <errno.h>
# include <X11/keysym.h>
# include <float.h>
# include <stdbool.h>
# include "tuples.h"
# include "minirt_types.h"
# include "ray_intersect.h"
# include "matrix.h"
# include "lighting.h"
# include "parser.h"


//colour utils
t_colour	colour_add(t_colour c1, t_colour c2);
t_colour	 colour_sub(t_colour c1, t_colour c2);
t_colour	 colour_sca_mul(double multiplier, t_colour c1);
t_colour	 colour_mul(t_colour c1, t_colour c2);
t_colour	colour_set(double r, double g, double b);

//mlx utils
void	put_pixel_img(t_data *data, int x, int y, int colour);
void	init_mlx(t_data *data, t_camera c, t_world *w);
void	new_img(int w, int h, t_data *data);
int		close_and_destroy(t_data *data);
int 	keyboard_inputs(int keysym, t_data *data);

//drawing utils
void	draw_circle(t_data *data, t_world *w);
void	draw_projectile(t_data *data, int startx, int starty, t_tuple velocity);
void	draw_clock(t_data *data);

//matrix utils
// void		matrix_print(t_matrix *mat);

//camera utils
t_camera	camera_construct(double h, double v, double view);
void		pixel_size(t_camera *c);
t_ray		ray_for_pixel(t_camera c, double px, double py);
void		render(t_camera c, t_world *w, t_data *data);

//main
void	data_for_obj(t_parser *parser, t_data *data);
void	sphere_init(t_sp *sp, t_data *data, t_obj *obj_list);
void	plane_init(t_pl *pl, t_data *data, t_obj *obj_list);
void	cylinder_init(t_cy *cy, t_data *data, t_obj *obj_list);

#endif
