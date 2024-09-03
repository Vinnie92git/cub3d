/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:00:01 by becamino          #+#    #+#             */
/*   Updated: 2023/10/16 16:36:01 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
//Count the number of nodes in a list.

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/*int main(void)
{
    t_list  *plst;
    t_list  lst;
	t_list	*lst2;
	int		x;
	int		c;
	void	*p;
    
	c = 59;
	p = &c;
	lst.content = p;
	lst.next =  NULL;
	plst = &lst;
	lst2 = ft_lstnew(p);
	ft_lstadd_front(&plst, lst2);
    x = ft_lstsize(plst);
    printf("%d\n", x);
	printf("%d\n", *(int*)lst.content);
    return(0);
}*/