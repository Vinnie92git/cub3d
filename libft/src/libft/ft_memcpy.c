/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:33:11 by becamino          #+#    #+#             */
/*   Updated: 2023/10/16 16:36:14 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*copia n bytes del area de mem src al area dst. 
Si dst y src se superponen, behaviour is undefined.*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		cont;
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (char *)src;
	cont = 0;
	while (cont < n && (d != (void *)0 || s != (void *)0))
	{
		d[cont] = s[cont];
		cont ++;
	}
	return (dst);
}

/*int	main(void)
{
	char		dst [30] = "Hola Pepita";
	const char	src [] = "Jacinta";
	size_t		n;

	n = 5;
	ft_memcpy(dst, src, n);
	return (0);
}*/
