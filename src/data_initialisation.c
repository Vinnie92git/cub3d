/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialisation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:24:23 by vini              #+#    #+#             */
/*   Updated: 2024/08/22 16:24:03 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_img(t_data *data)
{
	int	i;

	i = 0;
	data->img[0].mlx_img = mlx_xpm_file_to_image(data->mlx, data->tex.n,
			&data->img[0].w, &data->img[0].h);
	data->img[1].mlx_img = mlx_xpm_file_to_image(data->mlx, data->tex.s,
			&data->img[1].w, &data->img[1].h);
	data->img[2].mlx_img = mlx_xpm_file_to_image(data->mlx, data->tex.e,
			&data->img[2].w, &data->img[2].h);
	data->img[3].mlx_img = mlx_xpm_file_to_image(data->mlx, data->tex.w,
			&data->img[3].w, &data->img[3].h);
	data->img[4].mlx_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	while (i < 5)
	{
		data->img[i].ptr = mlx_get_data_addr(data->img[i].mlx_img,
				&data->img[i].bpp, &data->img[i].stride, &data->img[i].endian);
		i++;
	}
}

void	init_cameraplane(t_data *data)
{
	if (data->pc.point == 'N')
	{
		data->pc.plane.x = 0.66;
		data->pc.plane.y = 0;
	}
	if (data->pc.point == 'S')
	{
		data->pc.plane.x = -0.66;
		data->pc.plane.y = 0;
	}
	if (data->pc.point == 'W')
	{
		data->pc.plane.x = 0;
		data->pc.plane.y = 0.66;
	}
	if (data->pc.point == 'E')
	{
		data->pc.plane.x = 0;
		data->pc.plane.y = -0.66;
	}
}

static void	init_vectors(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'N')
	{
		data->pc.pos = (t_vector){j, i};
		data->pc.dir = (t_vector){0, -1};
		data->pc.point = 'N';
	}
	else if (data->map[i][j] == 'S')
	{
		data->pc.pos = (t_vector){j, i};
		data->pc.dir = (t_vector){0, 1};
		data->pc.point = 'S';
	}
	else if (data->map[i][j] == 'E')
	{
		data->pc.pos = (t_vector){j, i};
		data->pc.dir = (t_vector){1, 0};
		data->pc.point = 'E';
	}
	else if (data->map[i][j] == 'W')
	{
		data->pc.pos = (t_vector){j, i};
		data->pc.dir = (t_vector){-1, 0};
		data->pc.point = 'W';
	}
}

void	init_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->pc.fov = 0;
	data->pc.dir.x = 0;
	data->pc.dir.y = 0;
	data->pc.pos.x = 0;
	data->pc.pos.y = 0;
	while (data->map[i] != NULL)
	{
		while (data->map[i][j] != '\0')
		{
			init_vectors(data, i, j);
			j++;
		}
		i++;
		j = 0;
	}
}

void	init_data(t_data *data)
{
	int	i;

	i = 0;
	data->map_height = 0;
	data->file_data.lines = 0;
	data->map = NULL;
	data->dmap = NULL;
	data->tex.n = NULL;
	data->tex.s = NULL;
	data->tex.e = NULL;
	data->tex.w = NULL;
	data->tex.f = NULL;
	data->tex.c = NULL;
	while (i < 5)
	{
		data->img[i].mlx_img = NULL;
		data->img[i].ptr = NULL;
		i++;
	}
}
