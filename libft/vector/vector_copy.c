/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:05:06 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/18 13:08:49 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int				vector_copy(t_vector *dst, t_vector *src)
{
	if (!dst || !src)
		return (0);
	if (dst->data)
		free(dst->data);
	if (!(dst->data = (void **)malloc(sizeof(void *) * src->count)))
		return (0);
	ft_memcpy(dst->data, src->data, sizeof(void *) * src->count);
	dst->count = src->count;
	dst->size = dst->count;
	return (1);
}
