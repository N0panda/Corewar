/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:21:49 by mdelory           #+#    #+#             */
/*   Updated: 2018/11/22 11:24:11 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		vector_set(t_vector *v, unsigned int index, void *data)
{
	if (!v || index > v->count || !v->data)
		return (1);
	v->data[index] = data;
	return (0);
}
