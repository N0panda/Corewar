/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:12:57 by mdelory           #+#    #+#             */
/*   Updated: 2019/10/24 14:53:56 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnew(size_t size)
{
	char		*fresh;

	fresh = (char *)ft_memalloc(size + 1);
	if (!fresh)
		return (NULL);
	ft_bzero(fresh, size + 1);
	return (fresh);
}
