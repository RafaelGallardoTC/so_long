/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:17:47 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/22 23:09:53 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

# define NONE 0xFF000000
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define MAGENTA 0x00FF00FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF
# define BUFFER_SIZE 1
# define TRUE 1
# define FALSE 0
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_MOUSE_PRESS 4
# define X_EVENT_MOUSE_RELEASE 5
# define X_EVENT_MOUSE_MOVE 6
# define RED_CROSS 17

/*
*	-1 if left, +1 if right
*	-1 if back, +1 if front
*/
typedef struct s_player
{
	int		x;
	int		y;
	int		turn_dir;
	int		walk_dir;
	double	mov_speed;
	int		moves;
	int		mv_stepx;
	int		mv_stepy;
	int		new_playerx;
	int		new_playery;
}	t_player;

typedef struct s_map
{
	char	*map_path;
	char	**map_ptr;
	int		rectangular;
	int		grid_index_x;
	int		grid_index_y;
	int		x;
	int		y;
}	t_map;

/*
*	struct for push images to windows
*/
typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct s_exit
{
	char	*msg;
	int		code;
	int		x;
	int		y;
}	t_exit;

typedef struct s_game
{
	int				i;
	int				j;
	int				x;
	int				y;
	int				tx_x;
	int				tx_y;
	int				tile_size;
	int				win_width;
	int				win_height;
	char			*tmp_arr;
	int				n_collect;
	int				fd;
	t_player		player;
	t_map			map;
	t_mlx			mlx;
	t_img			img;
	t_img			sprite;
	t_img			tx_wall;
	t_img			tx_pl;
	t_img			tx_item;
	t_img			tx_exit;
	t_img			tx_floor;
}	t_game;

int				ft_exit(char *str);
int				ft_check_extension(char *path, char *ext);
int				found_wall(int x, int y, t_game *gm);
int				found_collect(int x, int y, t_game *gm);
int				found_exit(int x, int y, t_game *gm);
int				clear_config(t_game **gm);
int				clear_window(t_game *gm);
void			player_update(t_game *gm);
void			check_cepp(t_game *gm, int *ch_list, int i, int j);
int				exit_game(t_game *gm, ...);
int				exit_cross(t_game *gm);
void			get_map_size(char *map_path, t_game *gm);
int				get_next_line(const int fd, char **line);
int				read_map(t_game *gm);
void			setup(t_game *gm, char *map_path);
int				map_init(t_map *map, int x, int y);
int				key_release(int keycode, t_game *gm);
int				key_press(int keycode, t_game *gm);
int				create_win(t_game *gm);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
unsigned int	mlx_get_color(t_img *data, int x, int y);
void			set_tile_size(t_game *gm);
void			loadtextures1(t_game *gm);
void			loadtextures2(t_game *gm);
void			draw_tile(t_game *gm, int i, int j);
void			selectsprite(t_game *gm, int i, int j);
void			putspritepixel(t_game *gm, int i, int j);
void			putmoves(t_game *gm);
int				render_player(t_game *gm);
int				render_map(t_game *gm);
void			char_arr_free_null(char *arr);
void			int_arr_free_null(int *arr);
void			find_obstacle(int x, int y, t_game *gm);

#endif
