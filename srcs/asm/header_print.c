/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:00:40 by ythomas           #+#    #+#             */
/*   Updated: 2019/10/22 15:34:43 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			header_add_comment(char *str, int fd)
{
	int						len;
	const unsigned char		c = 0;

	len = ft_strlen(str);
	write(fd, str, len);
	while (++len <= COMMENT_LENGTH)
		write(fd, &c, 1);
	return (0);
}

int			header_add_name(char *str, int fd)
{
	int						len;
	const unsigned char		c = 0;

	len = ft_strlen(str);
	write(fd, str, len);
	while (++len <= PROG_NAME_LENGTH)
		write(fd, &c, 1);
	return (0);
}

int			header_add_magic_number(int fd)
{
	const int nb = COREWAR_EXEC_MAGIC;

	reverse_writing(fd, nb, 4);
	return (0);
}
