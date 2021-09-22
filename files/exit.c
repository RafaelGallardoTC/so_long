/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 06:59:40 by rgallard          #+#    #+#             */
/*   Updated: 2021/09/22 20:09:46 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(char *str)
{
	write(1, "[so_long] ", 10);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	exit(0);
	return (0);
}

int	clear_config(t_game **gm)
{
	int	i;

	i = 0;
	while (i < (*gm)->map.y)
	{
		if ((*gm)->map.map_ptr[i])
		{
			free((*gm)->map.map_ptr[i]);
			(*gm)->map.map_ptr[i] = NULL;
		}
		i++;
	}
	if ((*gm)->map.map_ptr)
	{
		free((*gm)->map.map_ptr);
		(*gm)->map.map_ptr = NULL;
	}
	return (0);
}

int	clear_window(t_game *gm)
{
	if (gm->img.ptr)
		mlx_destroy_image(gm->mlx.ptr, gm->img.ptr);
	if (gm->mlx.ptr && gm->mlx.win)
		mlx_destroy_window(gm->mlx.ptr, gm->mlx.win);
	return (0);
}

int	exit_game(t_game *gm, ...)
{
	va_list		args;
	char		*msg;
	int			code;

	clear_config(&gm);
	clear_window(gm);
	va_start(args, gm);
	msg = va_arg(args, char *);
	if (msg)
		printf("%s\n", msg);
	else
		printf("[so_long] EXIT Default\n");
	code = va_arg(args, int);
	va_end(args);
	printf("code: %d \n", code);
	exit(code);
	return (code);
}

int	exit_cross(t_game *gm)
{
	clear_config(&gm);
	clear_window(gm);
	printf("[so_long] EXIT SUCCESS\n");
	exit(0);
	return (0);
}
