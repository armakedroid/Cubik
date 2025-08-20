/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:09:44 by argharag          #+#    #+#             */
/*   Updated: 2025/08/20 20:52:43 by apetoyan         ###   ########.fr       */
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

// void	my_mlx_pixel_put(t_data *px, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = px->addr + (y * px->line_length + x * (px->bits_by_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

void	draw_on_image(t_data *data)
{
	float	x;
	float	y;
	int	color;
	int	w;
	int	h;
	float	i;

	w = 1900;
	x = w;
	h = 800;
	i = 0;
	while (x-- > 1200)
	{
		y = h - i;
		if (y <= i)
			break;
		while (y-- > i)
		{
			// color = (x * 255) / w + ((((w - x) * 255) / w) << 16) + (((y * 255)
			// 			/ h) << 8);
			color = 120;
			mlx_pixel_put(data->mlx, data->win, x, y, color);
		}
		i += 0.5;
		printf("x = %f, y = %f, i = %f\n", x, y, i);
	}
	while (x-- > 800)
	{
		y = h - i;
		if (y < 300)
			break;
		while (y-- > i)
		{
			// color = (x * 255) / w + ((((w - x) * 255) / w) << 16) + (((y * 255)
			// 			/ h) << 8);
			color = 56;
			mlx_pixel_put(data->mlx, data->win, x, y, color);
		}
		// i += 0.5;
	}
	printf("x = %f, y = %f, i = %f", x, y, i);
	
	while (x--)
	{
		y = h - i;
		if (y <= 0)
			break;
		while (y-- > i)
		{
			// color = (x * 255) / w + ((((w - x) * 255) / w) << 16) + (((y * 255)
			// 			/ h) << 8);
			color = 120;
			mlx_pixel_put(data->mlx, data->win, x, y, color);
		}
		i -= 0.5;
	}
	printf("x = %f, y = %f, i = %f", x, y, i);
	// while (y < 30)
	// {
	// 	color = (x * 255) / w + ((((w - x) * 255) / w) << 16) + (((y * 255)
					// / h) << 8);
	// 	mlx_pixel_put(data->mlx, data->win, x, y, color);
	// 	y++;
	// }
	// while (y < 40)
	// {
	// 	color = (x * 255) / w + ((((w - x) * 255) / w) << 16) + (((y * 255)
					// / h) << 8);
	// 	mlx_pixel_put(data->mlx, data->win, x, y, color);
	// 	y++;
	// }
	// while (y < 50)
	// {
	// 	color = (x * 255) / w + ((((w - x) * 255) / w) << 16) + (((y * 255)
					// / h) << 8);
	// 	mlx_pixel_put(data->mlx, data->win, x, y, color);
	// 	y++;
	// }
}

void	create_map(t_data *data, t_mapdata *mp)
{
	int	i;
	int	j;

	i = -1;
	j = 450;
	(void)mp;
	// while (i++ < j)
	// {
		draw_on_image(data);
	// }
	all_imgs(data, &(data->map_img), 1);
	// mlx_put_image_to_window(data->mlx, data->win, data->map_img.wall, 0, 0);
	// while (++i < mp->map_y)
	// {
	// 	j = -1;
	// 	while (++j < mp->map_x)
	// 	{
	// 		if ((mp->mapdata)[i][j] == '1')
	// 			A(data->mlx, data->win, data->map_img.wall, 32 * j, 32 * i);
	// 		else if ((mp->mapdata)[i][j] == '0')
	// 			A(data->mlx, data->win, data->map_img.item, 32 * j, 32 * i);
	// 		else if ((mp->mapdata)[i][j] == 'P')
	// 			A(data->mlx, data->win, data->map_img.player, 32 * j, 32 * i);
	// 		else if ((mp->mapdata)[i][j] == 'E')
	// 			find_exit(data, i, j, mp->coin_count);
	// 		else if ((mp->mapdata)[i][j] == 'C')
	// 			A(data->mlx, data->win, data->map_img.collect, 32 * j, 32 * i);
	// 	}
	// }
	destroy_imgs(data);
}
