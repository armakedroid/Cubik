#include "../includes/cube3d.h"

void	dir_ply_init(t_mapdata *data)
{
	if (data->mapdata[data->ply_y][data->ply_x] == 'N')
	{
		data->dir_x = 0;
		data->dir_y = -1;
		data->plane_x = 0.66;
		data->plane_y = 0;
	}
	else if (data->mapdata[data->ply_y][data->ply_x] == 'S')
	{
		data->dir_x = 0;
		data->dir_y = 1;
		data->plane_x = -0.66;
		data->plane_y = 0;
	}
	else if (data->mapdata[data->ply_y][data->ply_x] == 'E')
	{
		data->dir_x = 1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = 0.66;
	}
	else if (data->mapdata[data->ply_y][data->ply_x] == 'W')
	{
		data->dir_x = -1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = -0.66;
	}
}

int	win_close(int keycode, t_mapdata *data)
{
	if (keycode == KEY_W)
		go_forward(data);
	else if (keycode == KEY_S)
		go_back(data);
	else if (keycode == KEY_D)
		go_right(data);
	else if (keycode == KEY_A)
		go_left(data);
	else if (keycode == KEY_LEFT)
		rot_left(data, 0.05);
	else if (keycode == KEY_RIGHT)
		rot_right(data, 0.05);
	else if (keycode == KEY_ESC || keycode == KEY_Q)
	{
		destroy_imgs(data);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	create_map(data);
	return (1);
}

int	win_cl(t_mapdata *data)
{
	destroy_imgs(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	int i;
	t_mapdata arg;

	arg.move_speed = 1;
	arg.dir_x = 0;
	arg.dir_y = 0;
	arg.ply_x = 0;
	arg.ply_y = 0;
	arg.plane_x = 3;
	arg.plane_y = 3;
	arg.offset_x = 0;
	arg.offset_y = 0;

	if (argc != 2)
		return (ft_putstr_fd("Error\nWrong argument number\n", 2), 1);
	i = validation(argv[1], &arg);
	if (i == -1)
		return (ft_putstr_fd("Error\n", 2), 1);
	arg.mlx = mlx_init();
	if (!arg.mlx)
		return (1);
	arg.width = 1920;
	arg.height = 1080;
	arg.win = mlx_new_window(arg.mlx, arg.width, arg.height, "Cube3D");
	arg.screen.width = arg.width;
	arg.screen.height = arg.height;
	arg.screen.img = mlx_new_image(arg.mlx, arg.screen.width,
			arg.screen.height);
	arg.screen.addr = mlx_get_data_addr(arg.screen.img,
			&(arg.screen.bits_per_pixel), &(arg.screen.line_length),
			&(arg.screen.endian));
	dir_ply_init(&arg);
	all_imgs(&arg);
	create_map(&arg);
	mlx_hook(arg.win, 17, 0, win_cl, &arg);
	mlx_hook(arg.win, 2, 1L << 0, win_close, &arg);
	mlx_loop(arg.mlx);
}