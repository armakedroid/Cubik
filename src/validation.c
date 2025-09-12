/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:12:23 by apetoyan          #+#    #+#             */
/*   Updated: 2025/09/11 22:51:40 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	map_create_help3(t_vars_put *v, t_mapdata **data, int *i)
{
	if (v->tmp[*i][0] == 'F')
		(*data)->f_line = *i;
	else
		(*data)->c_line = *i;
	v->s = 2;
	v->str = (char *)malloc(ft_strlen(v->tmp[*i]) - 2 + 1);
	if (!v->str)
		return (1);
	v->l = 0;
	while (v->tmp[*i][v->s])
	{
		v->str[v->l++] = v->tmp[*i][(v->s)++];
	}
	v->str[v->l] = '\0';
	if (!access(v->str, F_OK))
	{
		my_free(v->str);
		return (1);
	}
	my_free(v->str);
	return (0);
}

int	map_create_help2(t_vars_put *v, t_mapdata **data, int *i)
{
	if (v->tmp[*i][0] == 'N')
		(*data)->no_line = *i;
	else if (v->tmp[*i][0] == 'W')
		(*data)->we_line = *i;
	else if (v->tmp[*i][0] == 'S')
		(*data)->so_line = *i;
	else if (v->tmp[*i][0] == 'E')
		(*data)->ea_line = *i;
	v->s = 3;
	v->str = (char *)malloc(ft_strlen(v->tmp[*i]) - 3 + 1);
	if (!v->str)
		return (1);
	v->l = 0;
	while (v->tmp[*i][v->s])
		v->str[(v->l)++] = v->tmp[*i][v->s++];
	v->str[v->l] = '\0';
	if (!access(v->str, F_OK))
	{
		my_free(v->str);
		return (1);
	}
	my_free(v->str);
	return (0);
}

int	map_create_help1(t_vars_put *v, t_mapdata **data, int *i, int *count)
{
	v->line = get_next_line(v->fd);
	if (!v->line)
	{
		free_str(v->tmp, *count);
		return (1);
	}
	v->tmp[*i] = ft_strtrim(v->line, "\n");
	if (!v->tmp[*i])
		return (1);
	free(v->line);
	if (!ft_strncmp(v->tmp[*i], "NO", 2) || !ft_strncmp(v->tmp[*i], "WE", 2)
		|| !ft_strncmp(v->tmp[*i], "SO", 2) || !ft_strncmp(v->tmp[*i], "EA", 2))
	{
		if (map_create_help2(v, data, i))
			return (1);
	}
	else if (!ft_strncmp(v->tmp[*i], "F", 1) || !ft_strncmp(v->tmp[*i], "C", 1))
	{
		if (map_create_help3(v, data, i))
			return (1);
	}
	return (0);
}

char	**map_create(char *argv, int count, t_mapdata *data)
{
	t_vars_put	vars;
	int			i;

	i = -1;
	vars.str = NULL;
	vars.tmp = (char **)malloc(sizeof(char *) * (count + 1));
	if (!vars.tmp)
		return (NULL);
	vars.fd = open(argv, O_RDONLY);
	if (vars.fd < 0)
		return (free_str(vars.tmp, count), NULL);
	while (++i < count)
	{
		if (map_create_help1(&vars, &data, &i, &count))
			return (NULL);
	}
	vars.tmp[i] = NULL;
	close(vars.fd);
	return (vars.tmp);
}

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

int check_game_com_ut(t_mapdata **map, int *i, int *j)
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

int check_game_com_ut1(t_mapdata *map, int *i, int *j)
{
	i = 0;
	j = 0;
	while (map->c_map[i])
	{
		j = 0;
		while (map->c_map[i][j])
		{
			if (map->c_map[i][j] != '1' && map->c_map[i][j] != 'E'
				&& map->c_map[i][j] != 'N' && map->c_map[i][j] != 'W'
				&& map->c_map[i][j] != 'S' && map->c_map[i][j] != ' '
				&& map->c_map[i][j] != '0' && map->c_map[i][j] != '-')
				return (1);
			j++;
		}
		i++;
	}
	i = 0;
	while (map->c_map[i])
	{
		if (map->c_map[i][map->max_row - 1] != '1' && map->c_map[i][map->max_row
			- 1] != '-')
			return (1);
		i++;
	}
	return (0);
}

int	check_game_com(t_mapdata *map)
{
	int	i;
	int	j;

	if(check_game_com_ut1(map, i, j))
		return (1);
	i = 1;
	while (map->c_map[i + 1])
	{
		j = 1;
		while (map->c_map[i][j])
		{
		if(check_game_com_ut(&map, &i, &j))
			continue;
		if (map->c_map[i][j] == '0')
			{
				if (map->c_map[i][j + 1] == '-' || map->c_map[i][j - 1] == '-'
					|| map->c_map[i + 1][j] == '-' || map->c_map[i
					- 1][j] == '-')
					return (1);
			}
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
	if (find_player(player))
		return (-1);
	if (copy_map1(player))
		return (-1);
	if (check_game_com(player))
		return (-1);
	free_str(player->c_map, 0);
	return (0);
}
