/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:16:28 by mdelory           #+#    #+#             */
/*   Updated: 2019/10/23 18:24:52 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			get_word_count(char const *s, char c)
{
	int				count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			while (*s && *s != c)
				s++;
			count++;
		}
	}
	return (count);
}

static char			*get_next_word(char const *s, char c)
{
	char			*cur;
	char			*w;
	unsigned int	i;

	cur = (char *)s;
	i = 0;
	while (*cur && *cur != c)
	{
		cur++;
		i++;
	}
	w = ft_strsub(s, 0, i);
	return (w);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**tab;
	int				count;
	int				i;

	if (!s)
		return (NULL);
	i = 0;
	count = get_word_count(s, c);
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		tab[i] = get_next_word(s, c);
		s += ft_strlen(tab[i]);
		i++;
	}
	tab[count] = NULL;
	return (tab);
}
