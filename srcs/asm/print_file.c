/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:26:14 by ythomas           #+#    #+#             */
/*   Updated: 2019/10/24 15:06:43 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			fill_header_buffer(t_env *env, int fd)
{
	const int		nb = 0;

	header_add_magic_number(fd);
	header_add_name(env->name, fd);
	write(fd, &nb, sizeof(int));
	reverse_writing(fd, env->champion_size, 4);
	header_add_comment(env->comment, fd);
	write(fd, &nb, sizeof(int));
	return (0);
}

int			add_one_champion_line(t_line *act, int fd)
{
	int i;

	i = 0;
	if (act->type == ZZ_OP)
	{
		write(fd, &act->instruction, 1);
		if (act->ocp == 1)
			write(fd, &act->value_ocp, 1);
		while (i < act->nb_params)
		{
			reverse_writing(fd, act->param_final[i], act->bit_type[i]);
			i++;
		}
	}
	return (0);
}

int			fill_champion_buffer(t_env *env, int fd)
{
	int i;

	(void)fd;
	i = 0;
	while (env->actions[i])
	{
		add_one_champion_line(env->actions[i], fd);
		i++;
	}
	return (0);
}

char		*get_name_cor(t_env *env)
{
	int		i;
	char	*str;
	char	*res;
	char	*tmp;

	i = 0;
	str = env->file_name;
	while (env->file_name[i])
	{
		if (env->file_name[i] == '/')
			str = env->file_name + i + 1;
		i++;
	}
	if (!(res = ft_memalloc(sizeof(char) * (ft_strlen(str) - 1))))
		return (NULL);
	ft_strncpy(res, str, ft_strlen(str) - 2);
	if (!(tmp = ft_strjoin(res, ".cor")))
		return (NULL);
	free(res);
	return (tmp);
}

int			create_binary_file(t_env *env)
{
	int			fd;
	char		*str;

	if ((str = get_name_cor(env)) == NULL)
		return (-1);
	if ((fd = open(str, O_CREAT | O_WRONLY | O_TRUNC, 0776)) == -1)
		return (ft_error(5, str));
	if (fill_header_buffer(env, fd) == -1)
		return (-1);
	fill_champion_buffer(env, fd);
	ft_printf("\nFile  --->   %s[%s]%s  is created\n\n", OKF, str, ERD);
	ft_strdel(&str);
	return (0);
}
