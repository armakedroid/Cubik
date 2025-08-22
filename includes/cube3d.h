#ifndef CUBE3D_H
# define CUBE3D_H

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"

# define KEY_ESC 65307
# define KEY_Q 113
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

typedef struct s_mapdata
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
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
	float	rot_speed;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
}			t_mapdata;

void		ft_putstr_fd(char *s, int fd);
int			copy_map(t_mapdata *map);
void		free_str(char **str, int count);
void		my_free(char *str);
int			validation(char *argv, t_mapdata *player);
int			find_player(t_mapdata *map);
char		**map_create(char *argv, int count);
int			count_av(char *argv, t_mapdata **map);
int			check_av(char *argv);
void		go_forward(t_mapdata *arg);
void		go_back(t_mapdata *arg);
void		go_left(t_mapdata *arg);
void		go_right(t_mapdata *arg);
void		rot_left(t_mapdata *data, double rotSpeed);
void		rot_right(t_mapdata *data, double rotSpeed);

#endif