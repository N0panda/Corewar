/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:20:46 by mdelory           #+#    #+#             */
/*   Updated: 2019/01/24 15:54:47 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		vector_add(t_vector *v, void *data)
{
	void	**ptr;

	if (!v || !v->data)
		return (0);
	if (v->count == v->size)
	{
		if (!(ptr = (void **)ft_memalloc(sizeof(void *) * v->size * 2)))
			return (0);
		v->size *= 2;
		ft_memcpy(ptr, v->data, sizeof(void *) * v->count);
		free(v->data);
		v->data = ptr;
	}
	v->data[v->count] = data;
	v->count++;
	return (1);
}
