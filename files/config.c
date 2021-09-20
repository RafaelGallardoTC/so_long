/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:17:34 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/20 19:57:34 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_init(t_map *map, int x, int y)
{
	int		i;
	int		r;
	int		fd;
	char	*line;

	fd = open(map->map_path, O_RDONLY);
	map->mapptr = (char **)malloc(y * sizeof(char *));
	if (map->mapptr == NULL)
		return (-1);
	i = 0;
	while (i < y)
	{
		map->mapptr[i] = (char *)ft_calloc(x, sizeof(int));
		if (map->mapptr[i] == NULL)
			return (-1);
		r = get_next_line(fd, &line);
		ft_memcpy(map->mapptr[i], line, x);
		i++;
	}
	close(fd);
	return (0);
}

void	setup(t_game *game, char *map_path)
{
	get_map_size(map_path, game);
	ft_set_tile_size(game);
	game->player.movespeed = game->tile_size;
	game->player.turndir = 0;
	game->player.walkdir = 0;
	game->player.moves = 0;
	game->map.map_path = map_path;
	//game->state = 1;
	//game->exit.x = -1;
	//game->exit.y = -1;
	//game->player.items = 0;
	//game->player.goal = 0;
	//game->state = 1;
	//game->keys.check = 1;
}
