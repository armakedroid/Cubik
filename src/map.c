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

void	create_map(t_mapdata *data)
{
	t_vars_put	vars;

	vars.i = 0;
	draw_ceil_floor(&(data->screen), data);
	while (vars.i < 4)
	{
		vars.dst_w = data->img_it[vars.i]->width + data->offset_y;
		vars.dst_h = data->img_it[vars.i]->height + data->offset_y;
		vars.dst_x = data->screen.width / 3 - vars.dst_w / 2 + data->offset_x;
		vars.dst_y = data->screen.height / 2 - vars.dst_h / 2;
		draw_from_texture(&(data->screen), data->img_it[vars.i], data, &vars);
		mlx_put_image_to_window(data->mlx, data->win, data->screen.img, 0, 0);
		(vars.i)++;
	}
}
