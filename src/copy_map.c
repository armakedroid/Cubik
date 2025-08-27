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

int	copy_map1(t_mapdata *map)
{
	int	i;
	int	j;
	int	a;
	int	rows;
	int	w = 0;
	int h = 0;
	map->max_row = 0;
	while (map->original_map[w])
	{
		h = ft_strlen(map->original_map[w]);
		if (h  > map->max_row)
			map->max_row = h;
		w++;
	}
	rows = 0;
	while (map->mapdata[rows])
		rows++;
	map->c_map = (char **)malloc(sizeof(char *) * (rows - 8 + 1));
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
			if (map->mapdata[i][a] && map->mapdata[i][a] != ' ' && map->mapdata[i][a] != '\n')
				map->c_map[j][a] = map->mapdata[i][a];
			else
				map->c_map[j][a] = '-';
			a++;
		}
		map->c_map[j][a] = '\0';
		j++;
		i++;
	}
	map->c_map[j] = NULL;
	return (0);
}

