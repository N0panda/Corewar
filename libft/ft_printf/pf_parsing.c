/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 22:01:07 by mdelory           #+#    #+#             */
/*   Updated: 2018/09/29 17:05:00 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				pf_parse(char **format, va_list ap, t_buffer **buffer)
{
	char		*ptr;
	t_fmt		fc;

	fc.attr = 0;
	fc.min_size = 0;
	fc.precision = -1;
	fc.lmod = 0;
	ptr = NULL;
	(*format)++;
	while (**format && ptr != *format)
	{
		ptr = *format;
		pf_parse_fmt(&fc, ap, format);
	}
	if (!(**format))
		return (0);
	fc.conv = **format;
	if (fc.precision < 0)
		fc.precision = -1;
	pf_fix_fmt(&fc);
	(*format)++;
	if (!ft_strchr(ALL_CONV, fc.conv))
		return (pf_invalid_conv(&fc, fc.conv, buffer));
	return (pf_conv(&fc, ap, buffer));
}

void			pf_parse_fmt(t_fmt *fc, va_list ap, char **fmt)
{
	pf_parse_attr(fmt, fc);
	if (ft_isdigit(**fmt) && **fmt != '0')
	{
		fc->min_size = ft_atoi(*fmt);
		(*fmt) += ft_numlen(fc->min_size);
	}
	else if (**fmt == '*' && (*(++*fmt) || !(**fmt)))
		fc->min_size = va_arg(ap, int);
	if (**fmt == '.')
	{
		fc->precision = 0;
		(*fmt)++;
		if (ft_isdigit(**fmt))
		{
			fc->precision = ft_atoi(*fmt);
			(*fmt) += ft_numlen(fc->precision);
		}
		else if (**fmt == '*' && (*(++*fmt) || !(**fmt)))
			fc->precision = va_arg(ap, int);
	}
	pf_parse_lmod(fmt, fc);
}

void			pf_parse_lmod(char **fmt, t_fmt *c)
{
	if (**fmt == 'h')
	{
		if (*(*fmt + 1) == 'h')
		{
			c->lmod = (c->lmod == 0 ? LMOD_HH : LMOD_LL);
			(*fmt)++;
		}
		else
			c->lmod = (c->lmod == 0 ? LMOD_H : LMOD_LL);
	}
	else if (**fmt == 'l')
		c->lmod = (c->lmod == 0 ? LMOD_L : LMOD_LL);
	else if (**fmt == 'j')
		c->lmod = (c->lmod == 0 ? LMOD_J : LMOD_LL);
	else if (**fmt == 'z')
		c->lmod = (c->lmod == 0 ? LMOD_Z : LMOD_LL);
	else
		return ;
	(*fmt)++;
}

void			pf_parse_attr(char **fmt, t_fmt *c)
{
	if (**fmt == '#')
		c->attr |= ATTR_HASH;
	else if (**fmt == '0')
		c->attr |= ATTR_ZERO;
	else if (**fmt == '-')
		c->attr |= ATTR_MINUS;
	else if (**fmt == ' ')
		c->attr |= ATTR_SPACE;
	else if (**fmt == '+')
		c->attr |= ATTR_PLUS;
	else
		return ;
	(*fmt)++;
}

void			pf_fix_fmt(t_fmt *fc)
{
	if (ft_strchr(ALL_ALIAS, fc->conv))
	{
		fc->conv = ft_tolower(fc->conv);
		fc->lmod = LMOD_L;
	}
	if (fc->attr & ATTR_ZERO && ft_strchr(NUM_CONV, fc->conv) \
			&& fc->precision != -1)
		fc->attr -= ATTR_ZERO;
	if (fc->attr & ATTR_ZERO && fc->attr & ATTR_MINUS)
		fc->attr -= ATTR_ZERO;
	if (fc->attr & ATTR_PLUS && fc->attr & ATTR_SPACE)
		fc->attr -= ATTR_SPACE;
	if (fc->conv == 's' && fc->lmod == LMOD_L)
		fc->conv = 'S';
	if (fc->conv == 'c' && fc->lmod == LMOD_L)
		fc->conv = 'C';
	if (fc->conv == 'c' || fc->conv == 'C' || fc->conv == '%')
		fc->precision = -1;
	if (fc->conv == 'p')
		fc->lmod = LMOD_L;
	if (fc->min_size < 0)
	{
		fc->attr |= ATTR_MINUS;
		fc->min_size = -fc->min_size;
	}
}
