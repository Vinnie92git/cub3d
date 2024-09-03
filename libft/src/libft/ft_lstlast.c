/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:55:28 by becamino          #+#    #+#             */
/*   Updated: 2023/10/16 16:35:47 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

//Returns the last node.
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		last = lst;
		lst = lst->next;
	}
	return (last);
}

/*int	main(void)
{
	t_list	*plst;
	t_list	*lst;
	
	lst = ft_lstlast(plst);
	printf("%d\n", *(int*)lst->content);
	return(0);
}*/