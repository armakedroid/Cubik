/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argharag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:08:27 by argharag          #+#    #+#             */
/*   Updated: 2025/09/14 15:08:28 by argharag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	check_rgb(t_mapdata *player)
{
	int	i;

	i = 0;
	while (player->mapdata[i])
	{
		if (player->mapdata[i][0] != 'F' && player->mapdata[i][0] != 'C')
		{
			i++;
			continue ;
		}
		if ((player->mapdata[i][0] == 'F' && player->mapdata[i][1]
				&& player->mapdata[i][1] != ' ')
			|| (player->mapdata[i][0] == 'C' && player->mapdata[i][1]
				&& player->mapdata[i][1] != ' '))
			return (-1);
		if (str_to_rgb(player->mapdata[i] + 2) == (unsigned int)INT_MAX
			+ (INT_MAX / 2) + 1)
			return (-1);
		i++;
	}
	return (0);
}

int	check_var_values(char **map, char *item)
{
	int				i;
	unsigned int	len;
	int				count;
	char			*str;

	i = 0;
	count = 0;
	len = ft_strlen(item);
	while (map[i])
	{
		str = ft_strchr(map[i], item[0]);
		if (!str)
		{
			i++;
			continue ;
		}
		if (ft_strlen(str) > len)
			count++;
		i++;
	}
	return (count);
}

int	check_more_val(char **map, char *item)
{
	int				i;
	int				count;
	unsigned int	len;
	int				cmp;

	i = 0;
	count = 0;
	len = ft_strlen(item);
	while (map[i])
	{
		cmp = ft_strncmp(map[i], item, len);
		if (!cmp && map[i][ft_strlen(item)] == ' ')
			count++;
		i++;
	}
	return (count);
}

int	check_any_cases(t_mapdata *player)
{
	char	**str;
	int		i;

	i = 0;
	str = (char *[]){"NO", "SO", "WE", "EA", "F", "C", NULL};
	while (str[i])
	{
		if (check_more_val(player->mapdata, str[i]) != 1)
			return (1);
		if (!check_var_values(player->mapdata, str[i]))
			return (1);
		i++;
	}
	return (0);
}
