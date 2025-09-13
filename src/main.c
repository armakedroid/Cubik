/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:10:31 by apetoyan          #+#    #+#             */
/*   Updated: 2025/09/13 20:09:17 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	win_close(int keycode, t_mapdata *data)
{
	data->press = 1;
	if (keycode == KEY_W)
		data->key[0] = 1;
	else if (keycode == KEY_S)
		data->key[1] = 1;
	else if (keycode == KEY_D)
		data->key[2] = 1;
	else if (keycode == KEY_A)
		data->key[3] = 1;
	else if (keycode == KEY_LEFT)
		data->key[4] = 1;
	else if (keycode == KEY_RIGHT)
		data->key[5] = 1;
	else if (keycode == KEY_ESC)
		data->key[6] = 1;
	return (0);
}

int	win_cl_1(int keycode, t_mapdata *data)
{
	data->press = 0;
	if (keycode == KEY_W)
		data->key[0] = 0;
	else if (keycode == KEY_S)
		data->key[1] = 0;
	else if (keycode == KEY_D)
		data->key[2] = 0;
	else if (keycode == KEY_A)
		data->key[3] = 0;
	else if (keycode == KEY_LEFT)
		data->key[4] = 0;
	else if (keycode == KEY_RIGHT)
		data->key[5] = 0;
	else if (keycode == KEY_ESC)
		data->key[6] = 0;
	return (0);
}

int	move_smwh(t_mapdata *data)
{
	if (!(data->press))
		return (0);
	if (data->key[0])
		go_forward(data);
	if (data->key[1])
		go_back(data);
	if (data->key[2])
		go_right(data);
	if (data->key[3])
		go_left(data);
	if (data->key[4])
		rot_left(data, -0.05);
	if (data->key[5])
		rot_right(data, 0.05);
	if (data->key[6])
		win_cl(data);
	create_map(data);
	return (0);
}

int	win_cl(t_mapdata *data)
{
	destroy_imgs(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_str(data->mapdata, 0);
	free_str(data->original_map, 0);
	exit(0);
}

int	main(int argc, char **argv)
{
	int			i;
	t_mapdata	arg;

	init(&arg);
	if (argc != 2)
		return (ft_putstr_fd("Error\nWrong argument number\n", 2), 1);
	i = validation(argv[1], &arg);
	if (i == -1)
	{
		free_str(arg.mapdata, 0);
		free_str(arg.original_map, 0);
		return (ft_putstr_fd("Error\n", 2), 1);
	}
	arg.mlx = mlx_init();
	if (!arg.mlx)
		return (1);
	arg_mlx(&arg);
	dir_ply_init(&arg);
	all_imgs(&arg);
	create_map(&arg);
	mlx_hook(arg.win, 17, 0, win_cl, &arg);
	mlx_hook(arg.win, 2, 1L << 0, win_close, &arg);
	mlx_hook(arg.win, 3, 1L << 1, win_cl_1, &arg);
	mlx_loop_hook(arg.mlx, move_smwh, &arg);
	mlx_loop(arg.mlx);
}
