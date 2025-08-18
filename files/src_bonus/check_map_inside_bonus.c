/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_inside_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <argharag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:09:30 by argharag          #+#    #+#             */
/*   Updated: 2025/04/28 20:48:39 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	put_str_win(t_data *data)
{
	char	*str;

	str = ft_itoa(data->step_count);
	mlx_string_put(data->mlx, data->win, 45, 50, 0, str);
	mlx_string_put(data->mlx, data->win, 46, 50, 0, str);
	mlx_string_put(data->mlx, data->win, 44, 50, 0, str);
	free(str);
}

int	update_coin(t_data *data)
{
	data->endian++;
	create_map(data, &(data->mapdata));
	return (1);
}

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
