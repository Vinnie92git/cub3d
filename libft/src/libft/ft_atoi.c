/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:33:15 by becamino          #+#    #+#             */
/*   Updated: 2024/03/13 15:43:55 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/libft.h"

/* Converts the initial portion of the string pointed by str to integer 
	representation.
	We have to handle for blank spaces, signs and numbers*/
int	ft_atoi(const char *str)
{
	int	x;
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	x = 0;
	while ((str[x] == 32 || (str[x] >= 9 && str[x] <= 13)))
	{
		x++;
	}
	if (str[x] == '-')
		sign *= -1;
	if (str[x] == '-' || str[x] == '+')
		x++;
	while (str[x] >= '0' && str[x] <= '9')
	{
		num = num * 10 + (str[x] - '0');
		x++;
	}
	return (num * sign);
}

/*int	main(void)
{
	char 	str [10] = "+123a";

	printf("%d \n", ft_atoi(str));
	printf("%d \n", ft_atoi((void *)0));
	return (0);
}*/
