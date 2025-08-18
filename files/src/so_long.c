/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <argharag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:09:49 by argharag          #+#    #+#             */
/*   Updated: 2025/04/28 19:54:01 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	free_str(char **str, int count)
{
	int	a;

	a = 0;
	while (a < count)
	{
		free(str[a]);
		a++;
	}
	free(str);
}

int	win_close(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		go_up(data);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		go_down(data);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		go_right(data);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		go_left(data);
	else if (keycode == KEY_ESC || keycode == KEY_Q)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free_str(data->mapdata.mapdata, data->mapdata.map_y);
		free(data->mlx);
		exit(0);
	}
	return (1);
}

int	win_cl(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_str(data->mapdata.mapdata, data->mapdata.map_y);
	free(data->mlx);
	exit(0);
}

int	render_hook(t_data *data)
{
	create_map(data, &(data->mapdata));
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_mapdata	*map;
	int			win_width;
	int			win_height;

	if (argc != 2)
		return (write(2, "Error\n", 6));
	map = &(data.mapdata);
	data.step_count = 0;
	win_width = check_map(map, argv[1]);
	if (win_width == -1)
		return (write (2, "Error\n", 6));
	else if (win_width)
		return (free_str(map->mapdata, map->map_y), write(2, "Error\n", 6));
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	win_width = map->map_x * 32;
	win_height = map->map_y * 32;
	data.win = mlx_new_window(data.mlx, win_width, win_height, "So Long");
	map->coin_count = coin_count(map);
	create_map(&data, map);
	mlx_hook(data.win, 17, 0, win_cl, &data);
	mlx_key_hook(data.win, win_close, &data);
	mlx_loop(data.mlx);
}
