/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:12:14 by apetoyan          #+#    #+#             */
/*   Updated: 2025/09/08 20:12:15 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	go_forward(t_mapdata *arg)
{
	double	new_x;
	double	new_y;
	char	c;

	new_y = arg->ply_y + (arg->dir_y * arg->move_speed);
	new_x = arg->ply_x + (arg->dir_x * arg->move_speed);
	if ((int)new_x <= 0 || (int)new_y <= 0)
		return ;
	c = arg->original_map[(int)new_y][(int)new_x];
	if (c == '0' || c == arg->ply_symbol || c == ' ')
	{
		arg->ply_x = new_x;
		arg->ply_y = new_y;
	}
	return ;
}

void	go_back(t_mapdata *arg)
{
	double	new_x;
	double	new_y;
	char	c;

	new_y = arg->ply_y - (arg->dir_y * arg->move_speed);
	new_x = arg->ply_x - (arg->dir_x * arg->move_speed);
	if ((int)new_x <= 0 || (int)new_y <= 0)
		return ;
	c = arg->original_map[(int)new_y][(int)new_x];
	if (c == '0' || c == arg->ply_symbol || c == ' ')
	{
		arg->ply_x = new_x;
		arg->ply_y = new_y;
	}
	return ;
}

void	go_left(t_mapdata *arg)
{
	double	new_x;
	double	new_y;
	char	c;

	new_y = arg->ply_y - (arg->plane_y * arg->move_speed);
	new_x = arg->ply_x - (arg->plane_x * arg->move_speed);
	if ((int)new_x <= 0 || (int)new_y <= 0)
		return ;
	c = arg->original_map[(int)new_y][(int)new_x];
	if (c == '0' || c == arg->ply_symbol || c == ' ')
	{
		arg->ply_x = new_x;
		arg->ply_y = new_y;
	}
	return ;
}

void	go_right(t_mapdata *arg)
{
	double	new_x;
	double	new_y;
	char	c;

	new_y = arg->ply_y + (arg->plane_y * arg->move_speed);
	new_x = arg->ply_x + (arg->plane_x * arg->move_speed);
	if ((int)new_x <= 0 || (int)new_y <= 0)
		return ;
	c = arg->original_map[(int)new_y][(int)new_x];
	if (c == '0' || c == arg->ply_symbol || c == ' ')
	{
		arg->ply_x = new_x;
		arg->ply_y = new_y;
	}
	return ;
}

void	arg_mlx(t_mapdata *arg)
{
	arg->width = 1920;
	arg->height = 1080;
	arg->win = mlx_new_window(arg->mlx, arg->width, arg->height, "Cube3D");
	arg->screen.width = arg->width;
	arg->screen.height = arg->height;
	arg->screen.img = mlx_new_image(arg->mlx, arg->screen.width,
			arg->screen.height);
	arg->screen.addr = mlx_get_data_addr(arg->screen.img,
			&(arg->screen.bits_per_pixel), &(arg->screen.line_length),
			&(arg->screen.endian));
}
