/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_numeric_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:22:05 by mdelory           #+#    #+#             */
/*   Updated: 2018/10/12 17:47:27 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		pf_fix_precision(t_fmt *fc, uintmax_t value)
{
	if (fc->conv == 'o' && value && fc->attr & ATTR_HASH &&\
			fc->precision <= ft_numlen_base(value, 8))
		fc->precision = ft_numlen_base(value, 8) + 1;
	else if (fc->conv == 'o' && fc->attr & ATTR_HASH && !value &&\
			!fc->precision)
		fc->precision = 1;
	else if (fc->precision == -1 && !value)
		fc->precision = 1;
}

int				pf_numeric_handler(t_fmt *fc, va_list ap, t_buffer **buffer)
{
	uintmax_t	value;
	int			len;

	if (ft_strchr(SIGNED_CONV, fc->conv))
		value = pf_signed_mod(fc->lmod, ap);
	else
		value = pf_unsigned_mod(fc->lmod, ap);
	pf_fix_precision(fc, value);
	len = pf_prefix_len(fc, value);
	len += pf_numeric_len(fc->conv, fc->precision, value);
	if (fc->attr & ATTR_ZERO)
		pf_write_prefix(fc, value, buffer);
	if (!(fc->attr & ATTR_MINUS) || fc->attr & ATTR_ZERO)
		len += pf_write_padding(fc, len, buffer);
	if (!(fc->attr & ATTR_ZERO))
		pf_write_prefix(fc, value, buffer);
	pf_numeric_conv(fc->conv, value, fc->precision, buffer);
	if (fc->attr & ATTR_MINUS)
		pf_write_padding(fc, len, buffer);
	return (0);
}

void			pf_numeric_conv(char conv, uintmax_t value, int prec, \
		t_buffer **buffer)
{
	int			base;
	char		c;
	char		b;

	base = (conv == 'o' ? 8 : 10);
	base = (conv == 'x' || conv == 'X' || conv == 'p' ? 16 : base);
	base = (conv == 'b' ? 2 : base);
	if (ft_strchr(SIGNED_CONV, conv) && (intmax_t)value < 0)
		value = -value;
	b = (conv == 'X' ? 'A' : 'a');
	if (value || prec > 0)
	{
		pf_numeric_conv(conv, value / base, prec - 1, buffer);
		c = (value % base) + (value % base > 9 ? b - 10 : '0');
		pf_fill_buffer(&c, 1, buffer);
	}
}

int				pf_numeric_len(char conv, int prec, uintmax_t value)
{
	int			len;
	int			base;

	len = 0;
	base = (conv == 'o' ? 8 : 10);
	base = (conv == 'x' || conv == 'X' || conv == 'p' ? 16 : base);
	base = (conv == 'b' ? 2 : base);
	if (ft_strchr(SIGNED_CONV, conv) && (intmax_t)value < 0)
		value = -value;
	while (value || prec > 0)
	{
		len++;
		prec--;
		value /= base;
	}
	return (len);
}
