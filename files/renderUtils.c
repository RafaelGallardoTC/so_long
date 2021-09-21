/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderUtils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:18:04 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/20 23:36:18 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
*	Draws a full square tile with the appropiated texture.
*/
void	draw_tile(t_game *gm, int i, int j)
{
	gm->x = 0;
	while (gm->x < gm->tile_size)
	{
		gm->y = 0;
		while (gm->y < gm->tile_size)
		{
			gm->sprite = gm->tx_floor;
			selectsprite(gm, i, j);
			putspritepixel(gm, i, j);
			gm->y++;
		}
		gm->x++;
	}
}

/*
*	Matches the loaded texture with the corresponding map tile,
*/
void	selectsprite(t_game *gm, int i, int j)
{
	if (gm->map.map_ptr[i][j] == '1')
		gm->sprite = gm->tx_wall;
	else if (gm->map.map_ptr[i][j] == 'C')
		gm->sprite = gm->tx_item;
	else if (gm->map.map_ptr[i][j] == 'E')
		gm->sprite = gm->tx_exit;
}

void	putspritepixel(t_game *gm, int i, int j)
{
	gm->tx_x = (int)((float)gm->y / gm->tile_size * gm->sprite.width);
	gm->tx_y = (int)((float)gm->x / gm->tile_size * gm->sprite.height);
	if (gm->map.map_ptr[i][j])
	{
		if (mlx_get_color(&gm->sprite, gm->tx_x, gm->tx_y) != NONE)
			my_mlx_pixel_put(&gm->img, j * gm->tile_size + gm->y,
				i * gm->tile_size + gm->x,
				mlx_get_color(&gm->sprite, gm->tx_x, gm->tx_y));
	}
}

int	render_map(t_game *gm)
{
	gm->i = 0;
	while (gm->i < gm->map.y)
	{
		gm->j = 0;
		while (gm->j < gm->map.x)
		{
			draw_tile(gm, gm->i, gm->j);
			gm->j++;
		}
		gm->i++;
	}
	return (0);
}

int	render_player(t_game *gm)
{
	int		x;
	int		y;

	x = 0;
	gm->sprite = gm->tx_pl;
	while (x < gm->tile_size)
	{
		y = 0;
		while (y < gm->tile_size)
		{
			gm->tx_x = (int)((float)y / gm->tile_size
					* gm->sprite.width);
			gm->tx_y = (int)((float)x / gm->tile_size
					* gm->sprite.height);
			if (mlx_get_color(&gm->sprite, gm->tx_x, gm->tx_y) != NONE)
				my_mlx_pixel_put(&gm->img, gm->player.x + y,
					gm->player.y + x,
					mlx_get_color(&gm->sprite, gm->tx_x, gm->tx_y));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(gm->mlx.ptr, gm->mlx.win, gm->img.ptr, 0, 0);
	return (0);
}
