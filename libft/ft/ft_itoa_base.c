/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:22:05 by mdelory           #+#    #+#             */
/*   Updated: 2018/07/28 18:31:05 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base(intmax_t nbr, int base)
{
	int			len;
	int			sign;
	char		*str;

	sign = 0;
	len = 1;
	if (nbr < 0)
	{
		if (base == 10)
			sign = 1;
		nbr = -nbr;
	}
	len = ft_numlen_base(nbr, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + sign) + 1)))
		return (NULL);
	str[len + sign] = '\0';
	while (len--)
	{
		str[len + sign] = (nbr % base) + (nbr % base > 9 ? 'A' - 10 : '0');
		nbr = nbr / base;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
