/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:23:04 by mdelory           #+#    #+#             */
/*   Updated: 2019/01/24 15:48:44 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		vector_init(t_vector *v)
{
	if (!v)
		return (0);
	v->size = 0;
	v->count = 0;
	if (!(v->data = (void **)ft_memalloc(sizeof(void *) * VECTOR_SIZE)))
		return (0);
	v->size = VECTOR_SIZE;
	return (1);
}
