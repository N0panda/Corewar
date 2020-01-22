/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:42:33 by mdelory           #+#    #+#             */
/*   Updated: 2019/02/19 04:03:33 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				vector_in(t_vector *v, void *ptr)
{
	size_t		i;

	i = 0;
	if (v && v->data)
		while (i < v->count)
		{
			if (v->data[i] == ptr)
				return (1);
			i++;
		}
	return (0);
}
