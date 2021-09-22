/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:17:42 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/22 21:48:40 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
*	Updates Player's position
*/
void	player_update(t_game *gm)
{
	gm->player.mv_stepx = gm->player.turn_dir * gm->player.mov_speed;
	gm->player.mv_stepy = gm->player.walk_dir * gm->player.mov_speed;
	gm->player.new_playerx = gm->player.x + gm->player.mv_stepx;
	gm->player.new_playery = gm->player.y + gm->player.mv_stepy;
	gm->tmp_arr = ft_calloc(3, sizeof(int));
	find_obstacle(gm->player.new_playerx, gm->player.new_playery, gm);
	if (gm->tmp_arr[0] == FALSE)
	{
		gm->player.x = gm->player.new_playerx;
		gm->player.y = gm->player.new_playery;
	}
	printf("%i\n", gm->n_collect);
	if (gm->tmp_arr[2] == TRUE && gm->n_collect == 0)
	{
		char_arr_free_null(gm->tmp_arr);
		exit_game(gm, "You found the exit! good bye", 0);
	}
	find_obstacle(gm->player.x, gm->player.y, gm);
	if (gm->tmp_arr[1] == TRUE)
		gm->map.map_ptr[gm->player.y / gm->tile_size][gm->player.x
			/ gm->tile_size] = '0';
	gm->player.turn_dir = 0;
	gm->player.walk_dir = 0;
	char_arr_free_null(gm->tmp_arr);
}

/*
*	Search for wall "list[0]", collect "list[1]", exit "list[2]"
*/
void	find_obstacle(int x, int y, t_game *gm)
{
	if (x < 0 || x > gm->win_width || y < 0 || y > gm->win_height)
		gm->tmp_arr[0] = TRUE;
	gm->map.grid_index_x = x / gm->tile_size;
	gm->map.grid_index_y = y / gm->tile_size;
	if (gm->map.map_ptr[gm->map.grid_index_y][gm->map.grid_index_x] == '1')
		gm->tmp_arr[0] = TRUE;
	else if (gm->map.map_ptr[gm->map.grid_index_y][gm->map.grid_index_x] == 'C')
	{
		gm->n_collect--;
		gm->tmp_arr[1] = TRUE;
	}
	else if (gm->map.map_ptr[gm->map.grid_index_y][gm->map.grid_index_x] == 'E')
		gm->tmp_arr[2] = TRUE;
	else
	{
		gm->tmp_arr[0] = FALSE;
		gm->tmp_arr[1] = FALSE;
		gm->tmp_arr[2] = FALSE;
	}
}
