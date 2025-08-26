#include "../includes/cube3d.h"

// void	destroy_imgs(t_mapdata *data)
// {
// 	if (data->img_it[0].img)
// 		mlx_destroy_image(data->mlx, data->img_it[0].img);
// 	if (data->img_it[1].img)
// 		mlx_destroy_image(data->mlx, data->img_it[1].img);
// 	if (data->img_it[2].img)
// 		mlx_destroy_image(data->mlx, data->img_it[2].img);
// 	if (data->img_it[3].img)
// 		mlx_destroy_image(data->mlx, data->img_it[3].img);
// }

// void	all_imgs(t_mapdata *data)
// {
// 	data->img_it[0].img = mlx_xpm_file_to_image(data->mlx,
// 			ft_strchr(data->mapdata[data->EA_line], ' ') + 1,
// 			&(data->img_it[0].width), &(data->img_it[0].height));
// 	data->img_it[1].img = mlx_xpm_file_to_image(data->mlx,
// 			ft_strchr(data->mapdata[data->WE_line], ' ') + 1,
// 			&(data->img_it[1].width), &(data->img_it[1].height));
// 	data->img_it[2].img = mlx_xpm_file_to_image(data->mlx,
// 			ft_strchr(data->mapdata[data->NO_line], ' ') + 1,
// 			&(data->img_it[2].width), &(data->img_it[2].height));
// 	data->img_it[3].img = mlx_xpm_file_to_image(data->mlx,
// 			ft_strchr(data->mapdata[data->SO_line], ' ') + 1,
// 			&(data->img_it[3].width), &(data->img_it[3].height));
// 	return ;
// }

// unsigned int	str_to_rgb(const char *str)
// {
// 	char			**parts;
// 	unsigned int	color;
// 	int				r;
// 	int				g;
// 	int				b;

// 	parts = ft_split(str, ',');
// 	if (!parts)
// 		return (0);
// 	r = ft_atoi(parts[0]);
// 	g = ft_atoi(parts[1]);
// 	b = ft_atoi(parts[2]);
// 	color = (r << 16) | (g << 8) | b;
// 	free_str(parts, 0);
// 	return (color);
// }

// unsigned int	get_pixel_color(t_img_it *tex, int x, int y)
// {
// 	char	*dst;

// 	dst = tex->addr + (y * tex->line_length + x * (tex->bits_per_pixel / 8));
// 	return (*(unsigned int *)dst);
// }

// void	put_pixel_color(t_img_it *img, int x, int y, unsigned int color)
// {
// 	char	*dst;

// 	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// void	draw_ceil_floor(t_img_it *screen, t_mapdata *data)
// {
// 	int		w;
// 	int		h;
// 	float	x;
// 	float	y;

// 	w = data->width;
// 	h = data->height;
// 	x = w;
// 	while (x)
// 	{
// 		y = h / 2;
// 		while (y)
// 		{
// 			put_pixel_color(screen, x, y,
// 				str_to_rgb(ft_strchr(data->mapdata[data->C_line], ' ') + 1));
// 			y--;
// 		}
// 		x--;
// 	}
// 	x = w;
// 	while (x)
// 	{
// 		y = h;
// 		while (y >= h / 2)
// 		{
// 			put_pixel_color(screen, x, y,
// 				str_to_rgb(ft_strchr(data->mapdata[data->F_line], ' ') + 1));
// 			y--;
// 		}
// 		x--;
// 	}
// }

// void	draw_from_texture(t_img_it *screen, t_img_it *tex, t_mapdata *data)
// {
// 	int				w;
// 	int				h;
// 	float			x;
// 	float			y;
// 	float			i;
// 	int				tex_x;
// 	int				tex_y;
// 	unsigned int	color;

