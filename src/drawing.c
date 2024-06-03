/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:31:48 by fcharbon          #+#    #+#             */
/*   Updated: 2024/05/22 14:29:47 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"

void	draw_circle(t_data *data, int radius)
{
	int	x0 = WIN_WIDTH / 2;
	int y0 = WIN_HEIGHT / 2;

	int x = radius;
	int	y = 0;
//	int	decisionOver2 = 1 - x;
	int	colour = 0xFFFFFF;

put_pixel_img(data,  x + x0,  y + y0, colour);
	// while (y <= x)
	// {
	// 	// Each point in each octant of the circle
	// 	put_pixel_img(data,  x + x0,  y + y0, colour);
	// 	put_pixel_img(data,  y + x0,  x + y0, colour);
	// 	put_pixel_img(data, -x + x0,  y + y0, colour);
	// 	put_pixel_img(data, -y + x0,  x + y0, colour);
	// 	put_pixel_img(data, -x + x0, -y + y0, colour);
	// 	put_pixel_img(data, -y + x0, -x + y0, colour);
	// 	put_pixel_img(data,  x + x0, -y + y0, colour);
	// 	put_pixel_img(data,  y + x0, -x + y0, colour);

	// 	y++;
	// 	if (decisionOver2 <= 0) {
	// 		decisionOver2 += 2 * y + 1;  // Change in decision criterion for y -> y+1
	// 	} else {
	// 		x--;
	// 		decisionOver2 += 2 * (y - x) + 1;  // Change for y -> y+1, x -> x-1
	// 	}
	// }
}

void	draw_projectile(t_data *data, int startx, int starty, t_3d_vector velocity)
{
	// t_3d_vector start;
	// t_3d_vector gravity;

	// start.x = startx;
	// start.y = starty;

	t_3d_vector currentpoint;
	currentpoint.x = startx;
	currentpoint.y = starty;

	t_3d_vector gravity;
	gravity.x = 0;
	gravity.y = 0.05;
	gravity.z = 0;

	t_3d_vector wind;
	wind.x = -0.04;
	wind.y = 0;
	wind.z = 0;

	while (currentpoint.x <= WIN_WIDTH && currentpoint.y <= WIN_HEIGHT)
	{
		put_pixel_img(data, currentpoint.x, currentpoint.y, 0xFF0000);
		velocity = vector_add(velocity, gravity);
		velocity = vector_add(velocity, wind);
		currentpoint = vector_add(currentpoint, velocity);
	}
}

void	draw_clock(t_data *data)
{
	t_matrix matA;
	t_matrix matB;
	//t_matrix matC;
	// t_matrix matD;
	// t_matrix matE;
	t_3d_vector	tuple;
	t_3d_vector	point;
	int	colour = 0xFF00FF;
	int	radius;

	radius = 200;
	tuple.x = 0;
	tuple.y = 0;
	tuple.z = 0;
	tuple.w = 1;

	put_pixel_img(data,  tuple.x, tuple.y, colour);
	vector_print(tuple);
	matrix_set_translation(&matA, 0, -radius, 0);
	matrix_print(&matA);
	point = matrix_multiply_vector(&matA, &tuple);
	vector_print(point);
	put_pixel_img(data, point.x, point.y, colour);
	matrix_set_rotation_z(&matB, PI / 6);
	matrix_print(&matB);
	int y = 0;
	while (y < 11)
	{
		point = matrix_multiply_vector(&matB, &point);
		vector_print(point);
		put_pixel_img(data,  point.x, point.y, colour);
		y++;
	}
}