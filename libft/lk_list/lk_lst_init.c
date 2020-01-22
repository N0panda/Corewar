/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lk_lst_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:53:45 by mdelory           #+#    #+#             */
/*   Updated: 2018/08/11 04:03:16 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lklist			*lk_lst_init(void)
{
	t_lklist		*lst;

	lst = NULL;
	if ((lst = (t_lklist *)ft_memalloc(sizeof(t_lklist))))
	{
		lst->count = 0;
		lst->cur = NULL;
		lst->head = NULL;
		lst->tail = NULL;
	}
	return (lst);
}
