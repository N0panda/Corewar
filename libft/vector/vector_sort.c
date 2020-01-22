/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:02:15 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/18 13:09:27 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

static void			sort_swap(void **d, int i, int j)
{
	void			*ptr;

	ptr = d[i];
	d[i] = d[j];
	d[j] = ptr;
}

static int			sort_partition(void **d, int low, int high, \
												int (*cmp)(void *, void *))
{
	int				p;
	int				l;
	int				h;

	l = low;
	h = high;
	p = low;
	while (l < h)
	{
		while (cmp(d[l], d[p]))
			l++;
		while (h > l && !cmp(d[h], d[p]))
			h--;
		if (l < h)
			sort_swap(d, l, h);
	}
	sort_swap(d, p, h);
	return (h);
}

static	void		quick_sort_recursive(void **d, int low, int high, \
												int (*cmp)(void *, void *))
{
	int				p;

	if (low < high)
	{
		p = sort_partition(d, low, high, cmp);
		quick_sort_recursive(d, low, p - 1, cmp);
		quick_sort_recursive(d, p + 1, high, cmp);
	}
}

void				vector_sort(t_vector *v, int (*cmp)(void *, void *))
{
	quick_sort_recursive(v->data, 0, v->count - 1, cmp);
}
