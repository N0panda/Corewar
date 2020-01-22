/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 17:23:13 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/18 12:43:11 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>

# include "libft.h"

# define VECTOR_SIZE 16

typedef struct		s_vector
{
	unsigned int	size;
	unsigned int	count;
	void			**data;
}					t_vector;

int					vector_init(t_vector *v);
int					vector_count(t_vector *v);
int					vector_add(t_vector *v, void *data);
int					vector_set(t_vector *v, unsigned int index, void *data);
void				*vector_at(t_vector *v, unsigned int index);
int					vector_in(t_vector *v, void *ptr);
int					vector_delete(t_vector *v, unsigned int index);
void				vector_destroy(t_vector *v);
void				vector_for_each(t_vector *v, void (*f)(void *));
void				vector_free(t_vector *v, unsigned int index);
void				vector_free_all(t_vector *v);
void				vector_print(t_vector *v);
void				vector_clear(t_vector *v);
void				vector_sort(t_vector *v, int (*cmp)(void *, void *));
int					vector_copy(t_vector *dst, t_vector *src);

#endif
