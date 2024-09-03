/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:59:56 by becamino          #+#    #+#             */
/*   Updated: 2023/10/16 16:35:29 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/*Add the node "new" at the beginning
of the list.*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*int	main(void)
{
	t_list	*lst;
	t_list	*plst;
	t_list	new;
	int		w;
	void	*z;

	new.content = (void *)59;
	new.next = NULL;
	w = 60;
	z = &w;
	lst = ft_lstnew(z);
	plst = lst;
	ft_lstadd_front(&lst, &new);
	printf("%d\n", *(int *)lst->content);
	free(plst);
	return(0);
}*/