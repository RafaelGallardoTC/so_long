/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:18:08 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/20 19:52:50 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_S || keycode == KEY_W
		|| keycode == KEY_A || keycode == KEY_D)
		printf("MOVEMENT: %d\n", game->player.moves++);
	if (keycode == KEY_S)
		game->player.walkdir = 1;
	else if (keycode == KEY_W)
		game->player.walkdir = -1;
	else if (keycode == KEY_D)
		game->player.turndir = 1;
	else if (keycode == KEY_A)
		game->player.turndir = -1;
	else if (keycode == KEY_ESC || keycode == RED_CROSS)
		exit_game(game, "It is OK if you leave.", 0);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->player.walkdir = 0;
	else if (keycode == KEY_S)
		game->player.walkdir = 0;
	else if (keycode == KEY_A)
		game->player.turndir = 0;
	else if (keycode == KEY_D)
		game->player.turndir = 0;
	return (0);
}
