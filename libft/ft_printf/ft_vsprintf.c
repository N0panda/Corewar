/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 19:07:35 by mdelory           #+#    #+#             */
/*   Updated: 2018/11/05 11:57:34 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_vsprintf(char *str, char *format, va_list ap)
{
	char		*out;
	int			pf_size;

	if (!str)
		return (-1);
	out = NULL;
	pf_size = ft_vasprintf(&out, format, ap);
	ft_memcpy(str, out, pf_size);
	free(out);
	return (pf_size);
}
