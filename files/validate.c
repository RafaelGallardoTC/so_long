/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:17:38 by rgallard          #+#    #+#             */
/*   Updated: 2021/08/21 17:50:40 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		read_map(t_game *game)
{
	int 	i;
	int 	j;
	int		valid_CEP;
	int		*ch_list;

	// TODO return memory allocate error.
	if (!(ch_list = (int*)malloc(sizeof(int) * 4)))
		return (-1);

	i = 0;
	j = 0;
	while (i < game->map.y)
	{
		j = 0;
		while (j < game->map.x)
		{
			check_CEPP(game, ch_list, i, j);
			j++;
		}
		printf("\n");
		i++;
	}
	game->map.rectangular = j > i;
	valid_CEP = (ch_list[0] && ch_list[1] && ch_list[2] && ch_list[3] && game->map.rectangular);
	if (ch_list)
	{
		free(ch_list);
		ch_list = NULL;
	}
	return (valid_CEP);
}

void	check_CEPP(t_game *game, int *ch_list, int i, int j)
{
	int		ch;

	ch = game->map.mapPtr[i][j];
	ch_list[0] = (ch != 'C' && ch_list[0] != 1) ? 0 : 1;
	ch_list[1] = (ch != 'E' && ch_list[1] != 1) ? 0 : 1;
	ch_list[2] = (ch != 'P' && ch_list[2] != 1) ? 0 : 1;

	if (ch == 'P')
	{
		game->player.y = i * game->TILE_SIZE;
		game->player.x = j * game->TILE_SIZE;
	}
	if (((i == 0 || i == (game->map.y - 1)) && ch != '1') || /* Perimeter */
		((j == 0 || j == (game->map.x - 1)) && ch != '1'))
			ch_list[3] = 0;
	else
		ch_list[3] = 1;
}
