/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:40:55 by mdelory           #+#    #+#             */
/*   Updated: 2018/05/24 13:38:24 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*reverse(t_list *lst, t_list *prev)
{
	t_list		*tmp;

	tmp = lst;
	if (lst->next)
		lst = reverse(lst->next, lst);
	tmp->next = prev;
	return (lst);
}

t_list			*ft_lstrev(t_list *lst)
{
	return (reverse(lst, NULL));
}
