/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:03:45 by mdelory           #+#    #+#             */
/*   Updated: 2018/11/05 11:55:08 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_sprintf(char *str, char *format, ...)
{
	va_list		ap;
	int			pf_size;

	if (!format)
		return (-1);
	va_start(ap, format);
	pf_size = ft_vsprintf(str, format, ap);
	va_end(ap);
	return (pf_size);
}
