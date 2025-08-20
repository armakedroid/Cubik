/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:58:16 by argharag          #+#    #+#             */
/*   Updated: 2025/04/09 19:19:30 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_m **lst, t_m *new)
{
	t_m	*node;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	node = *lst;
	new->next = node;
	new->prev = NULL;
	node->prev = new;
	*lst = new;
}
/*
int main(void) 
{
	t_list *node1 = ft_lstnew("Artur");
	t_list *node2 = ft_lstnew("jan");
	t_list *node3 = ft_lstnew("barev");

	node1->next = node2;
	t_list *all = node1;
	ft_lstadd_front(&all, node3);

	t_list *i = all;
	while (i)
	{
		printf("%s\n", (char *)i->content);
		i = i->next;
	}
}
*/
