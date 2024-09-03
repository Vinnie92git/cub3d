/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcastano <rcastano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:34:07 by vini              #+#    #+#             */
/*   Updated: 2024/09/02 16:54:53 by rcastano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	destroy_images(t_data *data)
{
	int	i;

	i = 0;
	if (data->mlx)
	{
		while (i < 5)
		{
			if (data->img[i].mlx_img)
				mlx_destroy_image(data->mlx, data->img[i].mlx_img);
			i++;
		}
	}
}

int	close_window(t_data *data)
{
	clean_game(data);
	destroy_images(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
}

int	number_to_hex(char **number)
{
	int	hex;
	int	r;
	int	g;
	int	b;

	r = ft_atoi(number[0]);
	g = ft_atoi(number[1]);
	b = ft_atoi(number[2]);
	hex = r;
	hex = (hex << 8) + g;
	hex = (hex << 8) + b;
	return (hex);
}

void	duplicate_map(t_data *data)
{
	int	i;

	i = 0;
	data->dmap = ft_calloc(data->map_height + 1, sizeof(char *));
	if (!data->dmap)
		return ;
	while (i < data->map_height)
	{
		data->dmap[i] = ft_strdup(data->map[i]);
		i++;
	}
}

void	floodfill(char **map_dup, int x, int y)
{
	map_dup[y][x] = 'x';
	if (y > 0 && map_dup[y - 1][x] == '0' && map_dup[y - 1][x] != 'x')
		floodfill(map_dup, x, y - 1);
	if (map_dup[y][x + 1] != '\0'
		&& map_dup[y][x + 1] == '0' && map_dup[y][x + 1] != 'x')
		floodfill(map_dup, x + 1, y);
	if (map_dup[y + 1] != NULL
		&& map_dup[y + 1][x] == '0' && map_dup[y + 1][x] != 'x')
		floodfill(map_dup, x, y + 1);
	if (x > 0 && map_dup[y][x - 1] == '0' && map_dup[y][x - 1] != 'x')
		floodfill(map_dup, x - 1, y);
}
