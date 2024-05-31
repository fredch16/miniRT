/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:51:38 by fcharbon          #+#    #+#             */
/*   Updated: 2024/05/24 15:07:01 by fcharbon         ###   ########.fr       */
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

typedef struct s_rgb
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
}	t_rgb;

typedef struct s_matrix
{
	double	matrix[4][4];
	int	columns;
	int	rows;
	int	determinant;

}	t_matrix;

typedef struct s_colour
{
	double	red;
	double	green;
	double	blue;
}	t_colour;

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
