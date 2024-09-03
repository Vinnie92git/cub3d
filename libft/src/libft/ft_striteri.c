/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:19:56 by becamino          #+#    #+#             */
/*   Updated: 2023/10/16 16:36:57 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Applies function f to every char of string s. It generates a new string
	with the successive result of f
	Par: - s1
		 - the f function to apply */

/*char	mi_toupper(unsigned int x, char *c)
{	
	(void)x;
	if (*c >= 97 && *c <= 122)
		return (*c - 32);
	else
		return (*c);
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	x;

	x = 0;
	while (s[x])
	{
		(*f)(x, &s[x]);
		x++;
	}
}

/*int	main(void)
{
	char const	s [] = "hace mal dia";
	char		*p;
	char		(*f)(unsigned int, char*);

	f = &mi_toupper;
	p = ft_striteri(s, f);
	printf("%s \n", p);
	free (p);
	return (0);
}*/
