/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:44:23 by becamino          #+#    #+#             */
/*   Updated: 2023/11/13 16:24:00 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

char	*ft_save2(char *stash, size_t i, size_t len)
{
	char	*aux;
	int		x;

	aux = malloc(sizeof(char) *(len - i + 1));
	if (!aux)
		return (NULL);
	x = 0;
	while (i < len)
	{
		aux[x] = stash[i];
		x++;
		i++;
	}
	aux[x] = '\0';
	free (stash);
	return (aux);
}

char	*ft_save(char *stash)
{
	char	*aux;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(stash);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	aux = ft_save2(stash, i, len);
	return (aux);
}

char	*ft_cut(char *stash)
{
	int		i;
	int		len;
	char	*res;

	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	len++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		res[i] = stash[i];
		i++;
	}
	res[i] = stash[i];
	i++;
	res[i] = '\0';
	return (res);
}

char	*ft_read(int fd, char *stash)
{
	char	readd[BUFFER_SIZE + 1];
	int		x;

	x = 1;
	while (x > 0)
	{
		x = (int)read(fd, readd, BUFFER_SIZE);
		if (x == -1)
			return (ft_free(stash));
		if (x == 0)
			break ;
		readd[x] = '\0';
		stash = ft_strjoin_gnl(stash, readd);
		if (!stash)
			return (ft_free(stash));
		if (ft_strchr_gnl(stash, '\n') == 1)
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		stash = ft_free(stash);
		return (NULL);
	}
	stash = ft_read(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_cut(stash);
	stash = ft_save(stash);
	return (line);
}
