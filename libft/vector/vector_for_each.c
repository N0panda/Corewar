/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_for_each.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:18:44 by mdelory           #+#    #+#             */
/*   Updated: 2019/09/14 23:26:04 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void				vector_for_each(t_vector *v, void (*f)(void *))
{
	unsigned int	i;

	i = 0;
	if (!v || !v->data)
		return ;
	while (i < v->count)
	{
		f(v->data[i]);
		i++;
	}
}
