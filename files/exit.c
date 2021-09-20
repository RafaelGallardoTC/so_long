/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 06:59:40 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/20 06:59:43 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_exit(char *str)
{
	write(1, "[so_long] ", 10);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	exit(0);
	return (0);
}

int		clear_config(t_map *map)
{
	if (map->mapPtr)
	{
		free(map->mapPtr);
		map->mapPtr = NULL;
	}
	return (0);
}

int		clear_window(t_game *game)
{
	if (game->img.ptr)
		mlx_destroy_image(game->mlx.ptr, game->img.ptr);
	if (game->mlx.ptr && game->mlx.win)
		mlx_destroy_window(game->mlx.ptr, game->mlx.win);
	return (0);
}

int		exit_game(t_game *game, ...)
{
	va_list		args;
	char		*msg;
	int			code;

	clear_config(&game->map);
	clear_window(game);
	va_start(args, game);

	if ((msg = va_arg(args, char*)))
		printf("%s\n", msg);
	else
		printf("[so_long] EXIT Default\n");

	code = va_arg(args, int);

	va_end(args);
	printf("code: %d \n", code);
	exit(code);
	return (code);
}

int		exit_cross(t_game *game)
{
	clear_config(&game->map);
	clear_window(game);
	printf("[so_long] EXIT SUCCESS\n");
	exit(0);
	return (0);
}
