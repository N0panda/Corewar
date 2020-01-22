/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:00:59 by mdelory           #+#    #+#             */
/*   Updated: 2019/02/28 12:41:16 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_max(int **m, int w, int h)
{
	int			max;
	int			i;
	int			j;

	max = 0;
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			max = ft_max(max, ft_numlen(m[i][j]));
			j++;
		}
		i++;
	}
	return (max);
}

static void		print_header(int w, int prec_side, int max)
{
	int			i;

	i = 0;
	prec_side++;
	while (prec_side--)
		ft_putchar(' ');
	while (w--)
	{
		ft_printf(" %*d", max, i);
		if (++i == 10)
			i = 0;
	}
	ft_putstr("\n");
}

void			ft_print_matrix(int **m, int w, int h)
{
	int			i;
	int			j;
	int			max;
	int			prec_side;

	i = 0;
	max = get_max(m, w, h);
	prec_side = ft_numlen(h);
	print_header(w, prec_side, max);
	while (i < h)
	{
		j = 0;
		ft_printf("%.*d ", prec_side, i);
		while (j < w)
		{
			ft_printf("|%*d", max, m[i][j]);
			j++;
		}
		ft_putstr("|\n");
		i++;
	}
}
