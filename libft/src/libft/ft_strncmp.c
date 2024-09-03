/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:37:20 by becamino          #+#    #+#             */
/*   Updated: 2024/07/09 18:48:58 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*Compare not more than n characters between s1 & s2.
doesn't compare after null. Returns en integer > = or < (s1 vs s2)*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!n)
		return (0);
	i = 0;
	while (str1 && str1[i] == str2[i] && i < n - 1
		&& (str1[i] != '\0' && str2[i] != '\0'))
	{
		i++;
	}
	return (str1[i] - str2[i]);
}

/*int	main(void)
{
	char	s1 [10] = "Hola Juan";
	char	s2 [10] = "Hola Pedro";
	size_t	n;
	
	n = 10;
	printf("%i \n", ft_strncmp (s1, s2, n));
	return (0);
}*/
