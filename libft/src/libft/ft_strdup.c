/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:27:38 by becamino          #+#    #+#             */
/*   Updated: 2023/10/16 16:36:44 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);*/
/*Reserves enough memory fot s1 and copies it in s2*/

char	*ft_strdup(const char *s1)
{
	size_t	x;
	char	*s2;

	x = ft_strlen(s1) + 1;
	s2 = (char *)malloc(x);
	if (!s2)
		return (0);
	ft_memcpy((void *)s2, (const void *)s1, x);
	return ((char *)s2);
}

/*int	main(void)
{
	char	s [8] = "Soy Bea";
	char	*s2;
	
	s2 = ft_strdup(s);
	printf("%s \n", s2);
	free (s2);
	return (0);
}*/
