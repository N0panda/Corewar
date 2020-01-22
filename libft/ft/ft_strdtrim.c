/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdtrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:20:37 by mdelory           #+#    #+#             */
/*   Updated: 2018/05/24 13:38:24 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdtrim(char const *s, char d)
{
	char		*trim;
	int			i;
	int			j;

	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i] == d)
		i++;
	while (s[j] == d && j >= 0)
		j--;
	if (j < i)
		trim = ft_strnew(0);
	else
		trim = ft_strsub(s, i, j - i + 1);
	return (trim);
}
