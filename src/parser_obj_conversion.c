/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_obj_conversion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:35:50 by fcharbon          #+#    #+#             */
/*   Updated: 2024/11/13 20:52:02 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

void	free_objects_memory(t_parser *parser)
{
	t_sp	*sp_tmp;
	t_pl	*pl_tmp;
	t_cy	*cy_tmp;

	while (parser->sphere_nbr > 0)
	{
		sp_tmp = parser->sphere;
		parser->sphere = parser->sphere->next;
		free (sp_tmp);
		parser->sphere_nbr--;
	}
	while (parser->plane_nbr > 0)
	{
		pl_tmp = parser->plane;
		parser->plane = parser->plane->next;
		free (pl_tmp);
		parser->plane_nbr--;
	}
	while (parser->cylinder_nbr > 0)
	{
		cy_tmp = parser->cylinder;
		parser->cylinder = parser->cylinder->next;
		free (cy_tmp);
		parser->cylinder_nbr--;
	}
}

void	add_obj_sp(t_sp *sp, t_data *data)
{
	t_matrix	translate;
	t_matrix	scale;
	t_matrix	endlime;
	t_obj		*obj;

	obj = obj_create(OT_SPHERE);
	obj_add_back(data->w->obj_list, obj);
	obj->material.colour = sp->col;
	obj->material.diffuse = 0.7;
	obj->material.specular = 0.3;
	matrix_set_translation(&translate, sp->center.x, \
		sp->center.y, sp->center.z);
	matrix_set_scaling(&scale, sp->diameter / 2, \
		sp->diameter / 2, sp->diameter / 2);
	matrix_multiply_matrix(&translate, &scale, &endlime);
	sphere_set_transform(obj, &endlime);
}

void	add_obj_pl(t_pl *pl, t_data *data)
{
	t_matrix	translate;
	t_matrix	rotate;
	t_matrix	endlime;
	t_obj		*obj;

	obj = obj_create(OT_PLANE);
	obj_add_back(data->w->obj_list, obj);
	obj->material.colour = pl->col;
	obj->material.diffuse = 0.7;
	obj->material.specular = 0;
	matrix_set_translation(&translate, pl->point.x, pl->point.y, pl->point.z);
	rotate = get_rotator(tuple_vec(0, 1, 0), pl->norm_axis_vec);
	matrix_multiply_matrix(&translate, &rotate, &endlime);
	sphere_set_transform(obj, &endlime);
}

void	add_obj_cy(t_cy *cy, t_data *data)
{
	t_obj		*obj;
	t_matrix	translate;
	t_matrix	rotate;
	t_matrix	scale;
	t_matrix	endlime;

	obj = obj_create(OT_CYLINDER);
	obj_add_back(data->w->obj_list, obj);
	obj->material.colour = cy->col;
	obj->material.diffuse = 0.7;
	obj->material.specular = 0.3;
	obj->min = 0;
	obj->max = cy->height;
	if (cy->cap == 0)
		obj->capped = false;
	matrix_set_scaling(&scale, cy->diameter / 2, \
		cy->diameter / 2, cy->diameter / 2);
	matrix_set_translation(&translate, cy->center.x, \
		cy->center.y, cy->center.z);
	rotate = get_rotator(tuple_vec(0, 1, 0), cy->norm_axis_vec);
	endlime = get_final_trans(&translate, &scale, &rotate);
	sphere_set_transform(obj, &endlime);
}

void	data_for_obj(t_parser *parser, t_data *data)
{
	t_sp	*sp_ptr;
	t_pl	*pl_ptr;
	t_cy	*cy_ptr;

	sp_ptr = parser->sphere;
	while (sp_ptr != NULL)
	{
		add_obj_sp(sp_ptr, data);
		sp_ptr = sp_ptr->next;
	}
	pl_ptr = parser->plane;
	while (pl_ptr != NULL)
	{
		add_obj_pl(pl_ptr, data);
		pl_ptr = pl_ptr->next;
	}
	cy_ptr = parser->cylinder;
	while (cy_ptr != NULL)
	{
		add_obj_cy(cy_ptr, data);
		cy_ptr = cy_ptr->next;
	}
}
