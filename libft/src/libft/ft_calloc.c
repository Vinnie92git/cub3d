/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:01:01 by becamino          #+#    #+#             */
/*   Updated: 2023/10/16 16:34:52 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../include/libft.h"

/*void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);*/

void	*ft_calloc(size_t n, size_t size)
{
	size_t	x;
	void	*p;

	x = n * size;
	p = malloc(x);
	if (!p)
		return (NULL);
	ft_bzero(p, x);
	return (p);
}

/*int main(void)
{
    size_t  n;
    size_t  size;
	void	*p;

	n = 2;
	size = 4;
	p = ft_calloc(n, size);
    printf("%lu \n", sizeof(p));
	free(p);
	return (0);
}*/
