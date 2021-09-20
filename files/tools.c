/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:17:42 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/20 19:48:28 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
*	Updates Player's position
*/
void	playerupdate(t_game *game)
{
	int		movestepx;
	int		movestepy;
	int		newplayerx;
	int		newplayery;

	movestepx = game->player.turndir * game->player.movespeed;
	movestepy = game->player.walkdir * game->player.movespeed;
	newplayerx = game->player.x + movestepx;
	newplayery = game->player.y + movestepy;
	if (found_wall(newplayerx, newplayery, game) == FALSE)
	{
		game->player.x = newplayerx;
		game->player.y = newplayery;
	}
	if (found_exit(newplayerx, newplayery, game))
		exit_game(game, "You found the exit! good bye", 0);
	else if (found_collect(game->player.x, game->player.y, game))
		game->map.mapptr[game->player.y
			/ game->tile_size][game->player.x / game->tile_size] = '0';
	game->player.turndir = 0;
	game->player.walkdir = 0;
}

int	found_wall(int x, int y, t_game *game)
{
	int	mapgridindexx;
	int	mapgridindexy;

	if (x < 0 || x > game->window_width || y < 0 || y > game->window_height)
		return (TRUE);
	mapgridindexx = x / game->tile_size;
	mapgridindexy = y / game->tile_size;
	if (game->map.mapptr[mapgridindexy][mapgridindexx] == '1')
		return (TRUE);
	else
		return (FALSE);
}

int	found_collect(int x, int y, t_game *game)
{
	int	mapgridindexx;
	int	mapgridindexy;

	if (x < 0 || x > game->window_width || y < 0 || y > game->window_height)
		return (FALSE);
	mapgridindexx = x / game->tile_size;
	mapgridindexy = y / game->tile_size;
	if (game->map.mapptr[mapgridindexy][mapgridindexx] == 'C')
		return (TRUE);
	else
		return (FALSE);
}

int	found_exit(int x, int y, t_game *game)
{
	int	mapgridindexx;
	int	mapgridindexy;

	if (x < 0 || x > game->window_width || y < 0 || y > game->window_height)
		return (FALSE);
	mapgridindexx = x / game->tile_size;
	mapgridindexy = y / game->tile_size;
	if (game->map.mapptr[mapgridindexy][mapgridindexx] == 'E')
		return (TRUE);
	else
		return (FALSE);
}
