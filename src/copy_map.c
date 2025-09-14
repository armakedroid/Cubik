/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:09:33 by apetoyan          #+#    #+#             */
/*   Updated: 2025/09/13 21:34:59 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	copy_map_help(t_mapdata **map, int *i, int *j, int *a)
{
	*a = 0;
	while ((*map)->mapdata[*i][*a])
		(*a)++;
	(*map)->original_map[*j] = (char *)malloc(sizeof(char) * (*a + 1));
	if (!(*map)->original_map[*j])
		return (1);
	*a = 0;
	while ((*map)->mapdata[*i][*a])
	{
		(*map)->original_map[*j][*a] = (*map)->mapdata[*i][*a];
		(*a)++;
	}
	(*map)->original_map[*j][*a] = '\0';
	(*j)++;
	(*i)++;
	return (0);
}

int	copy_map(t_mapdata *map)
{
	int	i;
	int	j;
	int	a;
	int	rows;

	rows = 0;
	i = 0;
	j = 0;
	while (map->mapdata[rows])
		rows++;
	if (rows < 8)
		return (1);
	while (map->mapdata[i][j] != '1')
		i++;
	map->original_map = (char **)malloc(sizeof(char *) * (rows - i + 1));
	if (!map->original_map)
		return (1);
	while (map->mapdata[i])
	{	map->original_map = (char **)malloc(sizeof(char *) * (rows - i + 1));

		if (copy_map_help(&map, &i, &j, &a))
			return (1);
	}
	map->original_map[j] = NULL;
	return (0);
}
