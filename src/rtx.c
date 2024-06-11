/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:16:31 by fcharbon          #+#    #+#             */
/*   Updated: 2024/06/11 16:32:37 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

int	main(void)
{
//	t_data	data;
	t_obj	*obj;
	t_obj	*obj_list;
	t_tuple		n;
	t_tuple		v;
	t_tuple		ref;

	v = tuple_vec(1, -1, 0);
	n = tuple_vec(0, 1, 0);
	obj_list = NULL;
	obj = obj_create(OT_SPHERE);
	obj_add_back(&obj_list, obj);
	//w.obj_list = &obj;
	//normal = sphere_normal_at(obj, &v);
	ref = reflect(&v, &n);
	tuple_print(ref);
	//init_mlx(&data, &w);
}

