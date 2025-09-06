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

void	all_imgs(t_mapdata *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->img_it[i] = malloc(sizeof(t_img_it));
		i++;
	}
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

void	draw_ceil_floor(t_img_it *screen, t_mapdata *data, int x,
		int draw_start, int draw_end)
{
	int				w;
	int				h;
	float			y;
	unsigned int	color;

	w = data->width;
	h = data->height;
	y = 0;
	color = str_to_rgb(ft_strchr(data->mapdata[data->c_line], ' ') + 1);
	while (y < draw_start)
	{
		put_pixel_color(screen, x, y, color);
		y++;
	}
	y = draw_end;
	color = str_to_rgb(ft_strchr(data->mapdata[data->f_line], ' ') + 1);
	while (y < h)
	{
		put_pixel_color(screen, x, y, color);
		y++;
	}
}

void	create_map(t_mapdata *data)
{
	int				x;
	int				y;
	double			cameraX;
	double			rayDirX;
	double			rayDirY;
	int				mapX;
	int				mapY;
	double			deltaDistX;
	double			deltaDistY;
	int				stepX;
	int				stepY;
	double			sideDistX;
	double			sideDistY;
	int				hit;
	int				side;
	double			perpWallDist;
	int				lineHeight;
	int				drawStart;
	int				drawEnd;
	int				texIndex;
	double			wallX;
	int				texX;
	double			stepTex;
	double			texPos;
	int				texY;
	unsigned int	color;

	x = 0;
	while (x < data->width)
	{
		cameraX = 2.0 * x / (double)data->width - 1.0;
		rayDirX = data->dir_x + data->plane_x * cameraX;
		rayDirY = data->dir_y + data->plane_y * cameraX;
		mapX = (int)data->ply_x;
		mapY = (int)data->ply_y;
		deltaDistX = fabs(1 / rayDirX);
		deltaDistY = fabs(1 / rayDirY);
		if (rayDirX < 0)
			stepX = -1;
		else
			stepX = 1;
		if (rayDirY < 0)
			stepY = -1;
		else
			stepY = 1;
		if (rayDirX < 0)
			sideDistX = (data->ply_x - mapX) * deltaDistX;
		else
			sideDistX = (mapX + 1.0 - data->ply_x) * deltaDistX;
		if (rayDirY < 0)
			sideDistY = (data->ply_y - mapY) * deltaDistY;
		else
			sideDistY = (mapY + 1.0 - data->ply_y) * deltaDistY;
		hit = 0;
		while (!hit)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (mapX < 0 || mapX >= data->width || mapY < 0
				|| mapY >= data->height)
			{
				hit = 1;
				break ;
			}
			if (data->original_map[mapY][mapX]
				&& data->original_map[mapY][mapX] == '1')
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - data->ply_x + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - data->ply_y + (1 - stepY) / 2) / rayDirY;
		lineHeight = (int)(data->height / perpWallDist);
		drawStart = -lineHeight / 2 + data->height / 2;
		drawEnd = lineHeight / 2 + data->height / 2;
		if (drawStart < 0)
			drawStart = 0;
		if (drawEnd >= data->height)
			drawEnd = data->height - 1;
		if (side == 0)
		{
			if (rayDirX > 0)
				texIndex = 0;
			else
				texIndex = 1;
		}
		else
		{
			if (rayDirY > 0)
				texIndex = 2;
			else
				texIndex = 3;
		}
		if (side == 0)
			wallX = data->ply_y + perpWallDist * rayDirY;
		else
			wallX = data->ply_x + perpWallDist * rayDirX;
		wallX -= floor(wallX);
		texX = (int)(wallX * (double)data->img_it[texIndex]->width);
		if ((side == 0 && rayDirX > 0) || (side == 1 && rayDirY < 0))
			texX = data->img_it[texIndex]->width - texX - 1;
		stepTex = 1.0 * data->img_it[texIndex]->height / lineHeight;
		texPos = (drawStart - data->height / 2 + lineHeight / 2) * stepTex;
		y = drawStart;
		while (y < drawEnd)
		{
			texY = (int)texPos & (data->img_it[texIndex]->height - 1);
			texPos += stepTex;
			color = get_pixel_color(data->img_it[texIndex], texX, texY);
			if (side == 1)
				color = color / 2;
			put_pixel_color(&data->screen, x, y, color);
			y++;
		}
		if (x <= data->width && y <= data->height)
			draw_ceil_floor(&(data->screen), data, x, drawStart, drawEnd);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->screen.img,
		data->offset_x, data->offset_y);
}
