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
	if (c == '0' || c == arg->ply_symbol)
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
	if (c == '0' || c == arg->ply_symbol)
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
	if (c == '0' || c == arg->ply_symbol)
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
	if (c == '0' || c == arg->ply_symbol)
	{
		arg->ply_x = new_x;
		arg->ply_y = new_y;
	}
	return ;
}

void	rot_left(t_mapdata *data, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plane_x;
	data->dir_x = data->dir_x * cos(rot_speed) - data->dir_y * sin(rot_speed);
	data->dir_y = old_dir_x * sin(rot_speed) + data->dir_y * cos(rot_speed);
	data->plane_x = data->plane_x * cos(rot_speed) - data->plane_y
		* sin(rot_speed);
	data->plane_y = old_plane_x * sin(rot_speed) + data->plane_y
		* cos(rot_speed);
}

void	rot_right(t_mapdata *data, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plane_x;
	data->dir_x = data->dir_x * cos(rot_speed) - data->dir_y * sin(rot_speed);
	data->dir_y = old_dir_x * sin(rot_speed) + data->dir_y * cos(rot_speed);
	data->plane_x = data->plane_x * cos(rot_speed) - data->plane_y
		* sin(rot_speed);
	data->plane_y = old_plane_x * sin(rot_speed) + data->plane_y
		* cos(rot_speed);
}
