/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:54:00 by apetoyan          #+#    #+#             */
/*   Updated: 2025/09/21 21:15:42 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	check_game_com_ut(t_mapdata **map, int *i, int *j)
{
	int	start;

	if ((*map)->c_map[*i][*j] == '-')
	{
		start = *j;
		while ((*map)->c_map[*i][*j] && (*map)->c_map[*i][*j] == '-')
			(*j)++;
		if (!((*map)->c_map[*i][*j]))
		{
			(*i)++;
			return (1);
		}
		else
		{
			(*j) = start;
			while ((*map)->c_map[*i][*j] && (*map)->c_map[*i][*j] == '-')
			{
				(*map)->c_map[*i][*j] = '1';
				(*j)++;
			}
		}
	}
	return (0);
}

int	check_game_com_ut1(t_mapdata *map, int *i, int *j)
{
	(*i) = 0;
	(*j) = 0;
	while (map->c_map[*i])
	{
		(*j) = -1;
		while (map->c_map[*i][++(*j)])
		{
			if (map->c_map[*i][*j] != '1' && map->c_map[*i][*j] != 'E'
				&& map->c_map[*i][*j] != 'N' && map->c_map[*i][*j] != 'W'
				&& map->c_map[*i][*j] != 'S' && map->c_map[*i][*j] != ' '
				&& map->c_map[*i][*j] != '0' && map->c_map[*i][*j] != '-')
				return (1);
		}
		(*i)++;
	}
	(*i) = 0;
	while (map->c_map[*i])
	{
		if (map->c_map[*i][map->max_row - 1] != '1'
			&& map->c_map[*i][map->max_row - 1] != '-')
			return (1);
		(*i)++;
	}
	return (0);
}

int	my_if_fun(t_mapdata *map, int i, int j)
{
	if ((map->c_map[i][j] == '0' || map->c_map[i][j] == 'N'
			|| map->c_map[i][j] == 'E' || map->c_map[i][j] == 'W'
			|| map->c_map[i][j] == 'S') && map->c_map[i][j + 1]
			&& map->c_map[i + 1][j])
	{
		if (map->c_map[i][j + 1] == '-' || map->c_map[i][j - 1] == '-'
			|| map->c_map[i + 1][j] == '-' || map->c_map[i - 1][j] == '-')
			return (1);
	}
	else if (map->c_map[i][j] == '0')
		return (1);
	return (0);
}

int	check_game_com(t_mapdata *map)
{
	int	i;
	int	j;

	if (check_game_com_ut1(map, &i, &j))
		return (1);
	i = 1;
	while (map->c_map[i + 1])
	{
		j = 1;
		while (map->c_map[i][j])
		{
			if (check_game_com_ut(&map, &i, &j))
			{
				j = 1;
				if (map->c_map[i])
					continue ;
				break ;
			}
			if (my_if_fun(map, i, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
