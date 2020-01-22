/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 21:17:49 by mdelory           #+#    #+#             */
/*   Updated: 2018/08/11 04:05:44 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			read_number(char const *str)
{
	unsigned int	n;

	n = 0;
	while (ft_isdigit(*str))
	{
		n = n * 10 + ((*str) - '0');
		str++;
	}
	return (n);
}

int					ft_atoi(char const *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' && ft_isdigit(*(str + 1)))
		return (-(read_number(str + 1)));
	if (*str == '+' && ft_isdigit(*(str + 1)))
		return (read_number(str + 1));
	if (ft_isdigit(*str))
		return (read_number(str));
	return (0);
}
