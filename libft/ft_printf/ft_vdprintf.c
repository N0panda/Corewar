/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:37:05 by mdelory           #+#    #+#             */
/*   Updated: 2018/10/04 16:37:03 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_vdprintf(int fd, char *format, va_list ap)
{
	char		*out;
	int			pf_size;

	out = NULL;
	pf_size = ft_vasprintf(&out, format, ap);
	write(fd, out, pf_size);
	free(out);
	return (pf_size);
}
