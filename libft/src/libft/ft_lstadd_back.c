/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:33:54 by becamino          #+#    #+#             */
/*   Updated: 2024/03/13 15:44:49 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

//Adds 'new' node to the end of the list 'lst'.
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (!lst || !new)
		return ;
	else if (!*lst)
		*lst = new;
	else
	{
		aux = *lst;
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		aux->next = new;
	}
}

/*int	main(void)
{
	t_list	*new;
	t_list	*lst;
	t_list	*p;
	void	*x;
	void	*y;
	int		w;
	int		z;

	w = 59;
	z = 60;
	x = &w;
	y = &z;
	
	new = ft_lstnew(x);
	lst = ft_lstnew(y);
	ft_lstadd_back(&lst, new);
	p = ft_lstlast(lst);
	printf("%d\n", *(int *)new->content);
	printf("%d\n", *(int *)lst->content);
	printf("%d\n", *(int *)p->content);
	
	return(0);
}*/