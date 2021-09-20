/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winUtils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:17:56 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/16 10:39:46 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		create_win(t_game *game)
{
	game->mlx.ptr = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.ptr, game->WINDOW_WIDTH, game->WINDOW_HEIGHT, "so_long");
	game->img.ptr = mlx_new_image(game->mlx.ptr, game->WINDOW_WIDTH, game->WINDOW_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.ptr, &game->img.bpp, &game->img.line_len, &game->img.endian);

	return (0);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

unsigned int	ft_mlx_get_color(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}

void	ft_set_tile_size(t_game *game)
{
	int		nativey;
	int		nativex;

	mlx_get_screen_size(game->mlx.ptr, &nativex, &nativey);
	if (game->map.y >= game->map.x)
		game->TILE_SIZE = (int)(nativey * 0.80 / game->map.y);
	else
		game->TILE_SIZE = (int)(nativex * 0.80 / game->map.x);

	game->WINDOW_WIDTH = (int)game->TILE_SIZE * game->map.x;
	game->WINDOW_HEIGHT = (int)game->TILE_SIZE * game->map.y;
}
