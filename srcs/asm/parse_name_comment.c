/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name_comment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:53:42 by ythomas           #+#    #+#             */
/*   Updated: 2019/10/28 13:32:53 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		check_format(t_env *env, char *str)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '\"')
		{
			if (count == 0 && str[i - 1] == '\\')
				return (parse_error(1, env->file_name, str));
			else if (str[i - 1] == '\\')
				continue ;
			else
				count++;
		}
	}
	if (count != 2)
		return (parse_error(1, env->file_name, str));
	return (0);
}

static int		get_len_str(t_env *env, char *str, int cas)
{
	int i;
	int j;
	int len;

	i = 0;
	j = ft_strlen(str);
	while (str[i] && str[i] != '\"')
		i++;
	len = j - i - 1;
	if (cas == 1 && len > 128)
		return (parse_error(1, env->file_name, str));
	else if (cas == 2 && len > 2048)
		return (parse_error(1, env->file_name, str));
	return (len);
}

static char		*stock_string(t_env *env, char *line, int cas)
{
	char		*str;
	int			len;
	int			i;
	int			j;
	int			z;

	i = 0;
	z = 0;
	if (check_format(env, line) == -1)
		return (NULL);
	if ((len = get_len_str(env, line, cas)) == -1)
		return (NULL);
	if (!(str = malloc(sizeof(char) * len)))
		return (NULL);
	str[len - 1] = '\0';
	while (line[i] && line[i] != '\"')
		i++;
	i++;
	j = i + len - 1;
	while (i < j)
		str[z++] = line[i++];
	return (str);
}

static int		parse_token(char *line, int stat)
{
	if (stat == 1)
	{
		if (ft_strstr(line, "name "))
			return (0);
		else if (ft_strstr(line, "name	"))
			return (0);
		else if (ft_strstr(line, "name\""))
			return (0);
	}
	else
	{
		if (ft_strstr(line, "comment "))
			return (0);
		else if (ft_strstr(line, "comment	"))
			return (0);
		else if (ft_strstr(line, "comment\""))
			return (0);
	}
	return (-1);
}

int				parse_name_comm(t_env *env, t_line *act, char *line)
{
	if ((ft_strstr(line, NAME_CMD_STRING)) != NULL)
	{
		if (env->name != NULL)
			return (-1);
		if ((env->name = stock_string(env, line, 1)) == NULL)
			return (-1);
		act->type = 1;
		if (parse_token(line, 1) == -1)
			return (parse_error(1, env->file_name, line));
	}
	else if ((ft_strstr(line, COMMENT_CMD_STRING)) != NULL)
	{
		if (env->comment != NULL)
			return (-1);
		if ((env->comment = stock_string(env, line, 2)) == NULL)
			return (-1);
		act->type = 1;
		if (parse_token(line, 2) == -1)
			return (parse_error(1, env->file_name, line));
	}
	else
		return (parse_error(11, env->file_name, line));
	return (0);
}
