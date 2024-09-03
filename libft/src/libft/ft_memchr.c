/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:26:24 by becamino          #+#    #+#             */
/*   Updated: 2023/10/16 16:36:05 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*Locates the first occurrence of c (converted into an unsigned char) 
	in s string.
Returns a pointer to that byte or NULL if it doesn's exists.*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned char	i;
	size_t			x;

	s2 = (unsigned char *)s;
	i = (unsigned char)c;
	x = 0;
	if (!n)
		return (NULL);
	while (x < n - 1 && s2[x] != i)
	{
		x++;
	}
	if (s2[x] == i)
	{
		return ((void *)&s2[x]);
	}
	else
		return (NULL);
}

// int	main(void)
// {
// 	// char    s [30] = "Lucrecia no tiene pan";
// 	// char    s [30] = "012345";
// 	char s[] = {48, 49, 50 ,51 ,52 ,53, 0};
// 	printf("$%s$\t$%s$", s+2, ft_memchr(s, 50, 3));
// 	// char s[] = {0, 1, 2, 3, 4};
// 	// printf("$%s$\t$%s$", s+2, ft_memchr(s, 2, 3));

// 	// int c = 110; 
// 	// size_t  n = 10;
// 	// printf("%s \n", (char *)ft_memchr(s, c, n));
// 	// printf("$%s$\t$%s$\t$%s$\t$%s$\t\n", s, s+1, s+2, s+3);

// 	// char s[] = {0, 1, 2 ,3 ,4 ,5}
// 	// /* 1 */ check(ft_memchr(s, 0, 0) == NULL); showLeaks();
// 	// /* 2 */ check(ft_memchr(s, 0, 1) == s); showLeaks();
// 	// /* 3 */ check(ft_memchr(s, 2, 3) == s + 2); showLeaks();
// 	// // /* 4 */ check(ft_memchr(s, 6, 6) == NULL); showLeaks();
// 	// /* 5 */ check(ft_memchr(s, 2 + 256, 3) == s + 2); showLeaks();
// }

// 3 1111 1111