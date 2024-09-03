/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vini <vini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:01:55 by vini              #+#    #+#             */
/*   Updated: 2024/08/21 22:59:18 by vini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > HEIGHT - 1 || x < 0
		|| x > WIDTH - 1)
		return ;
	pixel = (data->img[4].ptr + (y * data->img[4].stride
				+ x * (data->img[4].bpp / 8)));
	*(int *)pixel = color;
}

static void	render_background(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (y < HEIGHT / 2)
				put_pixel(data, x, y, number_to_hex(data->tex.c));
			else
				put_pixel(data, x, y, number_to_hex(data->tex.f));
			y++;
		}
		++x;
	}
}

int	render(t_data *data)
{
	render_background(data);
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img[4].mlx_img, 0, 0);
	return (0);
}
