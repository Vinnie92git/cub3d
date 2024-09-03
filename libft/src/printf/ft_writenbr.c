/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writenbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:11:07 by becamino          #+#    #+#             */
/*   Updated: 2024/03/13 15:47:57 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static int	my_counter(long n)
{
	int	cont;

	cont = 0;
	if (n < 0)
	{
		cont++;
		n = -n;
	}
	if (n == 0)
		cont = 1;
	while (n > 0)
	{
		n = n / 10;
		cont++;
	}
	return (cont);
}

int	ft_writenbr(int n)
{
	char	s [32];
	size_t	cont;
	size_t	slen;
	long	num;

	num = n;
	if (n < 0)
	{
		s[0] = '-';
		num = -num;
	}
	cont = my_counter(n);
	slen = cont;
	s[cont] = '\0';
	s[cont - 1] = '0';
	while (num > 0)
	{
		cont--;
		s[cont] = num % 10 + '0';
		num = num / 10;
	}
	write(1, s, slen);
	return (slen);
}

/*int	main(void)
{
	printf("\n%i", ft_writenbr(0));
	return (0);
}*/
