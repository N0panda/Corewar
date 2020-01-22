/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lk_lst_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 20:39:10 by mdelory           #+#    #+#             */
/*   Updated: 2018/08/11 04:04:11 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				lk_lst_iter(t_lklist *lst, void (*f)(t_lknode *el))
{
	t_lknode			*el;

	if (!lst || !f)
		return ;
	el = lst->head;
	while (el)
	{
		(*f)(el);
		el = el->next;
	}
}
