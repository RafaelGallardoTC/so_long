/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:17:34 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/14 23:51:15 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		map_init(t_map *map, int x, int y)
{
	/* x = COLUMNS and y = ROWS */
	int		i;
	int		r;
	int		fd;
	char	*line;

	fd = open(map->map_path, O_RDONLY);

	if ((map->mapPtr = (char**)malloc(y * sizeof(char*))) == NULL)
		return (-1);
	i = 0;
	while (i < y)
	{
		if ((map->mapPtr[i] = (char*)ft_calloc(x, sizeof(int))) == NULL)
			return (-1);
		r = get_next_line(fd, &line);
		ft_memcpy(map->mapPtr[i], line, x);
		i++;
	}
	close(fd);
	return (0);
}

void	setup(t_game *game, char *map_path)
{
	get_map_size(map_path, game);
	ft_set_tile_size(game);

	/* Player Initiation */
	game->player.moveSpeed = game->TILE_SIZE;
	game->player.turnDir = 0;
	game->player.walkDir = 0;
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
