/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:49:13 by fcharbon          #+#    #+#             */
/*   Updated: 2024/07/18 19:14:59 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtx.h"
#include <stdlib.h>

void	new_img(int w, int h, t_data *data)
{
	data->img = mlx_new_image(data->mlx, w, h);
	data->addr = mlx_get_data_addr(data->img, &(data->bpp),
			&(data->line_len), &(data->endian));
}

int	close_and_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_display(data->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	keyboard_inputs(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_and_destroy(data);
	return (0);
}

void	init_mlx(t_data *data, t_camera c, t_world *w)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "GTX");
	new_img(WIN_WIDTH, WIN_HEIGHT, data);
	// draw_circle(data, w);
	render(c, w, data);
	mlx_hook(data->win, 17, 0, close_and_destroy, data);
	mlx_hook(data->win, 2, 1L << 0, keyboard_inputs, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_loop(data->mlx);
}

void	put_pixel_img(t_data *data, int x, int y, int colour)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int *)dst = colour;
	}
}
