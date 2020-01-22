/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 18:31:47 by mdelory           #+#    #+#             */
/*   Updated: 2018/10/12 17:02:20 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				pf_conv(t_fmt *fc, va_list ap, t_buffer **buffer)
{
	if (ft_strchr(NUM_CONV, fc->conv))
		return (pf_numeric_handler(fc, ap, buffer));
	if (ft_strchr(STRING_CONV, fc->conv))
		return (pf_string_handler(fc, ap, buffer));
	return (0);
}

int				pf_write_padding(t_fmt *fc, int clen, t_buffer **buffer)
{
	int			plen;
	char		pad;

	pad = ' ';
	if (fc->attr & ATTR_ZERO)
		pad = '0';
	plen = 0;
	while (clen < fc->min_size)
	{
		pf_fill_buffer(&pad, 1, buffer);
		clen++;
		plen++;
	}
	return (plen);
}

int				pf_write_prefix(t_fmt *fc, uintmax_t value, t_buffer **buffer)
{
	if (ft_strchr(SIGNED_CONV, fc->conv) && (intmax_t)value < 0)
		return (pf_fill_buffer("-", 1, buffer));
	if (fc->attr & ATTR_HASH && fc->conv == 'b')
		return (pf_fill_buffer("0b", 2, buffer));
	if ((fc->attr & ATTR_HASH && fc->conv == 'x' && value) || fc->conv == 'p')
		return (pf_fill_buffer("0x", 2, buffer));
	if (fc->attr & ATTR_HASH && fc->conv == 'X' && value)
		return (pf_fill_buffer("0X", 2, buffer));
	if (fc->attr & ATTR_SPACE && ft_strchr(SIGNED_CONV, fc->conv) \
			&& (intmax_t)value >= 0)
		return (pf_fill_buffer(" ", 1, buffer));
	if (fc->attr & ATTR_PLUS && ft_strchr(SIGNED_CONV, fc->conv) \
			&& (intmax_t)value >= 0)
		return (pf_fill_buffer("+", 1, buffer));
	return (0);
}

int				pf_prefix_len(t_fmt *fc, uintmax_t value)
{
	if (fc->attr & ATTR_HASH && fc->conv == 'b')
		return (2);
	if ((fc->attr & ATTR_HASH && fc->conv == 'x' && value) || fc->conv == 'p')
		return (2);
	if (fc->attr & ATTR_HASH && fc->conv == 'X' && value)
		return (2);
	if (fc->attr & ATTR_SPACE && ft_strchr(SIGNED_CONV, fc->conv) \
			&& (intmax_t)value >= 0)
		return (1);
	if (fc->attr & ATTR_PLUS && ft_strchr(SIGNED_CONV, fc->conv) \
			&& (intmax_t)value >= 0)
		return (1);
	if (ft_strchr(SIGNED_CONV, fc->conv) && (intmax_t)value < 0)
		return (1);
	return (0);
}
