/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:00:07 by apetoyan          #+#    #+#             */
/*   Updated: 2025/09/08 20:21:34 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	imgs_utils(t_mapdata *data)
{
	data->img_it[0]->img = mlx_xpm_file_to_image(data->mlx,
			ft_strchr(data->mapdata[data->ea_line], ' ') + 2,
			&(data->img_it[0]->width), &(data->img_it[0]->height));
	data->img_it[1]->img = mlx_xpm_file_to_image(data->mlx,
			ft_strchr(data->mapdata[data->we_line], ' ') + 2,
			&(data->img_it[1]->width), &(data->img_it[1]->height));
	data->img_it[2]->img = mlx_xpm_file_to_image(data->mlx,
			ft_strchr(data->mapdata[data->no_line], ' ') + 2,
			&(data->img_it[2]->width), &(data->img_it[2]->height));
	data->img_it[3]->img = mlx_xpm_file_to_image(data->mlx,
			ft_strchr(data->mapdata[data->so_line], ' ') + 2,
			&(data->img_it[3]->width), &(data->img_it[3]->height));
}

void	all_imgs(t_mapdata *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->img_it[i] = malloc(sizeof(t_img_it));
		i++;
	}
	imgs_utils(data);
	i = 0;
	while (i < 4)
	{
		data->img_it[i]->addr = mlx_get_data_addr(data->img_it[i]->img,
				&(data->img_it[i]->bits_per_pixel),
				&(data->img_it[i]->line_length), &(data->img_it[i]->endian));
		i++;
	}
	return ;
}

void	create_map(t_mapdata *data)
{
	t_create	map;

	map.x = 0;
	while (map.x < data->width)
	{
		utils3(&map, data);
		while (map.y < map.draw_end)
		{
			map.tex_y = (int)map.tex_pos & (data->img_it[map.tex_index]->height
					- 1);
			map.tex_pos += map.step_tex;
			map.color = get_pixel_color(data->img_it[map.tex_index], map.tex_x,
					map.tex_y);
			if (map.side == 1)
				map.color = map.color / 2;
			put_pixel_color(&data->screen, map.x, map.y, map.color);
			map.y++;
		}
		if (map.x <= data->width && map.y <= data->height)
			draw_ceil_floor(&(data->screen), data, &map);
		map.x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->screen.img,
		data->offset_x, data->offset_y);
}
