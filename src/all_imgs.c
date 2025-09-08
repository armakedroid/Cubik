#include "../includes/cube3d.h"

void imgs_utils(t_mapdata *data)
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
