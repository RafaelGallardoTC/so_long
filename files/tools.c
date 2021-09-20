/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:17:42 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/16 10:17:07 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
*	Updates Player's position
*/
void	playerUpdate(t_game *game)
{
	int		moveStepX;
	int		moveStepY;
	int		newPlayerX; /* X future position */
	int		newPlayerY; /* Y future position */

	moveStepX = game->player.turnDir * game->player.moveSpeed;
	moveStepY = game->player.walkDir * game->player.moveSpeed;
	newPlayerX = game->player.x + moveStepX;
	newPlayerY = game->player.y + moveStepY;

	/* If future position isn't a wall modify player position*/
	if (found_wall(newPlayerX, newPlayerY, game) == FALSE)
	{
		game->player.x = newPlayerX;
		game->player.y = newPlayerY;
	}
	if (found_exit(newPlayerX, newPlayerY, game))
		exit_game(game, "You found the exit! good bye", 0);
	else if (found_collect(game->player.x, game->player.y, game))
		game->map.mapPtr[game->player.y / game->TILE_SIZE][game->player.x / game->TILE_SIZE] = '0';

	/* To avoid wrong movement. It makes movement step by step */
	game->player.turnDir = 0;
	game->player.walkDir = 0;
}

int		found_wall(int x, int y, t_game *game)
{
	if (x < 0 || x > game->WINDOW_WIDTH || y < 0 || y > game->WINDOW_HEIGHT)
		return (TRUE);

	int mapGridIndexX;
	int mapGridIndexY;

	mapGridIndexX = x / game->TILE_SIZE;
	mapGridIndexY = y / game->TILE_SIZE;

	if (game->map.mapPtr[mapGridIndexY][mapGridIndexX] == '1')
		return (TRUE);
	else
		return (FALSE);
}

int		found_collect(int x, int y, t_game *game)
{
	if (x < 0 || x > game->WINDOW_WIDTH || y < 0 || y > game->WINDOW_HEIGHT)
		return (FALSE);

	int mapGridIndexX;
	int mapGridIndexY;

	mapGridIndexX = x / game->TILE_SIZE;
	mapGridIndexY = y / game->TILE_SIZE;

	if (game->map.mapPtr[mapGridIndexY][mapGridIndexX] == 'C')
		return (TRUE);
	else
		return (FALSE);
}

int		found_exit(int x, int y, t_game *game)
{
	if (x < 0 || x > game->WINDOW_WIDTH || y < 0 || y > game->WINDOW_HEIGHT)
		return (FALSE);

	int mapGridIndexX;
	int mapGridIndexY;

	mapGridIndexX = x / game->TILE_SIZE;
	mapGridIndexY = y / game->TILE_SIZE;

	if (game->map.mapPtr[mapGridIndexY][mapGridIndexX] == 'E')
		return (TRUE);
	else
		return (FALSE);
}
