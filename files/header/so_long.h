/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetoyan <apetoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:10:06 by argharag          #+#    #+#             */
/*   Updated: 2025/08/20 20:06:49 by apetoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define A mlx_put_image_to_window
# define B map
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

typedef struct map_s
{
	void		*wall;
	void		*exit;
	void		*item;
	void		*player;
	void		*collect;
}				t_map_s;

typedef struct s_mapdata
{
	int			height;
	int			weight;
	int			player;
	int			score;
	int			collect;
	int			ply_x;
	int			ply_y;
	int			exit_x;
	int			exit_y;
	char		**mapdata;
	int			map_x;
	int			map_y;
	int			size_x;
	int			size_y;
	int			gameover;
	int			enemy;
	int			coin_count;
	int			ply_position;
}				t_mapdata;

typedef struct data_s
{
	t_mapdata	mapdata;
	t_map_s		map_img;
	void		*mlx;
	void		*win;
	void		*img;
	int			step_count;
	int			width;
	int			height;
	int			endian;
}				t_data;

int				check_ins_left_right(char **map, int count);
int				check_all_s(char **map, int count);
int				check_map_inside(char **map, int count);
int				count_av(char *argv, t_mapdata **map);
char			**map_create(char *argv, int count);
int				check_av(char *argv);
int				check_map_size(char **map, int count);
int				check_a(char **map, int a, int b);
int				check_game_com(char **map, int x, int y);
void			find_player(t_mapdata *map);
int				map_for_check_a(t_mapdata *map, t_s_str *v);
void			exit_check(t_data *data, t_mapdata *map, int m, int n);
void			free_str(char **str, int count);
int				win_cl(t_data *data);
int				coin_count(t_mapdata *map);
int				check_map(t_mapdata *map, char *argv);
void			create_map(t_data *data, t_mapdata *mp);
void			print_str(char **str, int count);
void			find_player(t_mapdata *map);
int				not_wall(t_mapdata *map, int x, int y);
void			go_left(t_data *data);
void			go_right(t_data *data);
void			go_up(t_data *data);
void			go_down(t_data *data);

#endif
