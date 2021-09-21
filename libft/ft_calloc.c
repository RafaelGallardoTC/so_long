/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 22:28:05 by rgallard          #+#    #+#             */
/*   Updated: 2019/11/17 23:54:50 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*space;
	size_t	len;

	len = count * size;
	space = malloc(len);
	if (!space)
		return (NULL);
	ft_bzero(space, len);
	return (space);
}
