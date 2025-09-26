/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:12:23 by apetoyan          #+#    #+#             */
/*   Updated: 2025/09/26 19:52:55 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	find_player(t_mapdata *map)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (map->original_map[++i])
	{
		j = -1;
		while (map->original_map[i][++j])
		{
			if (map->original_map[i][j] == 'N' || map->original_map[i][j] == 'W'
				|| map->original_map[i][j] == 'S'
				|| map->original_map[i][j] == 'E')
			{
				map->ply_x = (double)j;
				map->ply_y = (double)i;
				map->ply_symbol = map->original_map[i][j];
				count++;
			}
		}
	}
	if (count == 1)
		return (0);
	return (1);
}

int	check_wall_cf(t_mapdata *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->c_map[i])
	{
		j = 0;
		if (i == 0 || !map->c_map[i + 1])
		{
			while (map->c_map[i][j])
			{
				if (map->c_map[i][j] != '1' && map->c_map[i][j] != ' '
					&& map->c_map[i][j] != '-')
					return (1);
				j++;
			}
		}
		i++;
	}
	return (0);
}

int	check_wall_se(t_mapdata *map)
{
	int	i;
	int	j;

	i = 1;
	while (map->c_map[i + 1])
	{
		j = 0;
		while (map->c_map[i][j] && map->c_map[i][j] == '-')
			j++;
		if (map->c_map[i][j] != '1')
			return (1);
		while (map->c_map[i][j + 1] && map->c_map[i][j + 1] != '-')
			j++;
		if (map->c_map[i][j] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_symb(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' '
				&& map[i][j] != 'N' && map[i][j] != 'E' && map[i][j] != 'W'
				&& map[i][j] != 'S')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validation(char *argv, t_mapdata *player)
{
	int	count;

	if (check_av(argv))
		return (-1);
	count = count_av(argv, &player);
	if (!count)
		return (-1);
	player->mapdata = map_create(argv, count, player);
	if (!player->mapdata)
		return (-1);
	if (copy_map(player))
		return (-1);
	if (find_player(player) || check_any_cases(player)
		|| check_symb(player->original_map))
		return (-1);
	if (copy_map1(player))
		return (-1);
	if (check_game_com(player) || check_rgb(player) || check_wall_cf(player)
		|| check_wall_se(player))
	{
		free_str(player->c_map, 0);
		return (-1);
	}
	free_str(player->c_map, 0);
	return (0);
}
