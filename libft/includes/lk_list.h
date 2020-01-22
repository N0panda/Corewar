/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lk_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 17:23:13 by mdelory           #+#    #+#             */
/*   Updated: 2018/08/11 04:04:48 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LK_LIST_H
# define LK_LIST_H

# include "libft.h"

typedef struct			s_lknode
{
	void				*content;
	size_t				content_size;
	struct s_lklist		*header;
	struct s_lknode		*next;
	struct s_lknode		*prev;
}						t_lknode;

typedef struct			s_lklist
{
	unsigned int		count;
	struct s_lknode		*cur;
	struct s_lknode		*head;
	struct s_lknode		*tail;
}						t_lklist;

t_lknode				*lk_lst_new(void *content, size_t size);
t_lknode				*lk_lst_getnext(t_lklist *lst);
t_lknode				*lk_lst_push_f(t_lklist *lst, t_lknode *new);
t_lknode				*lk_lst_push_b(t_lklist *lst, t_lknode *new);
t_lknode				*lk_lst_remove(t_lklist *lst, t_lknode *del);
void					lk_lst_iter(t_lklist *lst, void (*f)(t_lknode *el));
t_lklist				*lk_lst_init(void);
void					lk_lst_del(t_lklist **lst);
void					lk_lst_delall(t_lklist **lst);

#endif
