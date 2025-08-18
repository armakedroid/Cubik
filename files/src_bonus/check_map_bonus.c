/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <argharag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:09:39 by argharag          #+#    #+#             */
/*   Updated: 2025/04/28 20:48:43 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

int	check_av(char *argv)
{
	int	i;

	i = ft_strlen(argv) - 4;
	if (i < 1)
		return (1);
	if (ft_strncmp((argv + i), ".ber", 4) != 0)
		return (1);
	return (0);
}

char	**map_create(char *argv, int count)
{
	int		i;
	int		fd;
	char	**tmp;
	char	*line;

	i = -1;
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
	}
	close(fd);
	return (tmp);
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
		return (1);
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

int	check_map_size(char **map, int count)
{
	int	i;
	int	m;
	int	l;
	int	b;

	l = 0;
	m = 0;
	i = 0;
	while (map[0][m])
		m++;
	while (l < count)
	{
		b = 0;
		while (map[i][b])
			b++;
		if (m != b)
			return (1);
		l++;
		i++;
	}
	return (0);
}

int	check_all_s(char **map, int count)
{
	t_s_str	v;

	v.i = -1;
	v.count_e = 0;
	v.count_p = 0;
	v.count_c = 0;
	while (++v.i < count && B[v.i])
	{
		v.m = -1;
		while (B[v.i][++v.m] != '\0')
		{
			if (B[v.i][v.m] == 'E')
				v.count_e++;
			else if (B[v.i][v.m] == 'P')
				v.count_p++;
			else if (B[v.i][v.m] == 'C')
				v.count_c++;
			if (B[v.i][v.m] != '1' && B[v.i][v.m] != '0' && B[v.i][v.m] != 'C'
				&& B[v.i][v.m] != 'E' && B[v.i][v.m] != 'P'
				&& B[v.i][v.m] != 'X')
				return (1);
		}
	}
	return (v.count_e != 1 || v.count_p != 1 || !v.count_c);
}
