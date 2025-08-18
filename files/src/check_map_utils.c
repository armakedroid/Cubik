/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <argharag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:09:34 by argharag          #+#    #+#             */
/*   Updated: 2025/04/28 19:53:28 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	check_a(char **map, int a, int b)
{
	int	i;
	int	m;

	i = 0;
	while (i < a)
	{
		m = 0;
		while (m < b)
		{
			if (map[i][m] != '1' && map[i][m] != 'A')
				return (1);
			m++;
		}
		i++;
	}
	return (0);
}

int	check_game_com(char **map, int x, int y)
{
	int	i;

	i = 0;
	if (map[y][x] == '1' || map[y][x] == 'A')
		return (0);
	if ((map[y][x] == '0' || map[y][x] == 'C' || map[y][x] == 'E'
			|| map[y][x] == 'P'))
		map[y][x] = 'A';
	if (x > 0 || y > 0)
	{
		check_game_com(map, x - 1, y);
		check_game_com(map, x + 1, y);
		check_game_com(map, x, y + 1);
		check_game_com(map, x, y - 1);
	}
	return (0);
}

void	find_player(t_mapdata *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_y)
	{
		j = 0;
		while (map->mapdata[i][j])
		{
			if (map->mapdata[i][j] == 'P')
			{
				map->ply_x = j;
				map->ply_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	map_for_check_a(t_mapdata *map, t_s_str	*v)
{
	v->for_c = malloc(sizeof(char *) * map->map_y);
	if (!v->for_c)
		return (1);
	v->a = 0;
	while (map->map_y > v->a)
	{
		v->for_c[v->a] = malloc((sizeof(char) * map->map_x) + 1);
		if (!v->for_c[v->a])
			return (1);
		v->b = 0;
		while (map->map_x > v->b)
		{
			v->for_c[v->a][v->b] = map->mapdata[v->a][v->b];
			v->b++;
		}
		v->for_c[v->a][v->b] = '\0';
		v->a++;
	}
	return (0);
}

int	check_map(t_mapdata *map, char *argv)
{
	t_s_str	v;

	v.i = 0;
	if (check_av(argv))
		return (-1);
	v.count = count_av(argv, &map);
	if (v.count <= 2)
		return (-1);
	map->mapdata = map_create(argv, v.count);
	if (!map->mapdata)
		return (1);
	if ((check_map_size(map->mapdata, v.count))
		|| (check_map_inside(map->mapdata, v.count)))
		return (1);
	find_player(map);
	if (map_for_check_a(map, &v))
		return (free_str(v.for_c, map->map_y), 1);
	if (check_game_com(v.for_c, map->ply_x, map->ply_y))
		return (free_str(v.for_c, map->map_y), 1);
	if (check_a(v.for_c, v.a, v.b))
		return (free_str(v.for_c, map->map_y), 1);
	free_str(v.for_c, map->map_y);
	return (0);
}
