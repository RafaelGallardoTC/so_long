/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winUtils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:17:56 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/21 01:28:50 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_win(t_game *gm)
{
	gm->mlx.ptr = mlx_init();
	gm->mlx.win = mlx_new_window(gm->mlx.ptr, gm->win_width,
			gm->win_height, "so_long");
	gm->img.ptr = mlx_new_image(gm->mlx.ptr, gm->win_width, gm->win_height);
	gm->img.addr = mlx_get_data_addr(gm->img.ptr, &gm->img.bpp,
			&gm->img.line_len, &gm->img.endian);
	return (0);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	mlx_get_color(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}

void	set_tile_size(t_game *gm)
{
	int		nativey;
	int		nativex;

	mlx_get_screen_size(gm->mlx.ptr, &nativex, &nativey);
	if (gm->map.y >= gm->map.x)
		gm->tile_size = (int)(nativey * 0.80 / gm->map.y);
	else
		gm->tile_size = (int)(nativex * 0.80 / gm->map.x);
	gm->win_width = (int)gm->tile_size * gm->map.x;
	gm->win_height = (int)gm->tile_size * gm->map.y;
}
