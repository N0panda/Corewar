/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:33:40 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/28 18:10:14 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			usage(void)
{
	ft_putendl("\
Usage: corewar [options] champions ...\n\
	\n\
Arguments:\n\
	champions ...      a list of champions (.cor file)\n\
	\n\
Options:\n\
	-h                 show this help message and exit\n\
	-n id              set the next player number to id\n\
	-d cycle           exit at given cycle and dump the memory on stderr\
	");
	exit(0);
}

int				exit_error(char *fmt, ...)
{
	va_list		vl;

	va_start(vl, fmt);
	if (!fmt)
		fmt = "Unknown error occured";
	if (errno)
		fmt = strerror(errno);
	write(2, "[-]Error: ", 10);
	ft_vdprintf(2, fmt, vl);
	va_end(vl);
	write(2, "\n", 1);
	exit(1);
}
