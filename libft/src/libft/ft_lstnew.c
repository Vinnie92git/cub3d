/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:59:48 by becamino          #+#    #+#             */
/*   Updated: 2023/10/16 16:35:56 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/*Creates a new node using malloc.
Content will be the parameter content.
Next will be null*/
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*int	main(void)
{
	t_list	*try;
	void	*x;
	int		y;

	y = 59;
	x = &y;
	try = ft_lstnew(x);
	printf("%i", *(int*)try->content); //castear porque es p a void
	return(0);
}*/
