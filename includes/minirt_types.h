/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:51:38 by fcharbon          #+#    #+#             */
/*   Updated: 2024/07/24 19:03:07 by fcharbon         ###   ########.fr       */
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

typedef struct s_lighting_atr
{
	t_tuple point;
	t_tuple eyev;
	t_tuple normalv;
}	t_lighting_atr;

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
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_rgb;

typedef struct s_colour
{
	double	r;
	double	g;
	double	b;
}	t_colour;

typedef struct s_quadratic
{
	double	a; double	b;
	double	c;
	double	t1;
	double	t2;
	double	d;
}	t_quadratic;

enum e_obj_type
{
	OT_SPHERE,
	OT_PLANE,
	OT_CYLINDER
};

/*a point light — a light source with no size, existing
at a single point in space*/
typedef struct s_point_light
{
	t_tuple			position;
	t_colour		intensity;
	t_lighting_atr	*latr;
}	t_point_light;

/* material is a property of the sphere
the surface colour + Phong reflection model: ambient, diffuse, specular, and shininess
Each should accept a nonnegative floating point number. 
For ambient, diffuse, and specular, the typical values are between 0 and 1. 
For shininess, values between 10 (very large highlight)
and 200 (very small highlight) seem to work best,
though there is no actual upper bound.*/
typedef struct s_material
{
	t_colour	colour;
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
}	t_material;

typedef struct s_lighting
{
	t_colour	ambient;
	t_colour	diffuse;
	t_colour	specular;
}	t_lighting;

typedef struct s_obj
{
	enum			e_obj_type type;
	t_matrix		transform;
	t_material		material;
	struct s_obj	*next;
}	t_obj;

typedef struct s_xsn
{
	int		id;
	int		count;
	double	x;
	t_obj	*xs_obj;
	struct s_xsn	*next;
}	t_xsn;

typedef struct s_camera
{
	double	hsize;
	double	vsize;
	double	field_of_view;
	t_matrix	transform; //how the world should be oriented relative to the camera.
	t_matrix	trans_inverse;
	double	half_width;
	double	half_height;
	double	pixel_size;
}	t_camera;

typedef struct s_world
{
	t_obj			**obj_list;
	t_point_light	point_light;
	t_camera		c;
}	t_world;

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
	t_world	*w;
}	t_data;

typedef struct s_comps
{
	double	t;
	t_obj	*obj;
	t_tuple	point;
	t_tuple	eyev;
	t_tuple	normalv;
	int		inside;
}	t_comps;


#endif
