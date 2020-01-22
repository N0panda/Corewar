/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lk_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 17:23:02 by mdelory           #+#    #+#             */
/*   Updated: 2018/08/11 04:04:11 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lknode			*lk_lst_new(void *content, size_t size)
{
	t_lknode		*new;

	if ((new = (t_lknode *)ft_memalloc(sizeof(t_lknode))))
	{
		new->content = NULL;
		new->content_size = 0;
		new->prev = NULL;
		new->next = NULL;
		if (content)
		{
			if ((new->content = ft_memalloc(size)))
			{
				ft_memcpy(new->content, content, size);
				new->content_size = size;
			}
		}
	}
	return (new);
}
