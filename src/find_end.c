/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:58:53 by apetoyan          #+#    #+#             */
/*   Updated: 2025/09/13 16:59:05 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	find_end_1(t_mapdata *map, int *i, int *j, size_t *len)
{
	while (map->c_map[*i])
	{
		*len = ft_strlen(map->c_map[*i]);
		if ((size_t)(*j) >= *len || map->c_map[*i][*j] != '-')
			break ;
		(*j)++;
	}
}

void	find_end_2(t_mapdata *map, int *i, int *j, size_t *len)
{
	while (map->c_map[*i] && *j >= 0)
	{
		*len = ft_strlen(map->c_map[*i]);
		if ((size_t)(*j) >= *len || map->c_map[*i][*j] != '-')
			break ;
		(*j)--;
	}
}

void	find_end_3(t_mapdata *map, int *i, int *j, size_t *len)
{
	while (*i < map->map_y && map->c_map[*i])
	{
		*len = ft_strlen(map->c_map[*i]);
		if ((size_t)(*j) >= *len || map->c_map[*i][*j] != '-')
			break ;
		(*i)++;
	}
}

void	find_end_4(t_mapdata *map, int *i, int *j, size_t *len)
{
	while (*i >= 0 && map->c_map[*i])
	{
		*len = ft_strlen(map->c_map[*i]);
		if ((size_t)(*j) >= *len || map->c_map[*i][*j] != '-')
			break ;
		(*i)--;
	}
}

int	find_end(t_mapdata *map, int i, int j, int k)
{
	size_t	len;

	if (k == 1)
		find_end_1(map, &i, &j, &len);
	else if (k == 2)
		find_end_2(map, &i, &j, &len);
	else if (k == 3)
		find_end_3(map, &i, &j, &len);
	else if (k == 4)
		find_end_4(map, &i, &j, &len);
	if (i < 0 || i >= map->map_y || !map->c_map[i])
		return (1);
	len = ft_strlen(map->c_map[i]);
	if (j < 0 || (size_t)j >= len)
		return (1);
	return (0);
}
