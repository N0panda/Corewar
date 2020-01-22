/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:08:58 by mdelory           #+#    #+#             */
/*   Updated: 2019/10/09 16:15:33 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		read_line(const int fd, char **buff_tab)
{
	char		*o;
	char		*buff;
	char		*t;
	int			rd;

	rd = 1;
	if (!(buff = ft_strnew(GNL_BUFF_SIZE)))
		return (-1);
	while (!(o = ft_strchr(buff_tab[fd], '\n')))
	{
		if ((rd = read(fd, buff, GNL_BUFF_SIZE)) <= 0)
			break ;
		buff[rd] = '\0';
		t = buff_tab[fd];
		if (!(buff_tab[fd] = ft_strjoin(t, buff)))
			return (-1);
		ft_strdel(&t);
	}
	ft_strdel(&buff);
	return ((rd <= 0 ? rd : (o - buff_tab[fd]) + 1));
}

int				get_next_line(const int fd, char **line)
{
	static char *buff_tab[OPEN_MAX];
	char		*t;
	int			offset;

	if (fd < 0 || fd > OPEN_MAX || !line)
		return (-1);
	if (!buff_tab[fd] && !(buff_tab[fd] = ft_strnew(0)))
		return (-1);
	if ((offset = read_line(fd, buff_tab)) == -1)
		return (-1);
	if (!offset)
	{
		if (!(*line = ft_strdup(buff_tab[fd])))
			return (-1);
		ft_strdel(&buff_tab[fd]);
		return (!!ft_strlen(*line));
	}
	if (!(*line = ft_strsub(buff_tab[fd], 0, offset - 1)))
		return (-1);
	t = buff_tab[fd];
	if (!(buff_tab[fd] = ft_strdup(t + offset)))
		return (-1);
	ft_strdel(&t);
	return (1);
}
