#ifndef CUBE3D_H
# define CUBE3D_H

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <math.h>

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

typedef struct s_vars_put
{
	int			dst_x;
	int			dst_y;
	int			dst_w;
	int			dst_h;
	int			i;
}				t_vars_put;

typedef struct s_img_it
{
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			endian;
	int			line_length;
	int			height;
	int			width;
}				t_img_it;

typedef struct s_mapdata
{
	t_img_it	*img_it[4];
	t_img_it	screen;
	void		*mlx;
	int			max_row;
	void		*win;
	int			height;
	int			width;
	int			player;
	double		ply_x;
	double		ply_y;
	char		**mapdata;
	char		**c_map;
	char		**original_map;
	char		ply_symbol;
	int			map_x;
	int			map_y;
	int			size_x;
	int			size_y;
	int			press;
	int			key[7];
	int			ply_position;
	int			so_line;
	int			no_line;
	int			we_line;
	int			ea_line;
	int			f_line;
	int			c_line;
	float		rot_speed;
	float		move_speed;
	double		dir_x;
	double		dir_y;
	double		plane_y;
	double		plane_x;
	double		offset_x;
	double		offset_y;
	int			endian;
	int			step_up;
	int			step_around;
}				t_mapdata;

void			print_map(char **map);
void			ft_putstr_fd(char *s, int fd);
int				copy_map(t_mapdata *map);
int				copy_map1(t_mapdata *map);
void			free_str(char **str, int count);
void			my_free(char *str);
int				validation(char *argv, t_mapdata *player);
int				find_player(t_mapdata *map);
char			**map_create(char *argv, int count, t_mapdata *data);
int				count_av(char *argv, t_mapdata **map);
int				check_av(char *argv);
void			go_forward(t_mapdata *arg);
void			go_back(t_mapdata *arg);
void			go_left(t_mapdata *arg);
void			go_right(t_mapdata *arg);
void			rot_left(t_mapdata *data, double rotSpeed);
void			rot_right(t_mapdata *data, double rotSpeed);
void			create_map(t_mapdata *data);
void			all_imgs(t_mapdata *data);
void			destroy_imgs(t_mapdata *data);
void			draw_ceil_floor(t_img_it *screen, t_mapdata *data, int x,
					int draw_start, int draw_end);
int				move_smwh(t_mapdata *data);

#endif