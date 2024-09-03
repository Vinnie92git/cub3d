/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:33:57 by becamino          #+#    #+#             */
/*   Updated: 2023/10/16 16:36:50 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// locates the first occurrence of c (converted to char) in the string s.

/*size_t	ft_strlen(const char *s);*/

char	*ft_strchr(const char *s, int c)
{
	const int	slen = ft_strlen(s);
	int			x;

	x = 0;
	while (x <= slen && (x >= 0 && x <= 255))
	{
		if (s[x] == (char)c)
			return ((char *)&s[x]);
		else
			x++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	s [] = "Pepita tiene frio";
	int	c = 110;
    printf("%s \n", ft_strchr(s, c));
	ft_strchr (s, c);
	return (0);
} */
