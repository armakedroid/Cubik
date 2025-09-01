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

void	draw_ceil_floor(t_img_it *screen, t_mapdata *data)
{
	int		w;
	int		h;
	float	x;
	float	y;

	w = data->width;
	h = data->height;
	x = 0;
	while (x < w)
	{
		y = 0;
		while (y < h / 2)
		{
			put_pixel_color(screen, x, y,
				str_to_rgb(ft_strchr(data->mapdata[data->c_line], ' ') + 1));
			y++;
		}
		while (y < h)
		{
			put_pixel_color(screen, x, y,
				str_to_rgb(ft_strchr(data->mapdata[data->f_line], ' ') + 1));
			y++;
		}
		x++;
	}
}

void	draw_from_texture(t_img_it *screen, t_img_it *tex, t_mapdata *data,
		t_vars_put *vars)
{
	int				w;
	int				h;
	float			x;
	float			y;
	int				tex_x;
	int				tex_y;
	unsigned int	color;

	w = data->width;
	h = data->height;
	x = 0;
	while (x < vars->dst_w)
	{
		y = 0;
		while (y < vars->dst_h)
		{
			tex_x = x * tex->width / vars->dst_w;
			tex_y = y * tex->height / vars->dst_h;
			if (tex_x >= 0 && tex_x < tex->width && tex_y >= 0
				&& tex_y < tex->height && x >= 0 && x < screen->width && y >= 0
				&& y < screen->height)
			{
				color = get_pixel_color(tex, tex_x, tex_y);
				put_pixel_color(screen, vars->dst_x + x
					+ ((data->img_it[vars->i]->width * 4) * vars->i),
					vars->dst_y + y, color);
			}
			y++;
		}
		x++;
	}
}

// void	create_map(t_mapdata *data)
// {
// 	t_vars_put	vars;

// 	vars.i = 0;
// 	draw_ceil_floor(&(data->screen), data);
// 	while (vars.i < 4)
// 	{
// 		vars.dst_w = data->img_it[vars.i]->width + data->offset_y;
// 		vars.dst_h = data->img_it[vars.i]->height + data->offset_y;
// 		vars.dst_x = data->screen.width / 3 - vars.dst_w / 2 + data->offset_x;
// 		vars.dst_y = data->screen.height / 2 - vars.dst_h / 2;
// 		draw_from_texture(&(data->screen), data->img_it[vars.i], data, &vars);
// 		mlx_put_image_to_window(data->mlx, data->win, data->screen.img, 0, 0);
// 		(vars.i)++;
// 	}
// }

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
		int stepX;
		int stepY;
		double sideDistX;
		double sideDistY;
	int				hit;
		int side;
		double perpWallDist;
	int				lineHeight;
	int				drawStart;
	int				drawEnd;
		int texIndex;
		double wallX;
	int				texX;
	double			stepTex;
	double			texPos;
	int				texY;
	unsigned int	color;

	x = 0;
	draw_ceil_floor(&(data->screen), data);
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
			if (data->original_map[mapY][mapX] && data->original_map[mapY][mapX] == '1')
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
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->screen.img, data->offset_x, data->offset_y);
}
