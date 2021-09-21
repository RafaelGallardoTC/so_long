/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:18:24 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/21 02:40:55 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	drawit(t_game *gm)
{
	loadtextures1(gm);
	loadtextures2(gm);
	player_update(gm);
	render_map(gm);
	render_player(gm);
	mlx_put_image_to_window(gm->mlx.ptr, gm->mlx.win, gm->img.ptr, 0, 0);
	putmoves(gm);
	mlx_do_sync(gm->mlx.ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	gm;
	if (argc > 2 || argc == 1)
		ft_exit("Invalid number of arguments.");
	if (!(ft_check_extension(argv[1], ".ber")))
		ft_exit("Invalid file format.");
	setup(&gm, argv[1]);
	map_init(&gm.map, gm.map.x, gm.map.y);
	if (!read_map(&gm))
		exit_game(&gm, "Not a valid map", -1);
	create_win(&gm);
	mlx_hook(gm.mlx.win, 2, 1L << 0, key_press, &gm);
	mlx_hook(gm.mlx.win, 3, 1L << 1, key_release, &gm);
	mlx_hook(gm.mlx.win, 17, 1L << 17, exit_cross, &gm);
	mlx_loop_hook(gm.mlx.ptr, drawit, &gm);
	mlx_loop(gm.mlx.ptr);
}
