/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vini <vini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:24:37 by vini              #+#    #+#             */
/*   Updated: 2024/08/20 16:40:09 by vini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	rotate(t_data *data, double speed)
{
	double	aux_dir;
	double	aux_plane;

	aux_dir = data->pc.dir.x;
	aux_plane = data->pc.plane.x;
	data->pc.dir.x = data->pc.dir.x * cos(speed) - data->pc.dir.y * sin(speed);
	data->pc.dir.y = aux_dir * sin(speed) + data->pc.dir.y * cos(speed);
	data->pc.plane.x = data->pc.plane.x * cos(speed)
		- data->pc.plane.y * sin(speed);
	data->pc.plane.y = aux_plane * sin(speed)
		+ data->pc.plane.y * cos(speed);
}

static void	move(t_data *data, double x, double y, char sign)
{
	if (sign == '+')
	{
		if (data->dmap[(int)data->pc.pos.y][(int)(data->pc.pos.x + x)] != '1')
			data->pc.pos.x += x;
		if (data->dmap[(int)(data->pc.pos.y + y)][(int)data->pc.pos.x] != '1')
			data->pc.pos.y += y;
	}
	else if (sign == '-')
	{
		if (data->dmap[(int)data->pc.pos.y][(int)(data->pc.pos.x - x)] != '1')
			data->pc.pos.x -= x;
		if (data->dmap[(int)(data->pc.pos.y - y)][(int)data->pc.pos.x] != '1')
			data->pc.pos.y -= y;
	}
}

int	key_event(int key, t_data *data)
{
	if (key == KEY_ESC)
		close_window(data);
	else if (key == KEY_W)
		move(data, data->pc.dir.x * SPEED, data->pc.dir.y * SPEED, '+');
	else if (key == KEY_S)
		move(data, data->pc.dir.x * SPEED, data->pc.dir.y * SPEED, '-');
	else if (key == KEY_A)
		move(data, data->pc.plane.x * SPEED, data->pc.plane.y * SPEED, '-');
	else if (key == KEY_D)
		move(data, data->pc.plane.x * SPEED, data->pc.plane.y * SPEED, '+');
	else if ((key == KEY_L && (data->pc.point == 'N' || data->pc.point == 'S'))
		|| (key == KEY_R && (data->pc.point == 'E' || data->pc.point == 'W')))
		rotate(data, -ROTATION);
	else if ((key == KEY_L && (data->pc.point == 'E' || data->pc.point == 'W'))
		|| (key == KEY_R && (data->pc.point == 'N' || data->pc.point == 'S')))
		rotate(data, ROTATION);
	return (0);
}
