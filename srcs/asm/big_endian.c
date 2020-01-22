/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_endian.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:56:51 by ythomas           #+#    #+#             */
/*   Updated: 2019/10/21 19:54:48 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		reverse_writing(int fd, int value, int octet)
{
	int				i;
	unsigned char	c;

	i = octet;
	while (i > 0)
	{
		c = ((unsigned char *)&(value))[i - 1];
		write(fd, &c, 1);
		i--;
	}
}

void		reverse_writing_two(int fd, int value, int octet)
{
	int				end;
	int				start;
	unsigned char	tmp;

	end = octet;
	start = -1;
	while (++start < --end)
	{
		tmp = ((unsigned char *)&(value))[end];
		((unsigned char *)&(value))[end] = ((unsigned char *)&(value))[start];
		((unsigned char *)&(value))[start] = start;
	}
	write(fd, &value, octet);
}
