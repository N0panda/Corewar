/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ustring_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 18:24:17 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/18 12:30:45 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		pf_wcharlen(wchar_t wc)
{
	int			wlen;

	wlen = 1;
	while (wc /= 2)
		wlen++;
	if (wlen < 8)
		return (1);
	else if (wlen < 12)
		return (2);
	else if (wlen < 17)
		return (3);
	return (4);
}

static int		pf_wstrlen(wchar_t *wstr, int precision)
{
	int wlen;
	int nlen;

	wlen = 0;
	while (*wstr)
	{
		nlen = pf_wcharlen(*wstr);
		if (precision < 0 || precision - wlen >= nlen)
			wlen += nlen;
		else
			break ;
		wstr++;
	}
	return (wlen);
}

static void		pf_put_wchar(wchar_t wc, t_buffer **buffer)
{
	int			wlen;

	wlen = pf_wcharlen(wc);
	if (wlen == 1 && MB_CUR_MAX >= 1)
	{
		pf_putchar_buffer(0 + (0x7F & wc), buffer);
	}
	else if (wlen == 2 && MB_CUR_MAX >= 2)
	{
		pf_putchar_buffer(192 + ((0x7C0 & wc) >> 6), buffer);
		pf_putchar_buffer(128 + (0x3F & wc), buffer);
	}
	else if (wlen == 3 && MB_CUR_MAX >= 3)
	{
		pf_putchar_buffer(224 + ((0xF000 & wc) >> 12), buffer);
		pf_putchar_buffer(128 + ((0xFC0 & wc) >> 6), buffer);
		pf_putchar_buffer(128 + (0x3F & wc), buffer);
	}
	else if (MB_CUR_MAX == 4)
	{
		pf_putchar_buffer(240 + ((0x1C0000 & wc) >> 18), buffer);
		pf_putchar_buffer(128 + ((0x3F000 & wc) >> 12), buffer);
		pf_putchar_buffer(128 + ((0xFC0 & wc) >> 6), buffer);
		pf_putchar_buffer(128 + (0x3F & wc), buffer);
	}
}

static void		pf_put_wstr(t_fmt *fc, wchar_t *wstr, t_buffer **buffer)
{
	int			len;

	while (*wstr)
	{
		len = pf_wcharlen(*wstr);
		if (fc->precision >= 0 && len > fc->precision)
			break ;
		pf_put_wchar(*wstr, buffer);
		fc->precision -= len;
		wstr++;
	}
}

int				pf_wstring_conv(t_fmt *fc, va_list ap, t_buffer **buffer)
{
	wchar_t		*str;
	wchar_t		c;
	int			slen;

	if (fc->conv == 'S')
	{
		if (!(str = va_arg(ap, wchar_t *)))
			str = L"(null)";
		slen = pf_wstrlen(str, fc->precision);
	}
	else
	{
		c = (wchar_t)(va_arg(ap, int));
		slen = 1;
	}
	if (!(fc->attr & ATTR_MINUS))
		pf_write_padding(fc, slen, buffer);
	if (fc->conv == 'C')
		pf_put_wchar(c, buffer);
	else
		pf_put_wstr(fc, str, buffer);
	if (fc->attr & ATTR_MINUS)
		pf_write_padding(fc, slen, buffer);
	return (1);
}
