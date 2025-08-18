/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <argharag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:23:49 by argharag          #+#    #+#             */
/*   Updated: 2025/04/28 20:47:39 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	go_up(t_data *data)
{
	int	x;
	int	y;

	x = data->mapdata.ply_x;
	y = data->mapdata.ply_y;
	if (!not_wall(data, x, y - 1))
	{
		data->mapdata.mapdata[y][x] = '0';
		data->mapdata.mapdata[y - 1][x] = 'P';
		data->mapdata.coin_count = coin_count(&(data->mapdata));
		data->step_count++;
		data->mapdata.ply_position = 3;
		exit_check(data, &(data->mapdata), 0, -1);
		create_map(data, &(data->mapdata));
	}
	find_player(&(data->mapdata));
	return ;
}

void	go_down(t_data *data)
{
	int	x;
	int	y;

	x = data->mapdata.ply_x;
	y = data->mapdata.ply_y;
	if (!not_wall(data, x, y + 1))
	{
		data->mapdata.mapdata[y][x] = '0';
		data->mapdata.mapdata[y + 1][x] = 'P';
		data->mapdata.coin_count = coin_count(&(data->mapdata));
		data->step_count++;
		data->mapdata.ply_position = 4;
		exit_check(data, &(data->mapdata), 0, 1);
		create_map(data, &(data->mapdata));
	}
	find_player(&(data->mapdata));
	return ;
}

void	create_map_utils(t_data *data, t_mapdata *mp, int i, int j)
{
	if ((mp->mapdata)[i][j] == 'E')
		find_exit(data, i, j, mp->coin_count);
	else if ((mp->mapdata)[i][j] == 'C')
		A(data->mlx, data->win, data->map_img.collect, 32 * j, 32 * i);
	else if ((mp->mapdata)[i][j] == 'X')
		A(data->mlx, data->win, data->map_img.enemy, 32 * j, 32 * i);
}
