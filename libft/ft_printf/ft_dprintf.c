/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:15:28 by mdelory           #+#    #+#             */
/*   Updated: 2018/10/04 16:33:30 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_dprintf(int fd, char *format, ...)
{
	va_list		ap;
	int			pf_size;

	if (!format)
		return (-1);
	va_start(ap, format);
	pf_size = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (pf_size);
}
