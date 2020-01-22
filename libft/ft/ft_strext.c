/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 18:58:46 by mdelory           #+#    #+#             */
/*   Updated: 2018/05/24 13:38:24 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strext(char **dst, const char *src)
{
	char		*tmp;

	if (!(*dst) || !src)
		return (NULL);
	tmp = (*dst);
	if (!((*dst) = ft_strjoin((*dst), src)))
		return (NULL);
	ft_strdel(&tmp);
	return (*dst);
}
