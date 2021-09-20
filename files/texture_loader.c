/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:01:13 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/20 19:45:47 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_loadtextures1(t_game *game)
{
	game->texwall.ptr = mlx_xpm_file_to_image(game->mlx.ptr, "img/wall.xpm",
			&game->texwall.width, &game->texwall.height);
	if (!(game->texwall.ptr))
		ft_exit("Failed to allocate memory for the wall texture.");
	game->texwall.addr = mlx_get_data_addr(game->texwall.ptr,
			&game->texwall.bpp, &game->texwall.line_len,
			&game->texwall.endian);
	game->texpl.ptr = mlx_xpm_file_to_image(game->mlx.ptr, "img/panda.xpm",
			&(game->texpl.width), &(game->texpl.height));
	if (!(game->texpl.ptr))
		ft_exit("Failed to allocate memory for the player texture.");
	game->texpl.addr = mlx_get_data_addr(game->texpl.ptr, &game->texpl.bpp,
			&game->texpl.line_len, &game->texpl.endian);
}

void	ft_loadtextures2(t_game *game)
{
	game->texitem.ptr = mlx_xpm_file_to_image(game->mlx.ptr, "img/food.xpm",
			&(game->texitem.width), &(game->texitem.height));
	if (!(game->texitem.ptr))
		ft_exit("Failed to allocate memory for the item texture.");
	game->texitem.addr = mlx_get_data_addr(game->texitem.ptr,
			&game->texitem.bpp, &game->texitem.line_len,
			&game->texitem.endian);
	game->texexit.ptr = mlx_xpm_file_to_image(game->mlx.ptr, "img/door.xpm",
			&(game->texexit.width), &(game->texexit.height));
	if (!(game->texexit.ptr))
		ft_exit("Failed to allocate memory for the exit texture.");
	game->texexit.addr = mlx_get_data_addr(game->texexit.ptr,
			&game->texexit.bpp, &game->texexit.line_len,
			&game->texexit.endian);
	game->texfloor.ptr = mlx_xpm_file_to_image(game->mlx.ptr, "img/floor.xpm",
			&(game->texfloor.width), &(game->texfloor.height));
	if (!(game->texfloor.ptr))
		ft_exit("Failed to allocate memory for the floor texture.");
	game->texfloor.addr = mlx_get_data_addr(game->texfloor.ptr,
			&game->texfloor.bpp, &game->texfloor.line_len,
			&game->texfloor.endian);
}
