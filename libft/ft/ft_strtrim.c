/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:42:12 by mdelory           #+#    #+#             */
/*   Updated: 2018/05/24 13:38:25 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	char		*trim;
	int			i;
	int			j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j >= 0)
		j--;
	if (j < i)
		trim = ft_strnew(0);
	else
		trim = ft_strsub(s, i, j - i + 1);
	return (trim);
}
