/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <argharag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:09:44 by argharag          #+#    #+#             */
/*   Updated: 2025/04/28 20:46:34 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	destroy_imgs(t_data *data)
{
	mlx_destroy_image(data->mlx, data->map_img.wall);
	mlx_destroy_image(data->mlx, data->map_img.item);
	mlx_destroy_image(data->mlx, data->map_img.player);
	mlx_destroy_image(data->mlx, data->map_img.exit);
	mlx_destroy_image(data->mlx, data->map_img.collect);
}

void	all_imgs(t_data *data, t_map_s *maps, int k)
{
	if (k)
	{
		maps->wall = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm",
				&(data->width), &(data->height));
		maps->item = mlx_xpm_file_to_image(data->mlx, "textures/bckgr.xpm",
				&(data->width), &(data->height));
		maps->player = mlx_xpm_file_to_image(data->mlx,
				"textures/main_down.xpm", &(data->width), &(data->height));
		maps->exit = mlx_xpm_file_to_image(data->mlx, "textures/Door.xpm",
				&(data->width), &(data->height));
		maps->collect = mlx_xpm_file_to_image(data->mlx, "textures/coin1.xpm",
				&(data->width), &(data->height));
		return ;
	}
}

void	find_exit(t_data *data, int y, int x, int coin_count)
{
	data->mapdata.exit_x = x;
	data->mapdata.exit_y = y;
	if (coin_count)
		mlx_put_image_to_window(data->mlx, data->win, data->map_img.item, 32
			* x, 32 * y);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->map_img.exit, 32
			* x, 32 * y);
}

void	create_map(t_data *data, t_mapdata *mp)
{
	int	i;
	int	j;

	i = -1;
	all_imgs(data, &(data->map_img), 1);
	while (++i < mp->map_y)
	{
		j = -1;
		while (++j < mp->map_x)
		{
			if ((mp->mapdata)[i][j] == '1')
				A(data->mlx, data->win, data->map_img.wall, 32 * j, 32 * i);
			else if ((mp->mapdata)[i][j] == '0')
				A(data->mlx, data->win, data->map_img.item, 32 * j, 32 * i);
			else if ((mp->mapdata)[i][j] == 'P')
				A(data->mlx, data->win, data->map_img.player, 32 * j, 32 * i);
			else if ((mp->mapdata)[i][j] == 'E')
				find_exit(data, i, j, mp->coin_count);
			else if ((mp->mapdata)[i][j] == 'C')
				A(data->mlx, data->win, data->map_img.collect, 32 * j, 32 * i);
		}
	}
	destroy_imgs(data);
}
