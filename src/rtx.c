/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:16:31 by fcharbon          #+#    #+#             */
/*   Updated: 2024/09/10 18:06:21 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"
#include <stdbool.h>

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

int	main(int argc, char **argv)
{
	t_world w;
	t_data	data;

	char		**scene;
	t_parser	parser;

	if (argc > 2 || argc < 2)
	{
		ft_message_error("Error\nYou need to pass file with .rt extension.\n");
	}
	if (argc == 2)
	{
		scene = file_read(argv[1]);
		int i = 0;
		while (scene[i] != NULL)
		{
			ft_putstr_fd(scene[i], 1);
			ft_putchar_fd('\n', 1);
			i++;
		}
		file_check_error(scene);
		set_data(scene, &parser);
		// if (set_data(scene, &parser) == true)
		// 	execute_rt(parser);
		free_text(scene);
		free_objects_memory(&parser);
	}

	//ok here we start to move things from parser to useable info 
	
	//camera related
	t_camera	c = camera_construct(WIN_WIDTH, WIN_HEIGHT, (parser.camera.fov * (PI / 180)));
	t_tuple	from = parser.camera.view_point;
	t_tuple	to = tuple_add(from, parser.camera.orientation_vector);
	t_tuple	up = tuple_vec(0, 1, 0);
	pixel_size(&c);
	c.transform = view_transform(from, to, up);
	matrix_det_4(&c.transform);
	c.trans_inverse = matrix_inverse(&c.transform);
	w.c = c;

	//lighting
	w.point_light.position = parser.light.light_point;
	//remember to include brightness
	w.point_light.intensity = colour_set(1, 1, 1);

	data.w = &w;
	//obj_create
	data_for_obj(&parser, &data);

	init_mlx(&data, c, &w);
	return (1);
}

void	sphere_init(t_sp *sp, t_data *data, t_obj *obj_list)
{
	t_matrix	translate;
	t_matrix	scale;
	t_matrix	endlime;
	t_obj		*obj;

	obj = obj_create(OT_SPHERE);
	obj_add_back(&obj_list, obj);
	obj->material.colour = sp->col;
	//what values do we put for diffuse and specular?
	obj->material.diffuse = 0.7;
	obj->material.specular = 0.3;
	matrix_set_translation(&translate, sp->center.x, sp->center.y, sp->center.z);
	matrix_set_scaling(&scale, sp->diameter / 2, sp->diameter / 2, 1);
	/*scaling: is it 1 for z?*/
	matrix_multiply_matrix(&translate, &scale, &endlime);
	sphere_set_transform(obj, &endlime);
}

void	plane_init(t_pl *pl, t_data *data, t_obj *obj_list)
{
	t_matrix	translate;
	t_matrix	rotate;
	t_matrix	endlime;
	t_obj		*obj;

	obj = obj_create(OT_PLANE);
	obj_add_back(&obj_list, obj);
	obj->material.colour = pl->col;
	//what values do we put for diffuse and specular?
	obj->material.diffuse = 0.7;
	obj->material.specular = 0.3;
	matrix_set_translation(&translate, pl->point.x, pl->point.y, pl->point.z);
	/*  FORMULA FOR ROTATION... 
	matrix_set_rotation_x
	matrix_set_rotation_y
	matrix_set_rotation_z
	*/
	matrix_multiply_matrix(&translate, &rotate, &endlime);
	sphere_set_transform(obj, &endlime);
}

void	cylinder_init(t_cy *cy, t_data *data, t_obj *obj_list)
{
	t_obj		*obj;
	t_matrix	translate;
	t_matrix	rotate;
	t_matrix	scale;
	t_matrix	endlime;

	obj = obj_create(OT_CYLINDER);
	obj_add_back(&obj_list, obj);
	obj->material.colour = cy->col;
	//what values do we put for diffuse and specular?
	obj->material.diffuse = 0.7;
	obj->material.specular = 0.3;
	/* how to calculate min and max? */
	obj->min = cy->center - cy->height / 2;
	obj->max = cy->center + cy->height / 2;
	matrix_set_scaling(&scale, cy->diameter / 2, cy->diameter / 2, 1);
	/*scaling: is it 1 for z?*/
	matrix_set_translation(&translate, cy->center.x, cy->center.y, cy->center.z);
	matrix_multiply_matrix(&scale, &translate, &endlime);
	/*  FORMULA FOR ROTATION... 
	matrix_set_rotation_x
	matrix_set_rotation_y
	matrix_set_rotation_z
	*/
	sphere_set_transform(obj, &endlime);
}

void	data_for_obj(t_parser *parser, t_data *data)
{
	t_obj	*obj_list;
	t_cy	*cy_ptr;
	t_sp	*sp_ptr;
	t_pl	*pl_ptr;

	data->w->obj_list = &obj_list;
	obj_list = NULL;
	sp_ptr = parser->sphere;
	while (sp_ptr != NULL)
	{
		sphere_init(sp_ptr, data, obj_list);
		sp_ptr = sp_ptr->next;
	}
	pl_ptr = parser->plane;
	while (pl_ptr != NULL)
	{
		plane_init(pl_ptr, data, obj_list);
		pl_ptr = pl_ptr->next;
	}
	cy_ptr = parser->cylinder;
	while (cy_ptr != NULL)
	{
		cylinder_init(cy_ptr, data, obj_list);
		cy_ptr = cy_ptr->next;
	}
}