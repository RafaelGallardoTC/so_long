/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:17:01 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/20 19:55:13 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_extension(char *path, char *ext)
{
	int	pathlen;
	int	extlen;

	pathlen = ft_strlen(path);
	extlen = ft_strlen(ext);
	if (!(extlen == 4) || !(pathlen > 4))
		return (0);
	return (*(path + pathlen - 1) == *(ext + extlen - 1)
		&& *(path + pathlen - 2) == *(ext + extlen - 2)
		&& *(path + pathlen - 3) == *(ext + extlen - 3)
		&& *(path + pathlen - 4) == *(ext + extlen - 4));
}

void	get_map_size(char *map_path, t_game *game)
{
	char	*line;
	int		fd;
	int		r;

	fd = open(map_path, O_RDONLY);
	game->map.x = 0;
	game->map.y = 0;
	while (TRUE)
	{
		r = get_next_line(fd, &line);
		if (!r)
			break ;
		if (game->map.y == 0 && *line)
		{
			while (*line)
			{
				line++;
				game->map.x++;
			}
		}
		game->map.y++;
	}
	close(fd);
}
