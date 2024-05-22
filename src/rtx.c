/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:16:31 by fcharbon          #+#    #+#             */
/*   Updated: 2024/05/22 23:55:42 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

int	main(void)
	{
	t_data	data;
	t_ray	ray1;
	t_3d_vector	dir;
	t_3d_vector	ori;
	t_3d_vector pos;

	data.origin.x = 0;
	data.origin.y = 0;
	data.origin.z = 0;

	ori.x = 2;
	ori.y = 3;
	ori.z = 4;

	dir.x = 1;
	dir.y = 0;
	dir.z = 0;

	ray1.origin = ori;
	ray1.direction = dir;
	pos = ray_position(&ray1, 0);
	printf("After 0 sec pos is:\n");
	vector_print(pos);
	pos = ray_position(&ray1, 1);
	printf("After 1 sec pos is:\n");
	vector_print(pos);
	pos = ray_position(&ray1, -1);
	printf("After -1 sec pos is:\n");
	vector_print(pos);
	pos = ray_position(&ray1, 2.5);
	printf("After 2.5 sec pos is:\n");
	vector_print(pos);
	
	data.velocity.x = 1;
	data.velocity.y = -1.7;
	data.velocity.z = 0;
	data.velocity.w = 1;

	data.velocity = vector_norm(data.velocity);
	vector_mul(9, &data.velocity);
	
	// vector_print(vector_neg(a));
	// vector_print(vector_neg(b));
	// printf("%.4f\n", vector_abs(a));
	// printf("%.4f\n", (vector_abs(b)));
	init_mlx(&data);
}
