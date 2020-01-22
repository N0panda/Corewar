/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:30:02 by mdelory           #+#    #+#             */
/*   Updated: 2018/11/06 15:20:15 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtok_r(char *str, const char *sep, char **lasts)
{
	char			*w;

	if (!str)
		str = *lasts;
	while (*str && ft_strchr(sep, *str))
		++str;
	if (*str == '\0')
		return (NULL);
	w = str;
	while (*str && !ft_strchr(sep, *str))
		++str;
	if (*str)
		*str++ = '\0';
	*lasts = str;
	return (w);
}

char				*ft_strtok(char *str, const char *sep)
{
	static char		*ptr;

	return (ft_strtok_r(str, sep, &ptr));
}
