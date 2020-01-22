/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 20:32:52 by mdelory           #+#    #+#             */
/*   Updated: 2018/05/24 13:38:23 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_lstaddnew(t_list **alst, void const *cntt, size_t cntt_size)
{
	t_list		*lst;

	if (!(lst = ft_lstnew(cntt, cntt_size)))
		return (0);
	ft_lstadd(alst, lst);
	return (1);
}
