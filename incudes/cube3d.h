#ifndef CUBE3D_H
# define CUBE3D_H


# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

typedef struct s_mapdata
{
	int		height;
	int		weight;
	int		player;
	int		ply_x;
	int		ply_y;
	char	**mapdata;
	char	**original_map;
	int		map_x;
	int		map_y;
	int		size_x;
	int		size_y;
	int		ply_position;
	int		SO_line;
	int		NO_line;
	int		WE_line;
	int		EA_line;
	int		F_line;
	int		C_line;
}			t_mapdata;

void		ft_putstr_fd(char *s, int fd);
void		copy_map(t_mapdata *map);
void		free_str(char **str, int count);
void		my_free(char *str);
int			validation(char *argv, t_mapdata *player);
int			find_player(t_mapdata *map);
char		**map_create(char *argv, int count);
int			count_av(char *argv, t_mapdata **map);
int			check_av(char *argv);

#endif