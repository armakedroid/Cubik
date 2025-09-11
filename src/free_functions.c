/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:10:08 by apetoyan          #+#    #+#             */
/*   Updated: 2025/09/11 22:44:29 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	free_str(char **str, int count)
{
	int	a;

	a = 0;
	if (!count)
	{
		while (str[count])
			count++;
	}
	while (a < count)
	{
		my_free(str[a]);
		a++;
	}
	free(str);
}

void	my_free(char *str)
{
	if (str)
		free(str);
	str = NULL;
}
