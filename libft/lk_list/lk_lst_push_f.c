/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lk_lst_push_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 19:23:41 by mdelory           #+#    #+#             */
/*   Updated: 2018/08/11 04:04:11 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lknode			*lk_lst_push_f(t_lklist *lst, t_lknode *new)
{
	if (lst == NULL || new == NULL)
		return (NULL);
	new->header = lst;
	new->next = lst->head;
	if (lst->head)
		lst->head->prev = new;
	lst->head = new;
	if (lst->tail == NULL)
		lst->tail = new;
	if (lst->cur == NULL)
		lst->cur = new;
	lst->count++;
	return (new);
}
