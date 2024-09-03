/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:10:59 by vini              #+#    #+#             */
/*   Updated: 2024/08/22 16:27:31 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	copy_map(t_data *data, char **file, int start)
{
	int	i;

	i = 0;
	data->map_height = count_map_height(file, start);
	data->map = ft_calloc(data->map_height + 1, sizeof(char *));
	if (!data->map)
		return ;
	while (i < data->map_height)
	{
		data->map[i] = ft_strdup(data->file_data.file_cpy[start]);
		i++;
		start++;
	}
}

void	copy_info(t_data *data, char *line, int j)
{
	if (line[j + 1] && ft_isalpha(line[j + 1]))
		copy_textures(data, line, j);
	else
		copy_colors(data, line, j);
}

void	fill_copy(t_data *data)
{
	int		i;
	int		row;
	int		col;
	char	*line;

	i = 0;
	row = 0;
	col = 0;
	line = get_next_line(data->file_data.fd);
	while (line != NULL)
	{
		data->file_data.file_cpy[row]
			= ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->file_data.file_cpy[row])
			return ;
		while (line[i] != '\0')
			data->file_data.file_cpy[row][col++] = line[i++];
		data->file_data.file_cpy[row++][col] = '\0';
		col = 0;
		i = 0;
		free(line);
		line = get_next_line(data->file_data.fd);
	}
	data->file_data.file_cpy[row] = NULL;
}

int	count_lines(char *file)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}
