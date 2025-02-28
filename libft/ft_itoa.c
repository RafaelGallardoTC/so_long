/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 00:02:44 by rgallard          #+#    #+#             */
/*   Updated: 2019/11/25 00:02:46 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	nb_len(long n)
{
	size_t	i;

	i = 0;
	if (n >= 0 && n <= 9)
		return (1);
	if (n < 0)
	{
		++i;
		n *= -1;
	}
	n = n / 10;
	while (++i && n > 0)
		n = n / 10;
	return (i);
}

char	*ft_itoa(int n)
{
	size_t		i;
	size_t		len;
	char		*str;
	long		nb;

	nb = n;
	i = 0;
	len = nb_len(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
		++i;
	}
	while (i < len--)
	{
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}
