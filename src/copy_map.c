/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:09:33 by apetoyan          #+#    #+#             */
/*   Updated: 2025/09/21 21:21:17 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	copy_map_help2(t_mapdata **map, t_ut_ut *vars)
{
	while ((*map)->mapdata[vars->rows])
		(vars->rows)++;
	if (vars->rows < 8)
		return (1);
	while ((*map)->mapdata[vars->i])
	{
		if ((*map)->mapdata[vars->i][vars->j] == ' '
			|| (*map)->mapdata[vars->i][vars->j] == '1')
			break ;
		(vars->i)++;
	}
	(*map)->map_col = vars->i - 1;
	vars->w = vars->rows - 1;
	return (0);
}

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
	t_ut_ut	vars;

	vars.rows = 0;
	vars.i = 0;
	vars.j = 0;
	if (copy_map_help2(&map, &vars))
		return (1);
	while (map->mapdata[vars.w])
	{
		if ((map->mapdata[vars.w]) && map->mapdata[vars.w][0])
			break ;
		(vars.w)--;
	}
	if (vars.w == vars.rows - 2)
		return (1);
	map->original_map = ft_calloc(sizeof(char *), (vars.w - vars.i + 1));
	if (!map->original_map)
		return (1);
	while (vars.i < vars.w)
	{
		if (copy_map_help(&map, &(vars.i), &(vars.j), &(vars.a)))
			return (1);
	}
	map->original_map[vars.j] = NULL;
	return (0);
}
