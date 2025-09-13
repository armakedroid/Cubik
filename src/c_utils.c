/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:52:35 by apetoyan          #+#    #+#             */
/*   Updated: 2025/09/13 21:34:03 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	if_utils(t_mapdata **map, int *i, int *j, int *start)
{
	*start = *j;
	if (find_end(*map, *i, *j, 1) || find_end(*map, *i, *j, 2) || find_end(*map,
			*i, *j, 3) || find_end(*map, *i, *j, 4))
	{
		*j = *start + 1;
		return (1);
	}
	else
	{
		*j = *start;
		while ((*map)->c_map[*i][*j] && (*map)->c_map[*i][*j] == '-')
		{
			(*map)->c_map[*i][*j] = '0';
			(*j)++;
		}
	}
	return (0);
}

void	find_spaces(t_mapdata *map)
{
	int	i;
	int	j;
	int	start;

	i = 1;
	while (map->c_map[i + 1])
	{
		j = 1;
		while (map->c_map[i][j])
		{
			if (map->c_map[i][j] == '-')
			{
				if (if_utils(&map, &i, &j, &start))
					continue ;
			}
			else
				j++;
		}
		i++;
	}
}

int	copy_map1_ut(t_ut_ut *ut, t_mapdata *map)
{
	while (map->mapdata[ut->i])
	{
		map->c_map[ut->j] = ft_calloc(sizeof(char), (map->max_row + 1));
		if (!map->c_map[ut->j])
			return (1);
		ut->a = -1;
		while (++(ut->a) < map->max_row)
		{
			if (map->mapdata[ut->i])
			{
				if ((int)ft_strlen(map->mapdata[ut->i]) <= ut->a)
					map->c_map[ut->j][ut->a] = '-';
				if (map->mapdata[ut->i][ut->a]
					&& map->mapdata[ut->i][ut->a] != ' '
					&& map->mapdata[ut->i][ut->a] != '\n')
					map->c_map[ut->j][ut->a] = map->mapdata[ut->i][ut->a];
				else
					map->c_map[ut->j][ut->a] = '-';
			}
		}
		map->c_map[ut->j][ut->a] = '\0';
		ut->j++;
		ut->i++;
	}
	return (0);
}

int	copy_map1(t_mapdata *map)
{
	t_ut_ut	ut;

	ut.w = 0;
	ut.h = 0;
	map->max_row = 0;
	while (map->original_map[ut.w])
	{
		ut.h = ft_strlen(map->original_map[ut.w]);
		if (ut.h > map->max_row)
			map->max_row = ut.h;
		ut.w++;
	}
	ut.rows = 0;
	while (map->mapdata[ut.rows])
		ut.rows++;
	map->c_map = ft_calloc(sizeof(char *), (ut.rows - 8 + 1));
	if (!map->c_map)
		return (1);
	ut.i = 9;
	ut.j = 0;
	if (copy_map1_ut(&ut, map))
		return (1);
	map->c_map[ut.j] = NULL;
	find_spaces(map);
	return (0);
}
