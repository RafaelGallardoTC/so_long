/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:17:01 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/22 23:10:07 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_extension(char *path, char *ext)
{
	int		pathlen;
	int		extlen;

	pathlen = ft_strlen(path);
	extlen = ft_strlen(ext);
	if (!(extlen == 4) || !(pathlen > 4))
		return (0);
	return (*(path + pathlen - 1) == *(ext + extlen - 1)
		&& *(path + pathlen - 2) == *(ext + extlen - 2)
		&& *(path + pathlen - 3) == *(ext + extlen - 3)
		&& *(path + pathlen - 4) == *(ext + extlen - 4));
}

void	get_map_size(char *map_path, t_game *gm)
{
	char	*line;
	int		r;
	char	*tmp;

	gm->fd = open(map_path, O_RDONLY);
	while (TRUE)
	{
		r = get_next_line(gm->fd, &line);
		tmp = line;
		if (!r)
			break ;
		if (gm->map.y == 0 && *line)
		{
			while (*line)
			{
				line++;
				gm->map.x++;
			}
		}
		gm->map.y++;
		free(tmp);
	}
	if (tmp)
		free(tmp);
	close(gm->fd);
}

void	char_arr_free_null(char *arr)
{
	free(arr);
	arr = NULL;
}

void	int_arr_free_null(int *arr)
{
	free(arr);
	arr = NULL;
}
