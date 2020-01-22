/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:24:00 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/20 17:16:24 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		vector_delete(t_vector *v, unsigned int index)
{
	unsigned int	i;
	unsigned int	j;

	if (!v || index >= v->count || !v->data)
		return (0);
	i = index;
	j = index;
	vector_free(v, index);
	while (++i < v->count)
	{
		v->data[j] = v->data[i];
		j++;
	}
	v->count--;
	return (1);
}
