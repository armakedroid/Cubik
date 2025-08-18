/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:15:32 by argharag          #+#    #+#             */
/*   Updated: 2025/04/28 21:15:34 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	exit_check(t_data *data, t_mapdata *map, int m, int n)
{
	if (!(map->coin_count))
		map->mapdata[map->exit_y][map->exit_x] = 'E';
	if (!(map->coin_count) && (map->ply_x + m == map->exit_x && map->ply_y
			+ n == map->exit_y))
		win_cl(data);
}

int	coin_count(t_mapdata *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < map->map_y)
	{
		j = 0;
		while (j < map->map_x)
		{
			if (map->mapdata[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	not_wall(t_data *data, int x, int y)
{
	if (data->mapdata.mapdata[y][x] == '1')
		return (1);
	if (data->mapdata.mapdata[y][x] == 'X')
		win_cl(data);
	return (0);
}

void	go_left(t_data *data)
{
	int	x;
	int	y;

	x = data->mapdata.ply_x;
	y = data->mapdata.ply_y;
	if (!not_wall(data, x - 1, y))
	{
		data->mapdata.mapdata[y][x] = '0';
		data->mapdata.mapdata[y][x - 1] = 'P';
		data->mapdata.coin_count = coin_count(&(data->mapdata));
		data->step_count++;
		data->mapdata.ply_position = 2;
		exit_check(data, &(data->mapdata), -1, 0);
		create_map(data, &(data->mapdata));
	}
	find_player(&(data->mapdata));
}

void	go_right(t_data *data)
{
	int	x;
	int	y;

	x = data->mapdata.ply_x;
	y = data->mapdata.ply_y;
	if (!not_wall(data, x + 1, y))
	{
		data->mapdata.mapdata[y][x] = '0';
		data->mapdata.mapdata[y][x + 1] = 'P';
		data->mapdata.coin_count = coin_count(&(data->mapdata));
		data->step_count++;
		data->mapdata.ply_position = 1;
		exit_check(data, &(data->mapdata), 1, 0);
		create_map(data, &(data->mapdata));
	}
	find_player(&(data->mapdata));
	return ;
}
