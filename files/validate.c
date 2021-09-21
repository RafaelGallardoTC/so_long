/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:17:38 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/21 01:27:17 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(t_game *gm)
{
	int		i;
	int		j;
	int		valid;
	int		*ch_list;

	ch_list = ft_calloc(3, sizeof(int));
	if (!ch_list)
		return (-1);
	i = 0;
	while (i < gm->map.y)
	{
		j = 0;
		while (j < gm->map.x)
		{
			check_cepp(gm, ch_list, i, j);
			j++;
		}
		printf("\n");
		i++;
	}
	gm->map.rectangular = j > i;
	valid = (ch_list[0] && ch_list[1] && ch_list[2]
			&& ch_list[3] && gm->map.rectangular);
	int_arr_free_null(ch_list);
	return (valid);
}

void	check_cepp(t_game *gm, int *ch_list, int i, int j)
{
	int		ch;

	ch = gm->map.map_ptr[i][j];
	if (ch != 'C' && ch_list[0] != 1)
		ch_list[0] = 0;
	else
		ch_list[0] = 1;
	if (ch != 'E' && ch_list[1] != 1)
		ch_list[1] = 0;
	else
		ch_list[1] = 1;
	if (ch != 'P' && ch_list[2] != 1)
		ch_list[2] = 0;
	else
		ch_list[2] = 1;
	if (ch == 'P')
	{
		gm->player.y = i * gm->tile_size;
		gm->player.x = j * gm->tile_size;
	}
	if (((i == 0 || i == (gm->map.y - 1)) && ch != '1')
		|| ((j == 0 || j == (gm->map.x - 1)) && ch != '1'))
		ch_list[3] = 0;
	else
		ch_list[3] = 1;
}
