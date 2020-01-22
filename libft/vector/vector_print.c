/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:22:16 by mdelory           #+#    #+#             */
/*   Updated: 2018/11/22 15:31:12 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

static void	print(void *e)
{
	ft_printf("%p\n", e);
}

void		vector_print(t_vector *v)
{
	vector_for_each(v, print);
}
