/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:34:45 by mdelory           #+#    #+#             */
/*   Updated: 2018/11/11 21:53:51 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strspn(const char *s, const char *charset)
{
	const char	*ptr;

	ptr = s;
	while (*ptr && ft_strchr(charset, *ptr))
		ptr++;
	return ((size_t)(ptr - s));
}
