/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:58:24 by argharag          #+#    #+#             */
/*   Updated: 2025/04/09 19:19:50 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_m **lst, t_m *new)
{
	t_m	*back;

	back = NULL;
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	back = *lst;
	while (back->next)
		back = back->next;
	back->next = new;
	new->prev = back;
}
/*
int main(void)
{
	t_my_nodes *node1 = ft_lstnew("Artur");
	t_my_nodes *node2 = ft_lstnew("jan");
	t_my_nodes *node3 = ft_lstnew("barev");

	node1->next = node2;
	t_my_nodes *all = node1;
	ft_lstadd_back(&all, node3);

	t_my_nodes *i = all;
	while (i)
	{
		printf("%s\n", (char *)i->content);
		i = i->next;
	}
}*/
