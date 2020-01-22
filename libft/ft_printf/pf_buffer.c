/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:42:52 by mdelory           #+#    #+#             */
/*   Updated: 2018/09/29 13:29:44 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				pf_fill_buffer(char *str, int size, t_buffer **buffer)
{
	t_buffer	*cbuffer;
	int			i;

	i = 0;
	cbuffer = *buffer;
	while (i < size)
	{
		cbuffer->buffer[cbuffer->index] = *str;
		str++;
		cbuffer->index++;
		i++;
		if (cbuffer->index == PF_BUFF_SIZE - 1)
		{
			if (!(cbuffer = pf_create_buffer(buffer)))
				return (-1);
		}
	}
	return (size);
}

int				pf_putchar_buffer(char c, t_buffer **buffer)
{
	return (pf_fill_buffer(&c, 1, buffer));
}

t_buffer		*pf_create_buffer(t_buffer **buffer)
{
	t_buffer	*nbuffer;

	if (!(nbuffer = (t_buffer *)malloc(sizeof(t_buffer))))
		return (NULL);
	ft_memset(nbuffer->buffer, 0, PF_BUFF_SIZE);
	nbuffer->index = 0;
	nbuffer->next = *buffer;
	*buffer = nbuffer;
	return (nbuffer);
}

int				pf_join_buffer(t_buffer *buffer, char **out)
{
	t_buffer	*tbuffer;
	int			size;
	char		*str;

	size = 0;
	buffer = pf_reverse_buffer(buffer, NULL);
	tbuffer = buffer;
	while (tbuffer)
	{
		size += tbuffer->index;
		tbuffer = tbuffer->next;
	}
	str = ft_strnew(size);
	*out = str;
	while (buffer)
	{
		if (buffer->index == PF_BUFF_SIZE)
			buffer->index--;
		ft_memcpy(str, buffer->buffer, buffer->index);
		str += buffer->index;
		tbuffer = buffer;
		buffer = buffer->next;
		free(tbuffer);
	}
	return (size);
}

t_buffer		*pf_reverse_buffer(t_buffer *buffer, t_buffer *null)
{
	t_buffer	*tmp;

	tmp = buffer;
	if (buffer->next)
		buffer = pf_reverse_buffer(buffer->next, buffer);
	tmp->next = null;
	return (buffer);
}
