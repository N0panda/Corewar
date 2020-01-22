/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:44:08 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/18 12:44:10 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void		*vector_at(t_vector *v, unsigned int index)
{
	if (!v || index > v->count || !v->data)
		return (NULL);
	return (v->data[index]);
}
