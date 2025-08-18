/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <argharag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:23:32 by argharag          #+#    #+#             */
/*   Updated: 2025/04/28 20:48:30 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	destroy_imgs(t_data *data)
{
	mlx_destroy_image(data->mlx, data->map_img.wall);
	mlx_destroy_image(data->mlx, data->map_img.item);
	mlx_destroy_image(data->mlx, data->map_img.player_right);
	mlx_destroy_image(data->mlx, data->map_img.player_left);
	mlx_destroy_image(data->mlx, data->map_img.player_up);
	mlx_destroy_image(data->mlx, data->map_img.player_down);
	mlx_destroy_image(data->mlx, data->map_img.exit);
	mlx_destroy_image(data->mlx, data->map_img.collect);
	mlx_destroy_image(data->mlx, data->map_img.enemy);
}

void	all_imgs(t_data *data, t_map_s *maps)
{
	maps->wall = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm",
			&(data->width), &(data->height));
	maps->enemy = mlx_xpm_file_to_image(data->mlx, "textures/enemy.xpm",
			&(data->width), &(data->height));
	maps->item = mlx_xpm_file_to_image(data->mlx, "textures/bckgr.xpm",
			&(data->width), &(data->height));
	maps->player_right = mlx_xpm_file_to_image(data->mlx,
			"textures/main_right.xpm", &(data->width), &(data->height));
	maps->player_left = mlx_xpm_file_to_image(data->mlx,
			"textures/main_left.xpm", &(data->width), &(data->height));
	maps->player_up = mlx_xpm_file_to_image(data->mlx, "textures/main_up.xpm",
			&(data->width), &(data->height));
	maps->player_down = mlx_xpm_file_to_image(data->mlx,
			"textures/main_down.xpm", &(data->width), &(data->height));
	maps->exit = mlx_xpm_file_to_image(data->mlx, "textures/Door.xpm",
			&(data->width), &(data->height));
	if (data->endian % 4 < 2)
		maps->collect = C(data->mlx, "textures/coin2.xpm", &(data->width),
				&(data->height));
	else
		maps->collect = C(data->mlx, "textures/coin1.xpm", &(data->width),
				&(data->height));
}

void	player_position(t_data *data, t_mapdata *mp, int y, int x)
{
	if (mp->ply_position == 1)
		A(data->mlx, data->win, data->map_img.player_right, 32 * x, 32 * y);
	else if (mp->ply_position == 2)
		A(data->mlx, data->win, data->map_img.player_left, 32 * x, 32 * y);
	else if (mp->ply_position == 3)
		A(data->mlx, data->win, data->map_img.player_up, 32 * x, 32 * y);
	else
		A(data->mlx, data->win, data->map_img.player_down, 32 * x, 32 * y);
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
	all_imgs(data, &(data->map_img));
	while (++i < mp->map_y)
	{
		j = -1;
		while (++j < mp->map_x)
		{
			put_str_win(data);
			if ((mp->mapdata)[i][j] == '1')
				A(data->mlx, data->win, data->map_img.wall, 32 * j, 32 * i);
			else if ((mp->mapdata)[i][j] == '0')
				A(data->mlx, data->win, data->map_img.item, 32 * j, 32 * i);
			else if ((mp->mapdata)[i][j] == 'P')
				player_position(data, mp, i, j);
			else
				create_map_utils(data, mp, i, j);
		}
	}
	destroy_imgs(data);
}
