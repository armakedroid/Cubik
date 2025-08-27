#include "../includes/cube3d.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putstr_fd(ft_strjoin(map[i], "\n"), 1);
		i++;
	}
}

int	check_av(char *argv)
{
	int	i;

	i = ft_strlen(argv) - 4;
	if (i < 1)
		return (1);
	if (ft_strncmp((argv + i), ".cub", 4) != 0)
		return (1);
	return (0);
}

int	count_av(char *argv, t_mapdata **map)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	fd = open(argv, O_RDONLY);
	tmp = get_next_line(fd);
	if (!tmp)
		return (0);
	(*map)->map_x = ft_strlen(tmp) - 1;
	while (tmp)
	{
		free(tmp);
		i++;
		tmp = get_next_line(fd);
	}
	close(fd);
	(*map)->map_y = i;
	return (i);
}

char	**map_create(char *argv, int count, t_mapdata *data)
{
	int		i;
	int		fd;
	char	**tmp;
	char	*line;

	// char	*str;
	// int		s;
	// int		l;
	i = -1;
	// l = 0;
	// str = NULL;
	tmp = (char **)malloc(sizeof(char *) * count);
	if (!tmp)
		return (NULL);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (free_str(tmp, count), NULL);
	while (++i < count)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free_str(tmp, count);
			return (NULL);
		}
		tmp[i] = ft_strtrim(line, "\n");
		free(line);
		if (!ft_strncmp(tmp[i], "NO", 2) || !ft_strncmp(tmp[i], "WE", 2)
			|| !ft_strncmp(tmp[i], "SO", 2) || !ft_strncmp(tmp[i], "EA", 2))
		{
			if (tmp[i][0] == 'N')
				data->no_line = i;
			else if (tmp[i][0] == 'W')
				data->we_line = i;
			else if (tmp[i][0] == 'S')
				data->so_line = i;
			else if (tmp[i][0] == 'E')
				data->ea_line = i;
			// s = 3;
			// while (tmp[i][s])
			// 	str[l++] = tmp[i][s++];
			// if (!access(str, F_OK))
			// 	return (NULL);
		}
		else if (!ft_strncmp(tmp[i], "F", 1) || !ft_strncmp(tmp[i], "C", 1))
		{
			if (tmp[i][0] == 'F')
				data->f_line = i;
			else
				data->c_line = i;
			// s = 2;
			// while (tmp[i][s])
			// 	str[l++] = tmp[i][s++];
			// if (!access(str, F_OK))
			// 	return (NULL);
		}
	}
	tmp[i] = NULL;
	close(fd);
	return (tmp);
}

int	find_player(t_mapdata *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_y)
	{
		j = 0;
		while (map->original_map[i][j])
		{
			if (map->original_map[i][j] == 'N' || map->original_map[i][j] == 'W'
				|| map->original_map[i][j] == 'S'
				|| map->original_map[i][j] == 'E')
			{
				map->ply_x = j;
				map->ply_y = i;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
int	check_game_com(t_mapdata *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	print_map(map->c_map);
	while (map->c_map[i])
	{
		printf("a\n");
		while (map->c_map[i])
		{
			if (map->c_map[i][j] != '1' || map->c_map[i][j] != 'E'
				|| map->c_map[i][j] != 'N' || map->c_map[i][j] != 'W'
				|| map->c_map[i][j] != 'S' || map->c_map[i][j] != ' ')
				return (1);
			j++;
		}
		i++;
	}
	i = 0;
	while (map->c_map[i])
	{
		if (map->c_map[i][map->max_row - 1] != '1' || map->c_map[i][map->max_row
			- 1] != 'W')
			return (1);
		i++;
	}
	i = 1;
	while (map->c_map[i + 1])
	{
		j = 1;
		while (map->c_map[i][j])
		{
			if (map->c_map[i][j] == 0)
			{
				if (map->c_map[i][j + 1] == 'W' || map->c_map[i][j + 1] == ' '
					|| map->c_map[i][j - 1] == 'W' || map->c_map[i][j
					- 1] == ' ' || map->c_map[i + 1][j] == 'W' || map->c_map[i
					+ 1][j] == ' ' || map->c_map[i - 1][j] == 'W'
					|| map->c_map[i - 1][j] == ' ')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	all_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validation(char *argv, t_mapdata *player)
{
	int count;

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
	if (find_player(player))
		return (-1);
	if (copy_map1(player))
		return (-1);
	print_map(player->c_map);
	// if (check_game_com(player))
		// return (-1);
	// if (all_check(player->c_map))
	//	return (-1);
	// print_map(player->original_map);
	// free_str(player->c_map, 0);
	return (0);
}