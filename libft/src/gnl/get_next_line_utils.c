/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:46:19 by becamino          #+#    #+#             */
/*   Updated: 2023/11/03 11:20:01 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

char	*ft_free(char *s1)
{
	if (s1)
	{
		free (s1);
		s1 = NULL;
	}
	return (NULL);
}

/*size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}*/

int	ft_strchr_gnl(const char *s, char c)
{
	int			slen;
	int			x;

	slen = (int)ft_strlen(s);
	x = 0;
	while (x <= slen)
	{
		if (s[x] == c)
			return (1);
		else
			x++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*s3;
	int		x;
	int		j;

	if (!s1)
		s3 = malloc(sizeof(char) * (ft_strlen(s2) + 1));
	else
		s3 = malloc(sizeof(char) * (ft_strlen(s2) + ft_strlen(s1) + 1));
	if (!s3)
		return (ft_free(s3));
	x = 0;
	while (s1 && s1[x] != '\0')
	{
		s3[x] = s1[x];
		x++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		s3[x + j] = s2[j];
		j++;
	}
	s3[x + j] = '\0';
	ft_free(s1);
	return (s3);
}
