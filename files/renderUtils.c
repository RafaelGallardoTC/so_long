/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderUtils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:18:04 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/17 14:37:01 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
*	Draws a full square tile with the appropiated texture.
*/
void	ft_draw_tile(t_game *game, int i, int j)
{
	game->x = 0;
	while (game->x < game->TILE_SIZE)
	{
		game->y = 0;
		while (game->y < game->TILE_SIZE)
		{
			// if (game->player.x == game->exit.x && game->player.y == game->exit.y
			// 	&& i == game->player.x && j == game->player.y)
			// 	game->sprite = game->texexit;
			// else
			game->sprite = game->texfloor;
			ft_selectsprite(game, i, j);
			ft_putspritepixel(game, i, j);
			game->y++;
		}
		game->x++;
	}
}

/*
*	Matches the loaded texture with the corresponding map tile,
*/
void	ft_selectsprite(t_game *game, int i, int j)
{
	if (game->map.mapPtr[i][j] == '1')
		game->sprite = game->texwall;
	else if (game->map.mapPtr[i][j] == 'C')
		game->sprite = game->texitem;
	else if (game->map.mapPtr[i][j] == 'E')
		game->sprite = game->texexit;
}

void	ft_putspritepixel(t_game *game, int i, int j)
{
	game->texx = (int)((float)game->y / game->TILE_SIZE * game->sprite.width);
	game->texy = (int)((float)game->x / game->TILE_SIZE * game->sprite.height);
	if (game->map.mapPtr[i][j])
	{
		if (ft_mlx_get_color(&game->sprite, game->texx, game->texy) != NONE)
			my_mlx_pixel_put(&game->img, j * game->TILE_SIZE + game->y, i * game->TILE_SIZE + game->x,
							ft_mlx_get_color(&game->sprite, game->texx, game->texy));
	}
}

int		ft_renderMap(t_game *game)
{
	game->i = 0;
	while (game->i < game->map.y)
	{
		game->j = 0;
		while (game->j < game->map.x)
		{
			ft_draw_tile(game, game->i, game->j);
			game->j++;
		}
		game->i++;
	}
	return (0);
}

int		ft_renderPlayer(t_game *game)
{
	int		in_x = 0;
	int		in_y = 0;

	game->sprite = game->texpl;
	while (in_x < game->TILE_SIZE)
	{
		in_y = 0;
		while (in_y < game->TILE_SIZE)
		{

			game->texx = (int)((float)in_y / game->TILE_SIZE * game->sprite.width);
			game->texy = (int)((float)in_x / game->TILE_SIZE * game->sprite.height);

			if (ft_mlx_get_color(&game->sprite, game->texx, game->texy) != 0xFF000000)
				my_mlx_pixel_put(&game->img, game->player.x + in_y, game->player.y + in_x,
								ft_mlx_get_color(&game->sprite, game->texx, game->texy));
			in_y++;
		}
		in_x++;
	}
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->img.ptr, 0, 0);
	//ft_putmoves(game);
	//mlx_do_sync(game->mlx.ptr);
	return (0);
}

void	ft_putmoves(t_game *game)
{
	char	*num;
	char	*line;

	num = ft_itoa(game->player.moves);
	line = ft_strjoin("Move Count: ", num);
	mlx_string_put(game->mlx.ptr, game->mlx.win, 10, 10, 0xFFFFFF, line);
	free(line);
	free(num);
}

