/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:23:53 by becamino          #+#    #+#             */
/*   Updated: 2024/03/13 15:46:52 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*	Search for s2 in s1 for n bytes.*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (x < len && haystack[x] != '\0' && needle[y] != '\0')
	{
		while (x < len && haystack[x] != needle[y]
			&& haystack[x] != '\0')
			x++;
		while (x < len && haystack[x] == needle[y]
			&& needle[y] != '\0')
		{
			x++;
			y++;
		}
	}
	if (haystack[x - y] == needle[0] && needle[y] == '\0')
		return ((char *)&haystack[x - y]);
	else
		return (NULL);
}

/*int main(void)
{
    char    h [] = "lorem ipsum dolor sit amet";
	char	*s;
    size_t  len;

    len = 30; 
    s =  ft_strnstr(h, "ipsum", len);
	printf("%s \n", s);
    return (0);
}*/