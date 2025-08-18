/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:58:32 by argharag          #+#    #+#             */
/*   Updated: 2025/04/02 19:58:33 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
void	del(void *content)
{
	if (content)
		free(content);
	//(void)content;
}

int main(void)
{
	t_list *node1 = ft_lstnew(ft_strdup("Artur"));
	t_list *node2 = ft_lstnew(ft_strdup("jan"));

	node1->next = node2;
	ft_lstdelone(node2, &del);
	//node1->next = NULL;

	t_list *i = node1;
	while (i)
	{
		printf("%s\n", (char *)i->content);
		i = i->next;
	}
}
*/
