/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:09:07 by mdelory           #+#    #+#             */
/*   Updated: 2018/11/05 11:57:08 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_vsnprintf(char *str, size_t size, char *format, va_list ap)
{
	char		*out;
	int			pf_size;

	out = NULL;
	pf_size = ft_vasprintf(&out, format, ap);
	if ((size_t)pf_size < size)
		size = pf_size;
	ft_memcpy(str, out, size);
	free(out);
	return (size);
}
