/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:26:22 by becamino          #+#    #+#             */
/*   Updated: 2023/10/16 16:36:31 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*Send s string to a given fd, followed by a line break */
void	ft_putendl_fd(char *s, int fd)
{
	size_t	slen;

	slen = ft_strlen(s);
	write(fd, s, slen);
	write(fd, "\n", 1);
}

/*int	main(void)
{
	char	str[] = "hace buen dia";

	ft_putendl_fd(str, 1);
	return (0);
}*/
