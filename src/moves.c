#include "../includes/cube3d.h"

void	go_forward(t_mapdata *arg)
{
	(void) arg;
	return ;
}

void	go_back(t_mapdata *arg)
{
	(void) arg;
	return ;
}

void	go_left(t_mapdata *arg)
{
	(void) arg;
	return ;
}

void	go_right(t_mapdata *arg)
{
	(void) arg;
	return ;
}

void	rot_left(t_mapdata *data, double rotSpeed)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = data->dirX;
	oldPlaneX = data->planeX;
	data->dirX = data->dirX * cos(rotSpeed) - data->dirY * sin(rotSpeed);
	data->dirY = oldDirX * sin(rotSpeed) + data->dirY * cos(rotSpeed);
	data->planeX = data->planeX * cos(rotSpeed) - data->planeY * sin(rotSpeed);
	data->planeY = oldPlaneX * sin(rotSpeed) + data->planeY * cos(rotSpeed);
}

void	rot_right(t_mapdata *data, double rotSpeed)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = data->dirX;
	oldPlaneX = data->planeX;
	data->dirX = data->dirX * cos(rotSpeed) - data->dirY * sin(rotSpeed);
	data->dirY = oldDirX * sin(rotSpeed) + data->dirY * cos(rotSpeed);
	data->planeX = data->planeX * cos(rotSpeed) - data->planeY * sin(rotSpeed);
	data->planeY = oldPlaneX * sin(rotSpeed) + data->planeY * cos(rotSpeed);
}
