/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_inside.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <argharag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:09:30 by argharag          #+#    #+#             */
/*   Updated: 2025/04/25 21:09:31 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	check_ins_left_right(char **map, int count)
{
	int	m;
	int	i;

	m = 0;
	i = 0;
	while (map[i][m])
		m++;
	m--;
	while (i < count)
	{
		if ((map[i][0] != '1') || (map[i][m] != '1'))
			return (1);
		i++;
	}
	if (check_all_s(map, count))
		return (1);
	return (0);
}

int	check_map_inside(char **map, int count)
{
	int	i;
	int	m;

	m = 0;
	i = 0;
	if (count > 2)
	{
		while (map[0][m] != '\0')
		{
			if (map[0][m] != '1')
				return (1);
			m++;
		}
		while (map[count - 1][i])
		{
			if (map[count - 1][i] != '1')
				return (1);
			i++;
		}
	}
	if (check_ins_left_right(map, count))
		return (1);
	return (0);
}
