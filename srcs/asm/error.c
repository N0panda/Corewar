/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:57:30 by ythomas           #+#    #+#             */
/*   Updated: 2019/10/28 18:16:49 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		ft_error_two(int err, char *file)
{
	if (err == 7)
		ft_dprintf(2, "Error file %s[%s]%s -- File can't be read or empty\n",
			ERF, file, ERD);
	else if (err == 8)
		ft_dprintf(2, "Error with file %s[%s]%s -- Bad Parsing\n",
			ERF, file, ERD);
	else if (err == 9)
		ft_dprintf(2, "Error with file %s[%s]%s -- File does not exist\n",
			ERF, file, ERD);
}

int				ft_error(int err, char *file)
{
	ft_dprintf(2, "\n");
	if (err == 1)
		ft_dprintf(2, "%sBad number of param%s\n", ERF, ERD);
	else if (err == 2)
		ft_dprintf(2, "Error with file %s[%s]%s -- bad format\n",
			ERF, file, ERD);
	else if (err == 3)
		ft_dprintf(2, "Error with file %s[%s]%s -- Env malloc Failed\n",
			ERF, file, ERD);
	else if (err == 4)
		ft_dprintf(2, "Error with file %s[%s]%s -- Program name too big\n",
			ERF, file, ERD);
	else if (err == 5)
		ft_dprintf(2, "Error with file %s[%s]%s -- File can't be opened\n",
			ERF, file, ERD);
	else if (err == 6)
		ft_dprintf(2, "Error with file %s[%s]%s -- Malloc Failed\n",
			ERF, file, ERD);
	else
		ft_error_two(err, file);
	ft_dprintf(2, "\n");
	return (-1);
}

int				parse_error_two(int err, char *file, char *line)
{
	if (err == 7)
		ft_dprintf(2, "Error with file %s[%s]%s -- Bad REG\n\t%s[%s]\
%s\n", ERF, file, ERD, ERP, line, ERD);
	else if (err == 8)
		ft_dprintf(2, "Error with file %s[%s]%s -- Bad Param\n\t%s\
[%s]%s\n", ERF, file, ERD, ERP, line, ERD);
	else if (err == 9)
		ft_dprintf(2, "Error with file %s[%s]%s -- Label not defined\
\n\t%s[%s]%s\n", ERF, file, ERD, ERP, line, ERD);
	else if (err == 10)
		ft_dprintf(2, "Error with file %s[%s]%s -- Bad number of \
params\n\t%s[%s]%s\n", ERF, file, ERD, ERP, line, ERD);
	else if (err == 11)
		ft_dprintf(2, "Error with file %s[%s]%s -- Bad instruction \
in Header\n\t%s[%s]%s\n", ERF, file, ERD, ERP, line, ERD);
	else if (err == 12)
		ft_dprintf(2, "Error with file %s[%s]%s -- Bad spacing in \
params\n\t%s[%s]%s\n", ERF, file, ERD, ERP, line, ERD);
	return (-1);
}

int				parse_error(int err, char *file, char *line)
{
	ft_dprintf(2, "\n");
	if (err == 1)
		ft_dprintf(2, "Error with file %s[%s]%s -- Bad name or \
comment\n\t%s[%s]%s\n", ERF, file, ERD, ERP, line, ERD);
	else if (err == 2)
		ft_dprintf(2, "Error with file %s[%s]%s -- Bad instruction\
\n\t%s[%s]%s\n", ERF, file, ERD, ERP, line, ERD);
	else if (err == 3)
		ft_dprintf(2, "Error with file %s[%s]%s -- Bad Label\n\t%s\
[%s]%s\n", ERF, file, ERD, ERP, line, ERD);
	else if (err == 4)
		ft_dprintf(2, "Error with file %s[%s]%s -- label multi \
defined\n\t%s[%s]%s\n", ERF, file, ERD, ERP, line, ERD);
	else if (err == 5)
		ft_dprintf(2, "Error with file %s[%s]%s -- Bad number of \
params\n", ERF, file, ERD, ERP, line, ERD);
	else if (err == 6)
		ft_dprintf(2, "Error with file %s[%s]%s -- Bad number\n\t%s\
[%s]%s\n", ERF, file, ERD, ERP, line, ERD);
	else
		parse_error_two(err, file, line);
	ft_dprintf(2, "\n");
	return (-1);
}
