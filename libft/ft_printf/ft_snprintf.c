/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 16:58:08 by mdelory           #+#    #+#             */
/*   Updated: 2018/10/04 17:00:14 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_snprintf(char *str, size_t size, char *format, ...)
{
	va_list		ap;
	int			pf_size;

	if (!format)
		return (-1);
	va_start(ap, format);
	pf_size = ft_vsnprintf(str, size, format, ap);
	va_end(ap);
	return (pf_size);
}
