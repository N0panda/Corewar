/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 13:32:49 by mdelory           #+#    #+#             */
/*   Updated: 2018/10/04 16:33:54 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(char *format, ...)
{
	va_list		ap;
	int			pf_size;

	if (!format)
		return (-1);
	va_start(ap, format);
	pf_size = ft_vprintf(format, ap);
	va_end(ap);
	return (pf_size);
}
