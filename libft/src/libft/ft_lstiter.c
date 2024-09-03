/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:40:32 by becamino          #+#    #+#             */
/*   Updated: 2024/03/13 15:45:09 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

//Iters 'lst' list and applies function 'f' in every node content.
/*void	ft_zero(void *p)
{
	
}*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !(*f))
		return ;
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/*int main(void)
{
	t_list	*lst;
	int		x;
	void	*y;
	void	(*f)(void *);
	

	x = 5;
	y = &x;
	lst = ft_lstnew(y);
	f = &ft_zero;
	return (0);
}*/