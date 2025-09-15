/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:00:19 by apetoyan          #+#    #+#             */
/*   Updated: 2025/09/08 20:23:03 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void utils(t_create **map, t_mapdata *data)
{
	(*map)->map_x = (int)data->ply_x;
	(*map)->map_y = (int)data->ply_y;
	(*map)->delta_dist_x = fabs(1 / (*map)->ray_dir_x);
	(*map)->delta_dist_y = fabs(1 / (*map)->ray_dir_y);
	if ((*map)->ray_dir_x < 0)
		(*map)->step_x = -1;
	else
		(*map)->step_x = 1;
	if ((*map)->ray_dir_y < 0)
		(*map)->step_y = -1;
	else
		(*map)->step_y = 1;
	if ((*map)->ray_dir_x < 0)
		(*map)->side_dist_x = (data->ply_x - (*map)->map_x) * (*map)->delta_dist_x;
	else
		(*map)->side_dist_x = ((*map)->map_x + 1.0 - data->ply_x) * (*map)->delta_dist_x;
	if ((*map)->ray_dir_y < 0)
		(*map)->side_dist_y = (data->ply_y - (*map)->map_y) * (*map)->delta_dist_y;
	else
		(*map)->side_dist_y = ((*map)->map_y + 1.0 - data->ply_y) * (*map)->delta_dist_y;
}

void utils1(t_create **map, t_mapdata *data)
{
	while (!(*map)->hit)
	{
		if ((*map)->side_dist_x < (*map)->side_dist_y)
		{
			(*map)->side_dist_x += (*map)->delta_dist_x;
			(*map)->map_x += (*map)->step_x;
			(*map)->side = 0;
		}
		else
		{
			(*map)->side_dist_y += (*map)->delta_dist_y;
			(*map)->map_y += (*map)->step_y;
			(*map)->side = 1;
		}
		if ((*map)->map_x < 0 || (*map)->map_x >= data->width || (*map)->map_y < 0 || (*map)->map_y >= data->height)
		{
			(*map)->hit = 1;
			break;
		}
		if (data->original_map[(*map)->map_y][(*map)->map_x] && data->original_map[(*map)->map_y][(*map)->map_x] == '1')
			(*map)->hit = 1;
	}
}

void utils4(t_create **map, t_mapdata *data)
{
	if ((*map)->side == 0)
		(*map)->wall_x = data->ply_y + (*map)->perp_wall_dist * (*map)->ray_dir_y;
	else
		(*map)->wall_x = data->ply_x + (*map)->perp_wall_dist * (*map)->ray_dir_x;
	(*map)->wall_x -= floor((*map)->wall_x);
	(*map)->tex_x = (int)(fmod((*map)->wall_x, 1.0) * (double)data->img_it[(*map)->tex_index]->width);
	if (((*map)->side == 0 && (*map)->ray_dir_x > 0) || ((*map)->side == 1 && (*map)->ray_dir_y < 0))
		(*map)->tex_x = data->img_it[(*map)->tex_index]->width - (*map)->tex_x - 1;
	(*map)->step_tex = 1.0 * data->img_it[(*map)->tex_index]->height / (*map)->line_height;
	(*map)->tex_pos = ((*map)->draw_start - data->height / 2 + (*map)->line_height / 2) * (*map)->step_tex;
	(*map)->tex_pos += (*map)->step_tex;
}

void utils2(t_create **map, t_mapdata *data)
{
	if ((*map)->side == 0)
	{
		if ((*map)->ray_dir_x > 0)
			(*map)->tex_index = 0;
		else
			(*map)->tex_index = 1;
	}
	else
	{
		if ((*map)->ray_dir_y > 0)
			(*map)->tex_index = 2;
		else
			(*map)->tex_index = 3;
	}
	utils4(map, data);
}

void utils3(t_create *map, t_mapdata *data)
{
	map->camera_x = 2.0 * map->x / (double)data->width - 1.0;
	map->ray_dir_x = data->dir_x + data->plane_x * map->camera_x;
	map->ray_dir_y = data->dir_y + data->plane_y * map->camera_x;
	utils(&map, data);
	map->hit = 0;
	utils1(&map, data);
	map->line_height = 0;
	if (map->side == 0)
		map->perp_wall_dist = (map->map_x - data->ply_x + (1 - map->step_x) / 2) / map->ray_dir_x;
	else
		map->perp_wall_dist = (map->map_y - data->ply_y + (1 - map->step_y) / 2) / map->ray_dir_y;
	if (map->perp_wall_dist != 0)
		map->line_height = (int)(data->height / map->perp_wall_dist);
	else
		map->line_height = INT_MAX;
	map->draw_start = -map->line_height / 2 + data->height / 2;
	map->draw_end = map->line_height / 2 + data->height / 2;
	if (map->draw_start < 0)
		map->draw_start = 0;
	if (map->draw_end >= data->height)
		map->draw_end = data->height - 1;
	utils2(&map, data);
	map->y = map->draw_start;
}
