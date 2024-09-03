/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:55:24 by becamino          #+#    #+#             */
/*   Updated: 2023/10/16 16:35:52 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

//Iters 'lst' list and applies 'f' function to the content of every node.
//Creates a list with the result of every 'f' application.
//Function 'del' is used to delete the content of a node, if its necesary.

/*void function(void *p)
{
    int x;
    
    x = 1;
    *(int *)p = *(int *)p + x;
}

void    ft_del(void *p)
{
    p = (void *)0;
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dupe;
	t_list	*aux;

	if (!lst || !(*f) || !del)
		return (NULL);
	dupe = NULL;
	while (lst != NULL)
	{
		aux = ft_lstnew((*f)(lst->content));
		if (!aux)
		{
			ft_lstclear(&dupe, del);
			return (NULL);
		}
		ft_lstadd_back(&dupe, aux);
		lst = lst->next;
	}
	return (dupe);
}
/*int main (void)
{
    t_list  *lst;
	t_list	*sec;
    void    (*f)(void *);
    void    (*del)(void *);
	void	*x;
	void 	*w;
	int		y;
	int		z;
	
    y = 1;
	z = 3;
	x = &y;
	w = &z;
    f = &function;
    del = &ft_del;
	lst = ft_lstnew(x);
	sec = ft_lstnew(w);
	ft_lstadd_back(&lst, sec);
    ft_lstmap(lst, f, del);
    return (0);
}*/
