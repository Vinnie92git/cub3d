/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:41:46 by vini              #+#    #+#             */
/*   Updated: 2024/09/03 18:07:14 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static char	**get_color(char *line, int j)
{
	int		i;
	int		len;
	char	*temp;
	char	*rgb_values;
	char	**rgb_array;

	i = 0;
	len = 0;
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	i = j;
	while (line[i] && (line[i] != ' ' || line[i] != '\t'))
	{
		len++;
		i++;
	}
	temp = ft_substr(line, j, len);
	rgb_values = ft_strdup_no_nl(temp);
	free(temp);
	rgb_array = ft_split(rgb_values, ',');
	free(rgb_values);
	return (rgb_array);
}

static char	*get_texture(char *line, int j)
{
	int		i;
	int		len;
	char	*temp;
	char	*texture;

	i = 0;
	len = 0;
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	i = j;
	while (line[i] && (line[i] != ' ' || line[i] != '\t'))
	{
		len++;
		i++;
	}
	temp = ft_substr(line, j, len);
	texture = ft_strdup_no_nl(temp);
	free(temp);
	return (texture);
}

void	copy_colors(t_data *data, char *line, int j)
{
	if (line[j] == 'F')
	{
		if (data->tex.f)
			game_error(data, "Duplicated floor texture\n");
		data->tex.f = get_color(line, j + 1);
	}
	if (line[j] == 'C')
	{
		if (data->tex.c)
			game_error(data, "Duplicated ceiling texture\n");
		data->tex.c = get_color(line, j + 1);
	}
}

void	copy_textures(t_data *data, char *line, int j)
{
	if (line[j] == 'N' && line[j + 1] == 'O')
	{
		if (data->tex.n)
			game_error(data, "Duplicated north texture\n");
		data->tex.n = get_texture(line, j + 2);
	}
	if (line[j] == 'S' && line[j + 1] == 'O')
	{
		if (data->tex.s)
			game_error(data, "Duplicated south texture\n");
		data->tex.s = get_texture(line, j + 2);
	}
	if (line[j] == 'E' && line[j + 1] == 'A')
	{
		if (data->tex.e)
			game_error(data, "Duplicated east texture\n");
		data->tex.e = get_texture(line, j + 2);
	}
	if (line[j] == 'W' && line[j + 1] == 'E')
	{
		if (data->tex.w)
			game_error(data, "Duplicated west texture\n");
		data->tex.w = get_texture(line, j + 2);
	}
}

int	count_map_height(char **file, int i)
{
	int	start;
	int	j;

	start = i;
	while (file[i])
	{
		j = 0;
		while (file[i][j] == ' ' || file[i][j] == '\t' || file[i][j] == '\r'
		|| file[i][j] == '\v' || file[i][j] == '\f')
			j++;
		if (file[i][j] != '1')
			break ;
		i++;
	}
	return (i - start);
}
