#include "../includes/cube3d.h"
void init(t_mapdata *arg)
{
    arg->move_speed = 0.05;
	arg->press = 0;
	arg->dir_x = 0;
	arg->dir_y = 0;
	arg->ply_x = 0;
	arg->ply_y = 0;
	arg->plane_x = 3;
	arg->plane_y = 3;
	arg->offset_x = 0;
	arg->offset_y = 0;
	arg->key[0] = 0;
	arg->key[1] = 0;
	arg->key[2] = 0;
	arg->key[3] = 0;
	arg->key[4] = 0;
	arg->key[5] = 0;
	arg->key[6] = 0;
}

void	dir_p_ew(t_mapdata *data)
{
	if (data->original_map[(int)data->ply_y][(int)data->ply_x] == 'E')
	{
		data->dir_x = 1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = 0.66;
	}
	else if (data->original_map[(int)data->ply_y][(int)data->ply_x] == 'W')
	{
		data->dir_x = -1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = -0.66;
	}
}

void	dir_ply_init(t_mapdata *data)
{
	if (data->original_map[(int)data->ply_y][(int)data->ply_x] == 'N')
	{
		data->dir_x = 0;
		data->dir_y = -1;
		data->plane_x = 0.66;
		data->plane_y = 0;
	}
	else if (data->original_map[(int)data->ply_y][(int)data->ply_x] == 'S')
	{
		data->dir_x = 0;
		data->dir_y = 1;
		data->plane_x = -0.66;
		data->plane_y = 0;
	}
	else
		dir_p_ew(data);
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
