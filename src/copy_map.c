/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:09:33 by apetoyan          #+#    #+#             */
/*   Updated: 2025/09/08 20:09:34 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	copy_map(t_mapdata *map)
{
	int	i;
	int	j;
	int	a;
	int	rows;

	rows = 0;
	while (map->mapdata[rows])
		rows++;
	map->original_map = (char **)malloc(sizeof(char *) * (rows - 8 + 1));
	if (!map->original_map)
		return (1);
	i = 9;
	j = 0;
	while (map->mapdata[i])
	{
		a = 0;
		while (map->mapdata[i][a])
			a++;
		map->original_map[j] = (char *)malloc(sizeof(char) * (a + 1));
		if (!map->original_map[j])
			return (1);
		a = 0;
		while (map->mapdata[i][a])
		{
			map->original_map[j][a] = map->mapdata[i][a];
			a++;
		}
		map->original_map[j][a] = '\0';
		j++;
		i++;
	}
	map->original_map[j] = NULL;
	return (0);
}

int	find_end(t_mapdata *map, int i, int j, int k)
{
	size_t	len;

	if (k == 1)
	{
		while (map->c_map[i])
		{
			len = ft_strlen(map->c_map[i]);
			if ((size_t)j >= len || map->c_map[i][j] != '-')
				break ;
			j++;
		}
	}
	else if (k == 2)
	{
		while (map->c_map[i] && j >= 0)
		{
			len = ft_strlen(map->c_map[i]);
			if ((size_t)j >= len || map->c_map[i][j] != '-')
				break ;
			j--;
		}
	}
	else if (k == 3)
	{
		while (i < map->map_y && map->c_map[i])
		{
			len = ft_strlen(map->c_map[i]);
			if ((size_t)j >= len || map->c_map[i][j] != '-')
				break ;
			i++;
		}
	}
	else if (k == 4)
	{
		while (i >= 0 && map->c_map[i])
		{
			len = ft_strlen(map->c_map[i]);
			if ((size_t)j >= len || map->c_map[i][j] != '-')
				break ;
			i--;
		}
	}
	if (i < 0 || i >= map->map_y || !map->c_map[i])
		return (1);
	len = ft_strlen(map->c_map[i]);
	if (j < 0 || (size_t)j >= len)
		return (1);
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
				start = j;
				if (find_end(map, i, j, 1) || find_end(map, i, j, 2)
					|| find_end(map, i, j, 3) || find_end(map, i, j, 4))
				{
					j = start + 1;
					continue ;
				}
				else
				{
					j = start;
					while (map->c_map[i][j] && map->c_map[i][j] == '-')
					{
						map->c_map[i][j] = '0';
						j++;
					}
				}
			}
			else
				j++;
		}
		i++;
	}
}

int	copy_map1(t_mapdata *map)
{
	int	i;
	int	j;
	int	a;
	int	rows;
	int	w;
	int	h;

	w = 0;
	h = 0;
	map->max_row = 0;
	while (map->original_map[w])
	{
		h = ft_strlen(map->original_map[w]);
		if (h > map->max_row)
			map->max_row = h;
		w++;
	}
	rows = 0;
	while (map->mapdata[rows])
		rows++;
	map->c_map = ft_calloc(sizeof(char *), (rows - 8 + 1));
	if (!map->c_map)
		return (1);
	i = 9;
	j = 0;
	while (map->mapdata[i])
	{
		map->c_map[j] = ft_calloc(sizeof(char), (map->max_row + 1));
		if (!map->c_map[j])
			return (1);
		a = 0;
		while (a < map->max_row)
		{
			if (map->mapdata[i])
			{
				if ((int)ft_strlen(map->mapdata[i]) <= a)
					map->c_map[j][a] = '-';
				else if (map->mapdata[i][a] && map->mapdata[i][a] != ' '
					&& map->mapdata[i][a] != '\n')
					map->c_map[j][a] = map->mapdata[i][a];
				else
					map->c_map[j][a] = '-';
			}
			a++;
		}
		map->c_map[j][a] = '\0';
		j++;
		i++;
	}
	map->c_map[j] = NULL;
	find_spaces(map);
	return (0);
}
