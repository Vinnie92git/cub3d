/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becamino <becamino@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:25:21 by becamino          #+#    #+#             */
/*   Updated: 2023/11/03 12:32:13 by becamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

//Takes a node 'lst' and free mem of the content usind 'del' function
//and the node.
//Mem of next must not be free.

//Free memory of the content.
/*void	ft_del(void *p)
{
	p = (void *)0;
}*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*int	main(void)
{
	t_list	*lst;
	int		y;
	void	*x;
	void	(*del)(void *);

	y = 59;
	x = &y;
	del = &ft_del;
	lst = ft_lstnew(x);
	ft_lstdelone(lst, del);
	return (0);
}*/
