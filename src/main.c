#include "../includes/cube3d.h"

// int	win_close(int keycode, t_mapdata *data)
// {
// 	if (keycode == KEY_W)
// 		go_forward(data);
// 	else if (keycode == KEY_S)
// 		go_back(data);
// 	else if (keycode == KEY_D)
// 		go_right(data);
// 	else if (keycode == KEY_A)
// 		go_left(data);
// 	else if (keycode == KEY_LEFT)
// 		rot_left(data, data->rot_speed);
// 	else if (keycode == KEY_RIGHT)
// 		rot_right(data, data->rot_speed);
// 	else if (keycode == KEY_ESC || keycode == KEY_Q)
// 	{
// 		mlx_destroy_window(data->mlx, data->win);
// 		mlx_destroy_display(data->mlx);
// 		// free_str(data->mapdata.mapdata, data->mapdata.map_y);
// 		free(data->mlx);
// 		exit(0);
// 	}
// 	return (1);
// }

int	win_cl(t_mapdata *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	// free_str(data->mapdata.mapdata, data->mapdata.map_y);
	free(data->mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	int i;
	t_mapdata arg;

	if (argc != 2)
		return (ft_putstr_fd("Error\nWrong argument number\n", 2), 1);
	i = validation(argv[1], &arg);
	// if (i == -1)
	// 	return (ft_putstr_fd("Error\n", 2), 1);
	// arg.mlx = mlx_init();
	// if (!arg.mlx)
	// 	return (1);
	// arg.width = 1920;
	// arg.height = 1080;
	// arg.win = mlx_new_window(arg.mlx, arg.width, arg.height, "Cube3D");
	// create_map(&arg);
	// mlx_hook(arg.win, 17, 0, win_cl, &arg);
	// mlx_hook(arg.win, 2, 1L << 0, win_close, &arg);
	// mlx_loop(arg.mlx);
}