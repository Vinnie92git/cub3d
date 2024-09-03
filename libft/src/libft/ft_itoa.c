/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:57:48 by becamino          #+#    #+#             */
/*   Updated: 2023/10/16 16:35:21 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Using malloc, create a string that represents the integer recieved as an
//		argument. 
static int	my_counter(long n)
{
	int	cont;

	cont = 0;
	if (n < 0)
	{
		cont++;
		n = -n;
	}
	else if (n == 0)
		cont++;
	while (n > 0)
	{
		n = n / 10;
		cont++;
	}
	return (cont);
}

static int	ft_div(long n)
{
	long	x;

	x = n;
	if (x > 9)
	{
		n = (n % 10) + '0';
		return (n);
	}
	else
		return (n + '0');
}

static char	*ft_wnstr(char *s, size_t cont, long n)
{
	size_t	x;
	char	c;

	x = 0;
	if (n < 0)
	{
		s[x] = '-';
		x++;
	}
	n = -n;
	s[cont - 1] = '\0';
	while (cont > 2)
	{
		c = (ft_div(n));
		n = n / 10;
		s[cont - 2] = c;
		cont--;
	}
	return (s);
}

char	*ft_wpstrs(char *s, size_t cont, long n)
{
	char	c;

	s[cont - 1] = '\0';
	while (cont > 1)
	{
		c = (ft_div(n));
		n = n / 10;
		s[cont - 2] = c;
		cont--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	cont;
	long	num;

	num = n;
	cont = my_counter(num) + 1;
	s = malloc(cont * sizeof(char));
	if (!s)
		return (0);
	else if (num < 0)
		s = ft_wnstr(s, cont, num);
	else
		s = ft_wpstrs(s, cont, n);
	return (s);
}

/*int	main(void)
{
	char	*s;

	s = ft_itoa(-556);
	printf("%s \n", s);
	return (0);
}*/
