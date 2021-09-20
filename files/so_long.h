/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:17:47 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/20 19:47:13 by gfaviere         ###   ########.fr       */
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

typedef struct s_player
{
	int		x;
	int		y;
	int		turndir;
	int		walkdir;
	double	movespeed;
	int		moves;
}	t_player;

typedef struct s_map
{
	char	*map_path;
	char	**mapptr;
	int		rectangular;
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
	int				texx;
	int				texy;
	int				tile_size;
	int				window_width;
	int				window_height;
	t_player		player;
	t_map			map;
	t_mlx			mlx;
	t_img			img;
	t_img			sprite;
	t_img			texwall;
	t_img			texpl;
	t_img			texitem;
	t_img			texexit;
	t_img			texfloor;
}	t_game;

int				found_wall(int x, int y, t_game *game);
int				found_collect(int x, int y, t_game *game);
int				found_exit(int x, int y, t_game *game);
int				clear_config(t_map *map);
int				clear_window(t_game *game);

void			playerUpdate(t_game *game);
void			check_CEPP(t_game *game, int *ch_list, int i, int j);
int				exit_game(t_game *game, ...);
int				ft_exit(char *str);
int				exit_cross(t_game *game);
int				ft_check_extension(char *path, char *ext);
void			get_map_size(char *map_path, t_game *game);
int				get_next_line(const int fd, char **line);
int				read_map(t_game *game);
void			setup(t_game *game, char *map_path);
int				map_init(t_map *map, int x, int y);
int				key_release(int keycode, t_game *game);
int				key_press(int keycode, t_game *game);
int				create_win(t_game *game);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
unsigned int	ft_mlx_get_color(t_img *data, int x, int y);
void			ft_set_tile_size(t_game *game);
void			ft_loadtextures1(t_game *game);
void			ft_loadtextures2(t_game *game);
void			ft_draw_tile(t_game *game, int i, int j);
void			ft_selectsprite(t_game *game, int i, int j);
void			ft_putspritepixel(t_game *game, int i, int j);
void			ft_putmoves(t_game *game);
int				ft_renderPlayer(t_game *game);
int				ft_renderMap(t_game *game);

#endif