// 	w = 1920;
// 	h = 1080;
// 	x = w;
// 	i = 0;
// 	while (x > (w / 3) * 2)
// 	{
// 		y = h - i;
// 		if (y <= i)
// 			break ;
// 		while (y-- > i)
// 		{
// 			tex_x = (int)((float)tex->width * (((float)x + data->step_up)
// 						/ (float)w));
// 			tex_y = (int)((float)tex->height * (((float)y + data->step_around)
// 						/ (float)h));
// 			if (tex_x >= 0 && tex_x < tex->width && tex_y >= 0
// 				&& tex_y < tex->height && x >= 0 && x < screen->width && y >= 0
// 				&& y < screen->height)
// 			{
// 				color = get_pixel_color(tex, tex_x, tex_y);
// 				put_pixel_color(screen, x, y, color);
// 			}
// 		}
// 		i += 0.5;
// 		x--;
// 	}
// 	while (x-- > (w / 3))
// 	{
// 		y = h - i;
// 		if (y <= 300)
// 			break ;
// 		while (y-- > i)
// 		{
// 			tex_x = (int)((float)tex->width * (((float)x + data->step_up)
// 						/ (float)w));
// 			tex_y = (int)((float)tex->height * (((float)y + data->step_around)
// 						/ (float)h));
// 			if (tex_x >= 0 && tex_x < tex->width && tex_y >= 0
// 				&& tex_y < tex->height && x >= 0 && x < screen->width && y >= 0
// 				&& y < screen->height)
// 			{
// 				color = 0xFFFFFFF;
// 				put_pixel_color(screen, x, y, color);
// 			}
// 		}
// 	}
// 	while (x--)
// 	{
// 		y = h - i;
// 		if (y <= 0)
// 			break ;
// 		while (y-- > i)
// 		{
// 			tex_x = (int)((float)tex->width * (((float)x + data->step_around)
// 						/ (float)w));
// 			tex_y = (int)((float)tex->height * (((float)y + data->step_around)
// 						/ (float)h));
// 			if (tex_x >= 0 && tex_x < tex->width && tex_y >= 0
// 				&& tex_y < tex->height && x >= 0 && x < screen->width && y >= 0
// 				&& y < screen->height)
// 			{
// 				color = get_pixel_color(tex, tex_x, tex_y);
// 				put_pixel_color(screen, x, y, color);
// 			}
// 		}
// 		i -= 0.5;
// 	}
// }

// void	create_map(t_mapdata *data)
// {
// 	t_img_it	screen;
// 	t_img_it	*wall;
// 	int			i;

// 	i = 0;
// 	all_imgs(data);
// 	wall = NULL;
// 	screen.width = data->width;
// 	screen.height = data->height;
// 	screen.img = mlx_new_image(data->mlx, screen.width, screen.height);
// 	screen.addr = mlx_get_data_addr(screen.img, &screen.bits_per_pixel,
// 			&screen.line_length, &screen.endian);
// 	draw_ceil_floor(&screen, data);
// 	mlx_put_image_to_window(data->mlx, data->win, screen.img, 0, 0);
// 	mlx_destroy_image(data->mlx, screen.img);
// 	// while (i < 1)
// 	// {
// 	// 	wall = &data->img_it[i];
// 	// 	screen.width = 1920;
// 	// 	screen.height = 1080;
// 	// 	screen.img = mlx_new_image(data->mlx, 1920, 1080);
// 	// 	screen.addr = mlx_get_data_addr(screen.img, &screen.bits_per_pixel,
// 	// 			&screen.line_length, &screen.endian);
// 	// 	wall->addr = mlx_get_data_addr(wall->img, &wall->bits_per_pixel,
// 	// 			&wall->line_length, &wall->endian);
// 	// 	draw_from_texture(&screen, wall, data);
// 	// 	mlx_put_image_to_window(data->mlx, data->win, screen.img, 0, 0);
// 	// 	mlx_destroy_image(data->mlx, screen.img);
// 	// 	i++;
// 	// }
// 	destroy_imgs(data);
// }
