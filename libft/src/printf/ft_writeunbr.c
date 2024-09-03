/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writeunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:40:37 by becamino          #+#    #+#             */
/*   Updated: 2023/11/03 17:54:11 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static int	my_counter(unsigned int n)
{
	int	cont;

	cont = 0;
	if (n == 0)
		cont = 1;
	while (n > 0)
	{
		n = n / 10;
		cont++;
	}
	return (cont);
}

int	ft_writeunbr(int n)
{
	char			c;
	char			s [32];
	size_t			cont;
	size_t			slen;
	unsigned int	num;

	num = n;
	cont = my_counter(num);
	slen = cont;
	s[cont] = '\0';
	s[cont - 1] = '0';
	while (num > 0)
	{
		cont--;
		c = num % 10 + '0';
		num = num / 10;
		s[cont] = c;
	}
	write(1, s, slen);
	return (slen);
}

/*int	main(void)
{
	printf("\n%i", ft_writeunbr(-10));
	return (0);
}*/
