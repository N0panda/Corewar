/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:00:57 by mdelory           #+#    #+#             */
/*   Updated: 2018/09/29 15:55:07 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				pf_string_handler(t_fmt *fc, va_list ap, t_buffer **buffer)
{
	if (fc->conv == 's' || fc->conv == 'c' || fc->conv == '%')
		return (pf_string_conv(fc, ap, buffer));
	if (fc->conv == 'S' || fc->conv == 'C')
		return (pf_wstring_conv(fc, ap, buffer));
	return (0);
}

int				pf_string_conv(t_fmt *fc, va_list ap, t_buffer **buffer)
{
	char		*str;
	char		c;
	int			slen;

	if (fc->conv == 's')
	{
		if (!(str = va_arg(ap, char *)))
			str = "(null)";
		slen = ft_strlen(str);
		if (fc->precision >= 0 && fc->precision < slen)
			slen = fc->precision;
	}
	else
	{
		c = (fc->conv == '%' ? '%' : (char)(va_arg(ap, int)));
		str = &c;
		slen = 1;
	}
	if (!(fc->attr & ATTR_MINUS))
		pf_write_padding(fc, slen, buffer);
	pf_fill_buffer(str, slen, buffer);
	if (fc->attr & ATTR_MINUS)
		pf_write_padding(fc, slen, buffer);
	return (1);
}

int				pf_invalid_conv(t_fmt *fc, char c, t_buffer **buffer)
{
	if (!(fc->attr & ATTR_MINUS))
		pf_write_padding(fc, 1, buffer);
	pf_fill_buffer(&c, 1, buffer);
	if (fc->attr & ATTR_MINUS)
		pf_write_padding(fc, 1, buffer);
	return (1);
}
