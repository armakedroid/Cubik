/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:58:56 by argharag          #+#    #+#             */
/*   Updated: 2025/04/09 19:19:07 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_m	*ft_lstlast(t_m **lst)
{
	if (*lst == NULL)
		return (NULL);
	while ((*lst)->next)
		*lst = (*lst)->next;
	return (*lst);
}
/*
int main(void)
{
	t_list *node1 = ft_lstnew(NULL);
	t_list *node2 = ft_lstnew("OGHOS");
	t_list *node3 = ft_lstnew("GHOS");
	t_list *node4 = ft_lstnew("HOS");
	t_list *node5 = ft_lstnew("OS");
	t_list *node6 = ft_lstnew("S");

	node6->next = node5;
	node5->next = node4;
	node4->next = node3;
	node3->next = node2;
	node2->next = node1;

	printf("%s\n",ft_lstlast(node6)->content);
}*/
