/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:51:38 by fcharbon          #+#    #+#             */
/*   Updated: 2024/06/03 15:06:14 by fcharbon         ###   ########.fr       */
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

typedef struct s_xs
{
	int		count;
	double	*t_vals;
}	t_xs;

typedef struct s_quadratic
{
	double	a;
	double	b;
	double	c;
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
	struct s_obj	*next;
}	t_obj;

#endif
