/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:12:23 by apetoyan          #+#    #+#             */
/*   Updated: 2025/09/13 21:47:39 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putstr_fd(ft_strjoin(map[i], "\n"), 1);
		i++;
	}
}

int check_av(char *argv)
{
	int i;

	i = ft_strlen(argv) - 4;
	if (i < 1)
		return (1);
	if (ft_strncmp((argv + i), ".cub", 4) != 0)
		return (1);
	return (0);
}

int count_av(char *argv, t_mapdata **map)
{
	int i;
	int fd;
	char *tmp;

	i = 0;
	fd = open(argv, O_RDONLY);
	tmp = get_next_line(fd);
	if (!tmp || !*tmp || tmp[0] == ' ')
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

int find_player(t_mapdata *map)
{
	int i;
	int j;
	int count;

	i = -1;
	count = 0;
	while (map->original_map[++i])
	{
		j = -1;
		while (map->original_map[i][++j])
		{
			if (map->original_map[i][j] == 'N' || map->original_map[i][j] == 'W' || map->original_map[i][j] == 'S' || map->original_map[i][j] == 'E')
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

int validation(char *argv, t_mapdata *player)
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
	if (find_player(player) || check_any_cases(player))
		return (-1);
	if (copy_map1(player))
		return (-1);
	if (check_game_com(player) || check_rgb(player))
	{
		free_str(player->c_map, 0);
		return (-1);
	}
	free_str(player->c_map, 0);
	return (0);
}
