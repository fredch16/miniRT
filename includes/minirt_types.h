/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:51:38 by fcharbon          #+#    #+#             */
/*   Updated: 2024/06/03 18:47:26 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TYPES_H
# define MINIRT_TYPES_H

#include <stdint.h>

typedef struct s_tuple
{
	double		x;
	double		y;
	double		z;
	int			w;
}	t_tuple;

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple direction;
}	t_ray;

typedef struct s_matrix
{
	double	matrix[4][4];
	double	determinant;
	int		columns;
	int		rows;
}	t_matrix;

typedef struct s_rgb
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
}	t_rgb;

typedef struct s_colour
{
	double	red;
	double	green;
	double	blue;
}	t_colour;

typedef struct s_quadratic
{
	double	a;
	double	b;
	double	c;
	double	t1;
	double	t2;
	double	discriminant;
}	t_quadratic;

enum e_obj_type
{
	OT_SPHERE,
	OT_PLANE,
	OT_CYLINDER
};

typedef struct s_obj
{
	enum			e_obj_type type;
	t_matrix		transform;
	struct s_obj	*next;
}	t_obj;

typedef struct s_xs
{
	int		id;
	int		count;
	double	t_vals[2];
	t_obj	*xs_obj;
	struct s_xs	*next;
}	t_xs;

typedef struct s_data
{
	void	*mlx;
	void	*img;
	void	*addr;
	void	*win;
	t_tuple	origin;
	int		bpp;
	int		endian;
	int		line_len;
	t_tuple velocity;
}	t_data;

#endif
