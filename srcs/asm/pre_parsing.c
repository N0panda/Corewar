/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:49:52 by ythomas           #+#    #+#             */
/*   Updated: 2019/10/24 15:30:47 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			get_file_in_string(t_env *env, char *file_name)
{
	int		size;
	int		ret;
	char	*file_string;

	size = lseek(env->fd, 0, SEEK_END);
	lseek(env->fd, 0, SEEK_SET);
	if (!(file_string = ft_memalloc(sizeof(char) * size + 1)))
		return (ft_error(6, file_name));
	if ((ret = read(env->fd, file_string, size)) <= 0)
		return (ft_error(7, file_name));
	if (!(env->file = ft_strsplit(file_string, '\n')))
		return (ft_error(6, file_name));
	ft_strdel(&file_string);
	return (0);
}

int			get_nb_line(char **file)
{
	int i;
	int	len;

	i = 0;
	len = 0;
	while (file[i])
	{
		if (check_empty_line(file[i]) == 1)
			len++;
		i++;
	}
	return (len);
}

int			get_and_copy_file(t_env *env, char *av)
{
	int		i;

	if ((env->file_name = ft_strdup(av)) == NULL)
		return (ft_error(6, av));
	if ((env->fd = open(av, O_RDONLY)) == -1)
		return (ft_error(5, av));
	if ((get_file_in_string(env, av)) == -1)
		return (-1);
	env->nb_actions = get_nb_line(env->file);
	if (!(env->actions = ft_memalloc(sizeof(void *) * (env->nb_actions + 1))))
		return (ft_error(6, av));
	i = -1;
	while (++i < env->nb_actions)
		if (!(env->actions[i] = ft_memalloc(sizeof(t_line))))
			return (ft_error(6, av));
	env->actions[env->nb_actions] = NULL;
	env->name = NULL;
	env->comment = NULL;
	return (0);
}
