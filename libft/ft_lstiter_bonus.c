/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:58:41 by argharag          #+#    #+#             */
/*   Updated: 2025/04/02 19:58:42 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void	my_f(void *lst)
{
	(void)lst;
}

int main()
{
	t_list	*node1 = ft_lstnew("Artur");
	t_list	*node2 = ft_lstnew("Kiril");
	t_list	*node3 = ft_lstnew("Samson");

	node1->next = node2;
	node2->next = node3;
	t_list *all = node1;
	ft_lstiter(node1,&my_f);
	while (all)
	{
		printf("%s\n",all->content);
		all = all->next;
	}
}*/
