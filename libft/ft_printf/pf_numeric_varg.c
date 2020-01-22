/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_numeric_varg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:40:22 by mdelory           #+#    #+#             */
/*   Updated: 2018/10/12 17:46:22 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		pf_signed_mod(int lmod, va_list ap)
{
	if (lmod & LMOD_H)
		return ((short)va_arg(ap, int));
	if (lmod & LMOD_L)
		return (va_arg(ap, long));
	if (lmod & LMOD_J)
		return (va_arg(ap, intmax_t));
	if (lmod & LMOD_Z)
		return (va_arg(ap, size_t));
	if (lmod & LMOD_HH)
		return ((char)va_arg(ap, int));
	if (lmod & LMOD_LL)
		return (va_arg(ap, long long));
	return (va_arg(ap, int));
}

uintmax_t		pf_unsigned_mod(int lmod, va_list ap)
{
	if (lmod & LMOD_H)
		return ((unsigned short)va_arg(ap, int));
	if (lmod & LMOD_L)
		return (va_arg(ap, unsigned long));
	if (lmod & LMOD_J)
		return (va_arg(ap, uintmax_t));
	if (lmod & LMOD_Z)
		return (va_arg(ap, size_t));
	if (lmod & LMOD_HH)
		return ((unsigned char)va_arg(ap, int));
	if (lmod & LMOD_LL)
		return (va_arg(ap, unsigned long long));
	return (va_arg(ap, unsigned int));
}
