/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 18:48:26 by mdelory           #+#    #+#             */
/*   Updated: 2018/10/04 16:59:39 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_asprintf(char **ret, char *format, ...)
{
	va_list		ap;
	int			pf_size;

	if (!format)
		return (-1);
	va_start(ap, format);
	pf_size = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (pf_size);
}
