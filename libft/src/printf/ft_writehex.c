/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writehex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:36:25 by becamino          #+#    #+#             */
/*   Updated: 2023/11/03 17:53:58 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_len(unsigned int num)
{
	unsigned int	z;
	size_t			cont;

	z = 1;
	cont = 0;
	while (z > 0)
	{
		z = num / 16;
		num = num / 16;
		cont++;
	}
	return (cont);
}

void	ft_writer(unsigned int num, int cont, char *s, char isMayus)
{
	unsigned int	rest;
	char			tochar;

	if (isMayus > 0)
		tochar = 'A';
	else
		tochar = 'a';
	while (num > 0)
	{
		rest = num % 16;
		if (rest > 9)
			s[cont - 1] = rest - 10 + tochar;
		else
			s[cont - 1] = rest + '0';
		num = num / 16;
		cont--;
	}
}

int	ft_writehex(unsigned int num, char isMayus)
{
	char	s [32];
	int		cont;

	cont = ft_len(num);
	if (num == 0)
		s[0] = '0';
	ft_writer(num, cont, s, isMayus);
	write (1, s, cont);
	return (cont);
}

/*int	main (void)
{
	int	x;
	void *p;
	
	x = 666;
	p = &x;
	printf("\n%i", ft_writep(p));
	return (0);
}*/

/*int	main(void)
{
	printf("\n%i", ft_writehexma(0));
	return (0);
}*/
