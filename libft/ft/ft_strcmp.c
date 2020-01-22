/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:13:45 by mdelory           #+#    #+#             */
/*   Updated: 2018/05/24 13:38:24 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strcmp(const char *s1, const char *s2)
{
	if (*(unsigned char *)s1 == *(unsigned char *)s2 && *(unsigned char *)s1)
		return (ft_strcmp(s1 + 1, s2 + 1));
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
