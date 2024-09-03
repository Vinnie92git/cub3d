/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:50:45 by becamino          #+#    #+#             */
/*   Updated: 2023/01/29 14:46:00 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

//  Appends string src to the end of dst. If the return value is >= dstsize, 
//	the output has been truncated.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	x;
	size_t	y;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dstsize <= dlen)
		return (slen + dstsize);
	else
	{
		x = dlen;
		y = 0;
		while (src[y] && x < dstsize - 1)
		{
			dst[x] = src[y];
			x++;
			y++;
		}
		dst[x] = '\0';
		return (dlen + slen);
	}
}

/*int	main(void)
{
	char	dst[30] = "B";
	char	src[] = "123";
	size_t	dstsize;
	size_t	x;

	dstsize = 0;
	x = ft_strlcat(dst, src, dstsize);
	printf("%zu \n", x);
	return (0);
}*/