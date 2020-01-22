/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:49:34 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/18 21:41:42 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void			vector_clear(t_vector *v)
{
	if (!v)
		return ;
	ft_bzero(v->data, sizeof(void *) * v->count);
	v->count = 0;
}
