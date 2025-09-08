#include "../includes/cube3d.h"

void utils(t_create **map, t_mapdata *data)
{
    	(*map)->cameraX = 2.0 * (*map)->x / (double)data->width - 1.0;
		(*map)->rayDirX = data->dir_x + data->plane_x * (*map)->cameraX;
		(*map)->rayDirY = data->dir_y + data->plane_y * (*map)->cameraX;
		(*map)->mapX = (int)data->ply_x;
		(*map)->mapY = (int)data->ply_y;
		(*map)->deltaDistX = fabs(1 / (*map)->rayDirX);
		(*map)->deltaDistY = fabs(1 / (*map)->rayDirY);
		if ((*map)->rayDirX < 0)
			(*map)->stepX = -1;
		else
			(*map)->stepX = 1;
		if ((*map)->rayDirY < 0)
			(*map)->stepY = -1;
		else
			(*map)->stepY = 1;
		if ((*map)->rayDirX < 0)
			(*map)->sideDistX = (data->ply_x - (*map)->mapX) * (*map)->deltaDistX;
		else
			(*map)->sideDistX = ((*map)->mapX + 1.0 - data->ply_x) * (*map)->deltaDistX;
		if ((*map)->rayDirY < 0)
			(*map)->sideDistY = (data->ply_y - (*map)->mapY) * (*map)->deltaDistY;
		else
			(*map)->sideDistY = ((*map)->mapY + 1.0 - data->ply_y) * (*map)->deltaDistY;
        (*map)->hit = 0;
}

void utils1(t_create **map, t_mapdata *data)
{
    	while (!(*map)->hit)
		{
			if ((*map)->sideDistX < (*map)->sideDistY)
			{
				(*map)->sideDistX += (*map)->deltaDistX;
				(*map)->mapX += (*map)->stepX;
				(*map)->side = 0;
			}
			else
			{
				(*map)->sideDistY += (*map)->deltaDistY;
				(*map)->mapY += (*map)->stepY;
				(*map)->side = 1;
			}
			if ((*map)->mapX < 0 || (*map)->mapX >= data->width || (*map)->mapY < 0
				|| (*map)->mapY >= data->height)
			{
				(*map)->hit = 1;
                break ;
			}
			if (data->original_map[(*map)->mapY][(*map)->mapX]
				&& data->original_map[(*map)->mapY][(*map)->mapX] == '1')
				(*map)->hit = 1;
		}
}

void utils2(t_create **map, t_mapdata *data)
{
    		if ((*map)->side == 0)
		{
			if ((*map)->rayDirX > 0)
				(*map)->texIndex = 0;
			else
				(*map)->texIndex = 1;
		}
		else
		{
			if ((*map)->rayDirY > 0)
				(*map)->texIndex = 2;
			else
				(*map)->texIndex = 3;
		}
		if ((*map)->side == 0)
			(*map)->wallX = data->ply_y + (*map)->perpWallDist * (*map)->rayDirY;
		else
			(*map)->wallX = data->ply_x + (*map)->perpWallDist * (*map)->rayDirX;
		(*map)->wallX -= floor((*map)->wallX);
		(*map)->texX = (int)((*map)->wallX * (double)data->img_it[(*map)->texIndex]->width);
		if (((*map)->side == 0 && (*map)->rayDirX > 0) || ((*map)->side == 1 && (*map)->rayDirY < 0))
			(*map)->texX = data->img_it[(*map)->texIndex]->width - (*map)->texX - 1;
		(*map)->stepTex = 1.0 * data->img_it[(*map)->texIndex]->height / (*map)->lineHeight;
        (*map)->texPos = ((*map)->drawStart - data->height / 2 + (*map)->lineHeight / 2) * (*map)->stepTex;
}

void utils3(t_create *map, t_mapdata *data)
{
        utils(&map, data);
		utils1(&map, data);
		map->lineHeight = 0;
		if (map->side == 0)
			map->perpWallDist = (map->mapX - data->ply_x + (1 - map->stepX) / 2) / map->rayDirX;
		else
			map->perpWallDist = (map->mapY - data->ply_y + (1 - map->stepY) / 2) / map->rayDirY;
		if (map->perpWallDist != 0)
			map->lineHeight = (int)(data->height / map->perpWallDist);
		else
			map->lineHeight = INT_MAX;
		map->drawStart = -map->lineHeight / 2 + data->height / 2;
		map->drawEnd = map->lineHeight / 2 + data->height / 2;
		if (map->drawStart < 0)
			map->drawStart = 0;
		if (map->drawEnd >= data->height)
			map->drawEnd = data->height - 1;
		utils2(&map, data);
		map->y = map->drawStart;
}

void	create_map(t_mapdata *data)
{
	t_create map;

	map.x = 0;
	while (map.x < data->width)
	{
        utils3(&map, data);
		while (map.y < map.drawEnd)
		{
			map.texY = (int)map.texPos & (data->img_it[map.texIndex]->height - 1);
			map.texPos += map.stepTex;
			map.color = get_pixel_color(data->img_it[map.texIndex], map.texX, map.texY);
			if (map.side == 1)
				map.color = map.color / 2;
			put_pixel_color(&data->screen, map.x, map.y, map.color);
			map.y++;
		}
		if (map.x <= data->width && map.y <= data->height)
			draw_ceil_floor(&(data->screen), data, map.x, map.drawStart, map.drawEnd);
		map.x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->screen.img,
		data->offset_x, data->offset_y);
}
