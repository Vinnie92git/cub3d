/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:06:14 by becamino          #+#    #+#             */
/*   Updated: 2024/03/13 15:47:17 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*Search for set characters in the first/last one of s1, and keep searching 
	if it finds one.*/

static int	ft_search(char const *s1, char const *set, size_t i)
{
	size_t	slen;

	slen = ft_strlen(s1);
	if (i == 0)
	{
		while (ft_strchr(set, (int)s1[i]) != NULL && i < slen)
			i++;
	}
	else
	{
		while (ft_strchr(set, (int)s1[i]) != NULL && i > 0)
			--i;
	}
	return (i);
}

/*Strtrim searches for set characters in s1 and "deletes" them.
It returns a new string formed by the characters left*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	slen;
	size_t	x;
	size_t	y;

	if (!s1)
		return (0);
	slen = ft_strlen(s1);
	if (slen == 0)
		return (ft_strdup(""));
	x = ft_search(s1, set, 0);
	y = ft_search(s1, set, ft_strlen(s1) -1);
	if (x <= y)
	{
		res = (char *)malloc(y - x + 2);
		if (!res)
			return (NULL);
		ft_strlcpy(res, &s1[x], y - x + 2);
		return (res);
	}
	else
		return (ft_calloc(1, 1));
}

/*int	main(void)
{
	char 	s1[] = "holoh";
	char	set[] = "oh";
	char	*p;

	p = ft_strtrim (s1, set);
	printf("%s \n", p);
	free (p);
	return (0);
}*/
