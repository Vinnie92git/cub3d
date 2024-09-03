/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:47:20 by becamino          #+#    #+#             */
/*   Updated: 2024/06/04 16:27:24 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/*#include<stdio.h>*/

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/*static int is_lower(char c)*/

/*int	main(void)
{
	int	x;
	unsigned char	c;

	x = 90;
	c = x;

	printf("%d \n", ft_isalpha('c'));
	printf("%d \n", ft_isalpha('9'));
	printf("%d \n", ft_isalpha('!'));
	return(0);
}*/
