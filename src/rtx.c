/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:16:31 by fcharbon          #+#    #+#             */
/*   Updated: 2024/07/24 18:44:01 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

int	main(int argc, char **argv)
{
	char	**scene;

	if (argc > 2 || argc < 2)
		ft_message_error("Error\nYou need to pas one argument, which is a file with .rt extension.\n");
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
	}
}

	// t_obj	*obj;
	// t_obj	*obj2;
	// t_obj	*obj3;
	// t_obj	*obj_list;
	// // t_xsn	*xs_list;
	// t_tuple		p;
	// t_tuple		d;
	// t_ray		ray;
	// // t_comps		comps;
	// t_world		w;
	// t_matrix	translate_sp;
	// t_matrix	scale_sp;

	// obj_list = NULL;

	// matrix_set_translation(&translate_sp, 0, 0, 0);
	// // matrix_set_4(&translate_sp);
	// matrix_set_scaling(&scale_sp, 0.5, 0.5, 0.5);
	// // matrix_set_4(&scale_sp);

	// p = tuple_poi(0, 0, -5);
	// d = tuple_vec(0, 0, 1);
	// // p = tuple_poi(10, 10, -5);
	// // d = tuple_vec(1, 1, 0);
	// ray_create(&ray, p, d);
	
	// //earth
	// w.obj_list = &obj;
	// obj = obj_create(OT_SPHERE);
	// obj_add_back(&obj_list, obj);
	// obj->material.colour = colour_set(0.1764, 0.005, 0.6);
	// obj->material.ambient = 0.6;
	// obj->material.shininess = 50;
	// obj->material.specular = 0.6;
	// matrix_set_translation(&translate_sp, 0, 0, 11);
	// matrix_set_scaling(&scale_sp, 3, 3, 3);
	// t_matrix final;
	// matrix_multiply_matrix(&translate_sp, &scale_sp, &final);
	// matrix_print(&final);
	// printf("\n\n");
	// sphere_set_transform(obj, &final, &scale_sp);

	// //moon
	// obj2 = obj_create(OT_SPHERE);
	// obj_add_back(&obj_list, obj2);
	// obj2->material.colour = colour_set(0.4078, 0.3921, 0.4588);
	// obj2->material.ambient = 0.5;
	// obj2->material.shininess = 50;
	// obj2->material.specular = 0;
	// matrix_set_translation(&translate_sp, 4, 1, 9);
	// matrix_set_scaling(&scale_sp, 1, 1, 1);
	// sphere_set_transform(obj2, &translate_sp, &scale_sp);

	// //meteor
	// obj3 = obj_create(OT_SPHERE);
	// obj_add_back(&obj_list, obj3);
	// obj3->material.colour = colour_set(1, 0.32, 0.005);
	// obj3->material.ambient = 1;
	// obj3->material.shininess = 200;
	// obj3->material.specular = 0.2;
	// t_matrix rotate_sp;
	// matrix_set_scaling(&scale_sp, 10, 0.01, 10);
	// // matrix_set_translation(&translate_sp, -3, 3, 9);
	// // matrix_set_rotation_z(&rotate_sp, -PI / 4);
	// matrix_print(&rotate_sp);
	// // t_matrix temp_transform;
	// // matrix_multiply_matrix(&rotate_sp, &scale_sp, &temp_transform);
	// // t_matrix final_transform;
	// // matrix_multiply_matrix(&translate_sp, &temp_transform, &final_transform);
	// sphere_set_transform(obj3, &scale_sp, &translate_sp);

	// w.point_light.position = tuple_poi(-10, 10, -10);
	// w.point_light.intensity = colour_set(1, 1, 1);
	// t_colour col = colour_at(&w, ray);

	// //test test

	// // t_matrix	rotate;
	// // t_matrix	translate;
	// // matrix_set_rotation_y(&rotate, PI / 4);
	// // matrix_set_translation(&translate, 0, -2, 5);
	// // matrix_multiply_matrix(&rotate, &translate, &c.transform);
	// // t_ray	ray_pix = ray_for_pixel(c, 100, 50);
	// // ray_print(&ray_pix);
	// /// (root2)/2 = 0.70711...
	// //printf("c.pixel_size = %.3f\n\n", c.pixel_size);


	// t_camera	c = camera_construct(800, 800, PI / 4);
	// pixel_size(&c);
	// t_tuple	from = tuple_poi(0, 0, -5);
	// t_tuple	to = tuple_poi(0, 0, 0);
	// t_tuple	up = tuple_vec(0, 1, 0);
	// c.transform = view_transform(from, to, up);
	// matrix_det_4(&c.transform);
	// c.trans_inverse = matrix_inverse(&c.transform);
	// // matrix_print(&view);
	// printf("R: %.5f, G: %.5f, B: %.5f\n", col.r, col.g, col.b);

	// init_mlx(&data, c, &w);
	//}
