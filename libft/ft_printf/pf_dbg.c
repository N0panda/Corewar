/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dbg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:53:42 by mdelory           #+#    #+#             */
/*   Updated: 2018/04/14 15:59:10 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					pfdbg_printfc(t_fmt *fc)
{
	if (!fc)
		return (ft_putendl("NULL"));
	ft_putendl("========== V ==========");
	ft_putstr("Attributes      : ");
	ft_putnbr(fc->attr);
	ft_putchar('\n');
	ft_putstr("Minimum Size    : ");
	ft_putnbr(fc->min_size);
	ft_putchar('\n');
	ft_putstr("Precision       : ");
	ft_putnbr(fc->precision);
	ft_putchar('\n');
	ft_putstr("Length Modifier : ");
	ft_putnbr(fc->lmod);
	ft_putchar('\n');
	ft_putstr("Conversion      : ");
	ft_putchar(fc->conv);
	ft_putchar('\n');
}

void					pfdbg_printbuffer(t_buffer *buffer)
{
	ft_putchar('\n');
	ft_putendl("[BUFFER]");
	while (buffer)
	{
		write(0, buffer->buffer, buffer->index);
		buffer = buffer->next;
	}
	ft_putendl("----------");
}
