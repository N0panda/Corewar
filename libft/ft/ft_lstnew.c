/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:46:16 by mdelory           #+#    #+#             */
/*   Updated: 2018/05/24 13:38:23 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*lst;

	lst = (t_list *)ft_memalloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	if (!content)
	{
		lst->content = NULL;
		lst->content_size = 0;
		return (lst);
	}
	lst->content = ft_memalloc(content_size);
	ft_memcpy(lst->content, (void *)content, content_size);
	lst->content_size = content_size;
	return (lst);
}
