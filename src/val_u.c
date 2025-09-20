/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 21:13:32 by argharag          #+#    #+#             */
/*   Updated: 2025/09/20 21:13:38 by argharag         ###   ########.fr       */
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
