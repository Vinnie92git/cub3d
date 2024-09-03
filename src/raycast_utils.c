/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:31:04 by vini              #+#    #+#             */
/*   Updated: 2024/08/22 16:28:12 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	get_color(t_data *data, int x, int y, int texture)
{
	return (*(int *)(data->img[texture].ptr
		+ (y * data->img[texture].stride + x * (data->img[texture].bpp / 8))));
}

static void	draw_pixel(t_data *data, int x, int texture)
{
	int	color;

	color = get_color(data, data->ray.tex.x, data->ray.tex.y, texture);
	put_pixel(data, x, data->ray.line_start, color);
}

static void	map_texture(t_data *data, int start, int line_height)
{
	if (data->ray.side == 0)
		data->ray.wall_x = data->pc.pos.y + data->ray.perpwalldist
			* data->ray.dir.y;
	else
		data->ray.wall_x = data->pc.pos.x + data->ray.perpwalldist
			* data->ray.dir.x;
	data->ray.wall_x -= floor(data->ray.wall_x);
	data->ray.tex.x = data->ray.wall_x * TEXTURE_WIDTH;
	if (data->ray.side == 0 && data->ray.dir.x > 0)
		data->ray.tex.x = TEXTURE_WIDTH - data->ray.tex.x - 1;
	if (data->ray.side == 1 && data->ray.dir.y < 0)
		data->ray.tex.x = TEXTURE_WIDTH - data->ray.tex.x - 1;
	data->ray.tex_step = 1.0 * TEXTURE_HEIGHT / line_height;
	data->ray.tex_pos = (start - HEIGHT / 2
			+ line_height / 2) * data->ray.tex_step;
}

static void	line_data(t_data *data, int *line_height, int *start, int *end)
{
	*line_height = HEIGHT / data->ray.perpwalldist;
	*start = -*line_height / 2 + HEIGHT / 2;
	if (*start < 0)
		*start = 0;
	*end = *line_height / 2 + HEIGHT / 2;
	if (*end >= HEIGHT)
		*end = HEIGHT - 1;
}

void	draw_vline(t_data *data, int x)
{
	int	line_height;

	line_data(data, &line_height, &data->ray.line_start, &data->ray.line_end);
	map_texture(data, data->ray.line_start, line_height);
	while (data->ray.line_start < data->ray.line_end)
	{
		data->ray.tex.y = (int)data->ray.tex_pos & (TEXTURE_HEIGHT - 1);
		data->ray.tex_pos += data->ray.tex_step;
		if (data->ray.side == 1 && data->ray.dir.y < 0)
			draw_pixel(data, x, 1);
		else if (data->ray.side == 1 && data->ray.dir.y > 0)
			draw_pixel(data, x, 0);
		else if (data->ray.side == 0 && data->ray.dir.x < 0)
			draw_pixel(data, x, 3);
		else if (data->ray.side == 0 && data->ray.dir.x > 0)
			draw_pixel(data, x, 2);
		data->ray.line_start++;
	}
}
