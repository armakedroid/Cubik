/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:53:20 by apetoyan          #+#    #+#             */
/*   Updated: 2025/09/21 20:41:58 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	map_create_help3(t_vars_put *v, t_mapdata **data, int *i)
{
	if (!(v->tmp[*i][1]))
		return (1);
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
	if (!(v->tmp[*i][2]))
		return (1);
	v->str = (char *)malloc(ft_strlen(v->tmp[*i]) - 3 + 1);
	if (!v->str)
		return (1);
	v->l = 0;
	while (v->tmp[*i][v->s])
		v->str[(v->l)++] = v->tmp[*i][v->s++];
	v->str[v->l] = '\0';
	if (access(v->str + 1, R_OK))
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
		{
			free_str(vars.tmp, i + 1);
			return (NULL);
		}
	}
	vars.tmp[i] = NULL;
	close(vars.fd);
	return (vars.tmp);
}
