/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:59:20 by argharag          #+#    #+#             */
/*   Updated: 2025/04/09 19:27:56 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_m	*ft_lstnew(int num, int index)
{
	t_m	*node;

	node = (t_m *)malloc(sizeof(t_m));
	if (!node)
		return (NULL);
	node->num = num;
	node->index = index;
	node->next = 0;
	node->prev = 0;
	return (node);
}
/*
int main()
{
	char	str[]	= "Artur";
	t_list *c = ft_lstnew(str);
	printf("%s",c ->content);
}
*/
