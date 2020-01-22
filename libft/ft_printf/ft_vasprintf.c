/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 18:53:14 by mdelory           #+#    #+#             */
/*   Updated: 2018/10/04 16:36:12 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_vasprintf(char **ret, char *format, va_list ap)
{
	t_buffer	*buffer;
	int			pf_size;

	buffer = NULL;
	if (!format)
		return (-1);
	if (!(buffer = pf_create_buffer(&buffer)))
		return (-1);
	while (*format)
	{
		if (*format == '%')
			pf_parse(&format, ap, &buffer);
		else
			format += pf_fill_buffer(format, 1, &buffer);
	}
	pf_size = pf_join_buffer(buffer, ret);
	return (pf_size);
}
