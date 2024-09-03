/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:23:26 by becamino          #+#    #+#             */
/*   Updated: 2024/03/13 15:45:26 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/*size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);*/

/*Copia len bytes from string src to dst*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;

	dest = (char *)dst;
	source = (char *)src;
	if (dest == (void *)0 && source == (void *)0)
		return (NULL);
	if (dst < src)
	{
		ft_memcpy (dst, src, len);
		return (dst);
	}
	else
	{
		while (len > 0)
		{
			dest[len - 1] = source[len -1];
			len--;
		}
		return (dst);
	}
}

/*x = ft_strlen(src);*/
/*int	main(void)
{
	char	dst[30] = "Hola Juan que tal";
	size_t	len;

	len = 15;
	printf("%s \n",(char*)(ft_memmove (dst + 3, dst, len)));
	return (0);
}*/
