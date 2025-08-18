/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <argharag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:09:56 by argharag          #+#    #+#             */
/*   Updated: 2025/04/25 21:09:57 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	go_up(t_data *data)
{
	int	x;
	int	y;

	x = data->mapdata.ply_x;
	y = data->mapdata.ply_y;
	if (!not_wall(&(data->mapdata), x, y - 1))
	{
		data->mapdata.mapdata[y][x] = '0';
		data->mapdata.mapdata[y - 1][x] = 'P';
		data->mapdata.coin_count = coin_count(&(data->mapdata));
		data->step_count++;
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
	if (!not_wall(&(data->mapdata), x, y + 1))
	{
		data->mapdata.mapdata[y][x] = '0';
		data->mapdata.mapdata[y + 1][x] = 'P';
		data->mapdata.coin_count = coin_count(&(data->mapdata));
		data->step_count++;
		exit_check(data, &(data->mapdata), 0, 1);
		create_map(data, &(data->mapdata));
	}
	find_player(&(data->mapdata));
	return ;
}
