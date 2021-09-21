/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallard <rgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:02:51 by rgallard          #+#    #+#             */
/*   Updated: 2019/11/21 07:16:28 by rgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

static void	ft_check_sign(const char **str, long int *is_neg)
{
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '+')
		(*str)++;
	else if (**str == '-')
	{
		*is_neg = -1;
		(*str)++;
	}
}

int	ft_atoi(const char *str)
{
	long int	n;
	long int	is_neg;

	is_neg = 1;
	n = 0;
	ft_check_sign(&str, &is_neg);
	while (*str != '\0' && ft_isdigit(*str))
	{
		n = n * 10 + (*str++ - 48);
		if (n * is_neg > 2147483647)
			return (-1);
		else if (n * is_neg < -2147483648)
			return (0);
	}
	if (is_neg)
		return (n * is_neg);
	else
		return (n);
}
