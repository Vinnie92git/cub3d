/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:44:25 by becamino          #+#    #+#             */
/*   Updated: 2024/03/13 15:48:05 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_lenp(unsigned long int num)
{
	unsigned long		z;
	int					cont;

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

void	ft_writerp(unsigned long int num, int cont, char *s)
{
	int		rest;
	char	tochar;

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

int	ft_writep(unsigned long int num)
{
	int		cont;
	int		len;
	char	s [32];

	cont = 2;
	write (1, "0x", 2);
	len = ft_lenp(num);
	cont += len;
	if (num == 0)
		s[0] = '0';
	ft_writerp(num, len, s);
	write (1, s, len);
	return (cont);
}

/*int	main (void)
{
	int	x;
	void *p;
	
	x = 666;
	p = &x;
	printf("\n%i\n", ft_writep(x));
	return (0);
}*/