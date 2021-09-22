/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:18:08 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/22 18:56:21 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *gm)
{
	if (keycode == KEY_S || keycode == KEY_W
		|| keycode == KEY_A || keycode == KEY_D)
		printf("MOVEMENT: %d\n", gm->player.moves++);
	if (keycode == KEY_S)
		gm->player.walk_dir = 1;
	else if (keycode == KEY_W)
		gm->player.walk_dir = -1;
	else if (keycode == KEY_D)
		gm->player.turn_dir = 1;
	else if (keycode == KEY_A)
		gm->player.turn_dir = -1;
	else if (keycode == KEY_ESC || keycode == RED_CROSS)
		exit_game(gm, "It is OK if you leave.", 0);
	return (0);
}

int	key_release(int keycode, t_game *gm)
{
	if (keycode == KEY_W)
		gm->player.walk_dir = 0;
	else if (keycode == KEY_S)
		gm->player.walk_dir = 0;
	else if (keycode == KEY_A)
		gm->player.turn_dir = 0;
	else if (keycode == KEY_D)
		gm->player.turn_dir = 0;
	return (0);
}
