/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:01:13 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/20 23:34:51 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loadtextures1(t_game *gm)
{
	gm->tx_wall.ptr = mlx_xpm_file_to_image(gm->mlx.ptr, "img/wall.xpm",
			&gm->tx_wall.width, &gm->tx_wall.height);
	if (!(gm->tx_wall.ptr))
		ft_exit("Failed to allocate memory for the wall texture.");
	gm->tx_wall.addr = mlx_get_data_addr(gm->tx_wall.ptr, &gm->tx_wall.bpp,
			&gm->tx_wall.line_len, &gm->tx_wall.endian);
	gm->tx_pl.ptr = mlx_xpm_file_to_image(gm->mlx.ptr, "img/panda.xpm",
			&(gm->tx_pl.width), &(gm->tx_pl.height));
	if (!(gm->tx_pl.ptr))
		ft_exit("Failed to allocate memory for the player texture.");
	gm->tx_pl.addr = mlx_get_data_addr(gm->tx_pl.ptr, &gm->tx_pl.bpp,
			&gm->tx_pl.line_len, &gm->tx_pl.endian);
}

void	loadtextures2(t_game *gm)
{
	gm->tx_item.ptr = mlx_xpm_file_to_image(gm->mlx.ptr, "img/food.xpm",
			&(gm->tx_item.width), &(gm->tx_item.height));
	if (!(gm->tx_item.ptr))
		ft_exit("Failed to allocate memory for the item texture.");
	gm->tx_item.addr = mlx_get_data_addr(gm->tx_item.ptr, &gm->tx_item.bpp,
			&gm->tx_item.line_len, &gm->tx_item.endian);
	gm->tx_exit.ptr = mlx_xpm_file_to_image(gm->mlx.ptr, "img/door.xpm",
			&(gm->tx_exit.width), &(gm->tx_exit.height));
	if (!(gm->tx_exit.ptr))
		ft_exit("Failed to allocate memory for the exit texture.");
	gm->tx_exit.addr = mlx_get_data_addr(gm->tx_exit.ptr, &gm->tx_exit.bpp,
			&gm->tx_exit.line_len, &gm->tx_exit.endian);
	gm->tx_floor.ptr = mlx_xpm_file_to_image(gm->mlx.ptr, "img/floor.xpm",
			&(gm->tx_floor.width), &(gm->tx_floor.height));
	if (!(gm->tx_floor.ptr))
		ft_exit("Failed to allocate memory for the floor texture.");
	gm->tx_floor.addr = mlx_get_data_addr(gm->tx_floor.ptr,
			&gm->tx_floor.bpp, &gm->tx_floor.line_len, &gm->tx_floor.endian);
}
