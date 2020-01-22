/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:23:57 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/20 17:04:26 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void		vector_free(t_vector *v, unsigned int index)
{
	if (!v || index > v->count || !v->data)
		return ;
	free(v->data[index]);
}
