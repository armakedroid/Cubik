#include "../incudes/cube3d.h"

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

char	**map_create(char *argv, int count)
{
    int		i;
    int		fd;
    char	**tmp;
    char	*line;
    char    *str;
    int     s;
    int     l;

    i = -1;
    l = 0;
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
        if (!ft_strncmp(tmp[i],"NO", 2) && !ft_strncmp(tmp[i],"WE", 2)
            && !ft_strncmp(tmp[i],"SO", 2) && !ft_strncmp(tmp[i],"EA", 2))
            {
                s = 3;
                while(tmp[s])
                    str[l++] == tmp[s++];
                if (!access(str, F_OK))
                    return (NULL);
            }
        else if (!ft_strncmp(tmp[i],"F", 1) && !ft_strncmp(tmp[i],"C", 1))
            {
                s = 2;
                while(tmp[s])
                    str[l++] == tmp[s++];
                if (!access(str, F_OK))
                    return (NULL);
            }
    }
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
                    || map->original_map[i][j] == 'S' || map->original_map[i][j] == 'E')
			{
				map->ply_x = j;
				map->ply_y = i;
				return (0);
			}
			j++;
		}
		i++;
	}
    return(1);
}

int validation(char *argv, t_mapdata *player)
{
    int count;

    if (check_av(argv))
        return(-1);
    count = count_av(argv, player);
    if (!count)
        return (-1);
    player->mapdata = map_create(argv, count);
    if (!player->mapdata)
		return (-1);
    if (find_player(player))
        return (-1);
}