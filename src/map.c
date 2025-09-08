/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:10:41 by apetoyan          #+#    #+#             */
/*   Updated: 2025/09/08 20:11:50 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	destroy_imgs(t_mapdata *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->img_it[i]->img)
			mlx_destroy_image(data->mlx, data->img_it[i]->img);
		free(data->img_it[i]);
		data->img_it[i] = NULL;
		i++;
	}
	mlx_destroy_image(data->mlx, data->screen.img);
}

unsigned int	str_to_rgb(const char *str)
{
	char			**parts;
	unsigned int	color;
	int				r;
	int				g;
	int				b;

	parts = ft_split(str, ',');
	if (!parts)
		return (0);
	r = ft_atoi(parts[0]);
	g = ft_atoi(parts[1]);
	b = ft_atoi(parts[2]);
	color = (r << 16) | (g << 8) | b;
	free_str(parts, 0);
	return (color);
}

unsigned int	get_pixel_color(t_img_it *tex, int x, int y)
{
	char	*dst;

	dst = tex->addr + (y * tex->line_length + x * (tex->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	put_pixel_color(t_img_it *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_ceil_floor(t_img_it *screen, t_mapdata *data, t_create *vars)
{
	int				w;
	int				h;
	float			y;
	unsigned int	color;

	w = data->width;
	h = data->height;
	y = 0;
	color = str_to_rgb(ft_strchr(data->mapdata[data->c_line], ' ') + 1);
	while (y < vars->draw_start)
	{
		put_pixel_color(screen, vars->x, y, color);
		y++;
	}
	y = vars->draw_end;
	color = str_to_rgb(ft_strchr(data->mapdata[data->f_line], ' ') + 1);
	while (y < h)
	{
		put_pixel_color(screen, vars->x, y, color);
		y++;
	}
}
