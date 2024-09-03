/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:31:46 by becamino          #+#    #+#             */
/*   Updated: 2023/10/16 16:36:09 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Compares byte string s1 against byte string s2. Returns 0 if its identical,
// 		otherwise the difference between them.
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (str1[i] == str2[i] && i < n - 1)
	{
		i++;
	}
	return (str1[i] - str2[i]);
}

/*int	main(void)
{
	char	st1 [0];
	char	st2 [0];
	size_t	l;

	l = 0;
	printf("%d \n", ft_memcmp(st1, st2, l));
	return (0);
}*/
