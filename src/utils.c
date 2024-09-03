/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:10:50 by vini              #+#    #+#             */
/*   Updated: 2024/08/22 16:29:42 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_info(t_data *data)
{
	ft_printf("\n");
	if (data->tex.n)
		ft_printf("north texture is: %s\n", data->tex.n);
	if (data->tex.s)
		ft_printf("south texture is: %s\n", data->tex.s);
	if (data->tex.e)
		ft_printf("east texture is: %s\n", data->tex.e);
	if (data->tex.w)
		ft_printf("west texture is: %s\n", data->tex.w);
	if (data->tex.f)
	{
		ft_printf("\nfloor rgb value is: \n");
		print_array(data->tex.f);
	}
	if (data->tex.c)
	{
		ft_printf("ceiling rgb value is: \n");
		print_array(data->tex.c);
	}
}

void	print_array(char **array)
{
	int	i;

	i = 0;
	ft_printf("\n");
	while (array[i] != NULL)
	{
		ft_printf("%s\n", array[i]);
		i++;
	}
	ft_printf("\n");
}

void	free_info(t_data *data)
{
	if (data->tex.n)
		free(data->tex.n);
	if (data->tex.s)
		free(data->tex.s);
	if (data->tex.e)
		free(data->tex.e);
	if (data->tex.w)
		free(data->tex.w);
	if (data->tex.f)
		free_array(data->tex.f);
	if (data->tex.c)
		free_array(data->tex.c);
}

void	free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	if (array)
	{
		free(array);
		array = NULL;
	}
}

char	*ft_strdup_no_nl(char *str)
{
	int		i;
	char	*duplicate;

	i = 0;
	duplicate = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!duplicate)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break ;
		duplicate[i] = str[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}
