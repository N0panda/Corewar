/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:15:22 by mdelory           #+#    #+#             */
/*   Updated: 2019/02/24 16:10:21 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		*matrix_row(int w, int d)
{
	int			*row;
	int			i;

	i = 0;
	if ((row = (int *)malloc(sizeof(int) * w)))
		while (i < w)
		{
			row[i] = d;
			i++;
		}
	return (row);
}

int				**ft_matrix(int w, int h, int d)
{
	int			**mat;
	int			i;

	mat = NULL;
	i = 0;
	if (w > 0 && h > 0 && (mat = (int **)malloc(sizeof(int *) * h)))
		while (mat && i < h)
			if (!(mat[i++] = matrix_row(w, d)))
			{
				while (i--)
					free(mat[i]);
				free(mat);
				mat = NULL;
			}
	return (mat);
}
