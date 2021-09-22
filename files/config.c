/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:17:34 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/22 21:43:46 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
* x = COLUMNS and y = ROWS
*/

int	map_init(t_map *map, int x, int y)
{
	int		i;
	int		r;
	int		fd;
	char	*line;

	i = 0;
	fd = open(map->map_path, O_RDONLY);
	map->map_ptr = (char **)malloc(y * sizeof(char *) + 1);
	if (map->map_ptr == NULL)
		return (-1);
	while (i < y)
	{
		map->map_ptr[i] = (char *)ft_calloc(x + 1, sizeof(char));
		if (map->map_ptr[i] == NULL)
			return (-1);
		r = get_next_line(fd, &line);
		ft_memcpy(map->map_ptr[i], line, x);
		free(line);
		i++;
	}
	map->map_ptr[i] = NULL;
	close(fd);
	return (0);
}

void	setup(t_game *gm, char *map_path)
{
	gm->map.x = 0;
	gm->map.y = 0;
	gm->n_collect = 0;
	get_map_size(map_path, gm);
	set_tile_size(gm);
	gm->player.mov_speed = gm->tile_size;
	gm->player.turn_dir = 0;
	gm->player.walk_dir = 0;
	gm->player.moves = 0;
	gm->map.map_path = map_path;
}

void	putmoves(t_game *gm)
{
	char	*num;
	char	*line;

	num = ft_itoa(gm->player.moves);
	line = ft_strjoin("Move Count: ", num);
	mlx_string_put(gm->mlx.ptr, gm->mlx.win, 10, 10, 0xFFFFFF, line);
	char_arr_free_null(line);
	char_arr_free_null(num);
}
