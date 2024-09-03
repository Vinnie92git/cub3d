/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:08:15 by becamino          #+#    #+#             */
/*   Updated: 2023/10/16 16:37:17 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Applies function f to every char of string s. It generates a new string
	with the successive result of f
	Par: - s1
		 - the f function to apply */

/*char	mi_toupper(unsigned int x, char c)
{	
	(void)x;
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	x;
	char	*res;

	res = ft_strdup(s);
	if (!res)
		return (NULL);
	x = 0;
	while (s[x])
	{
		res[x] = (*f)(x, res[x]);
		x++;
	}
	return (res);
}

/*int	main(void)
{
	char const	s [] = "hace mal dia";
	char		*p;
	char		(*f)(unsigned int, char);

	f = &mi_toupper;
	p = ft_strmapi(s, f);
	printf("%s \n", p);
	free (p);
	return (0);
}*/
