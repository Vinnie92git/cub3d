/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:03:01 by becamino          #+#    #+#             */
/*   Updated: 2023/10/16 16:37:37 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

//Reserves enough space and return a substring. Is necessary to force len.

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*subs;
	size_t		slen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (len > slen)
		len = slen;
	if (start + len > slen)
		len = slen - start;
	if (start >= slen)
	{
		subs = (char *)malloc(1);
		if (!subs)
			return (0);
		*subs = 0;
		return (subs);
	}
	subs = (char *)malloc(len + 1);
	if (!subs)
		return (0);
	ft_strlcpy(subs, &s[start], len + 1);
	return (subs);
}

/*int main(void)
{
    char const		s [15] = "Soy Bea Camino";
	char			*p;
	unsigned int	start;
	size_t			len;

	start = 2;
	len = 5;
	p = ft_substr(s, start, len);
	printf("%s \n", p);
	free (p);
    return (0);
}
	x = 0;
	y = start;
	while (x < len)
	{
		subs[x] = s[y];
		x++;
		y++;
	}
	subs[x] = '\0';*/
