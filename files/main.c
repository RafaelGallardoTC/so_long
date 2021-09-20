/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:18:24 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/20 19:52:19 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	drawit(t_game *game)
{
	ft_loadtextures1(game);
	ft_loadtextures2(game);
	playerUpdate(game);
	ft_renderMap(game);
	ft_renderPlayer(game);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->img.ptr, 0, 0);
	ft_putmoves(game);
	mlx_do_sync(game->mlx.ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc > 2 || argc == 1)
		ft_exit("Invalid number of arguments.");
	if (!(ft_check_extension(argv[1], ".ber")))
		ft_exit("Invalid file format.");
	setup(&game, argv[1]);
	map_init(&game.map, game.map.x, game.map.y);
	if (!read_map(&game))
		exit_game(&game, "Not a valid map", -1);
	create_win(&game);
	mlx_hook(game.mlx.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.mlx.win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.mlx.win, 17, 1L << 17, exit_cross, &game);
	mlx_loop_hook(game.mlx.ptr, drawit, &game);
	mlx_loop(game.mlx.ptr);
}
