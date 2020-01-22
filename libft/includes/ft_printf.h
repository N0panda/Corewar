/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:25:14 by mdelory           #+#    #+#             */
/*   Updated: 2018/10/04 16:56:28 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define ALL_ATTR		"#0- +"
# define ALL_LMOD		"hljz"

# define ALL_CONV		"sSpdDioOuUxXcC%b"
# define NUM_CONV		"diouxXpb"
# define UNSIGNED_CONV	"ouxXb"
# define SIGNED_CONV	"di"
# define STRING_CONV	"sScC%"
# define ALL_ALIAS		"DOU"
# define ALT_CONV		"oxX"

# define ATTR_HASH		0b00000001
# define ATTR_ZERO		0b00000010
# define ATTR_MINUS		0b00000100
# define ATTR_SPACE		0b00001000
# define ATTR_PLUS		0b00010000

# define LMOD_H			0b00000001
# define LMOD_L			0b00000010
# define LMOD_J			0b00000100
# define LMOD_Z			0b00001000
# define LMOD_HH		0b00010000
# define LMOD_LL		0b00100000

# define PF_BUFF_SIZE	1024

typedef struct			s_fmt
{
	int					attr;
	int					min_size;
	int					precision;
	int					lmod;
	char				conv;
}						t_fmt;

typedef struct			s_buffer
{
	char				buffer[PF_BUFF_SIZE];
	unsigned int		index;
	struct s_buffer		*next;
}						t_buffer;

int						ft_printf(char *format, ...);
int						ft_sprintf(char *str, char *format, ...);
int						ft_snprintf(char *str, size_t size, char *format, ...);
int						ft_asprintf(char **ret, char *format, ...);
int						ft_dprintf(int fd, char *format, ...);

int						ft_vprintf(char *format, va_list ap);
int						ft_vsprintf(char *str, char *format, va_list ap);
int						ft_vsnprintf(char *str, size_t size, char *format,\
							va_list ap);
int						ft_vasprintf(char **ret, char *format, va_list ap);
int						ft_vdprintf(int fd, char *format, va_list ap);

int						pf_fill_buffer(char *str, int size, t_buffer **buffer);
int						pf_putchar_buffer(char c, t_buffer **buffer);
t_buffer				*pf_create_buffer(t_buffer **buffer);
int						pf_join_buffer(t_buffer *buffer, char **out);
t_buffer				*pf_reverse_buffer(t_buffer *buffer, t_buffer *null);
void					pf_free_buffer(t_buffer **buffer);

int						pf_parse(char **format, va_list ap, t_buffer **buffer);
void					pf_parse_fmt(t_fmt *fc, va_list ap, char **fmt);
void					pf_parse_attr(char **fmt, t_fmt *c);
void					pf_parse_lmod(char **fmt, t_fmt *c);
void					pf_fix_fmt(t_fmt *fc);

int						pf_conv(t_fmt *fc, va_list ap, t_buffer **buffer);
int						pf_write_prefix(t_fmt *fc, uintmax_t value, \
							t_buffer **buffer);
int						pf_prefix_len(t_fmt *fc, uintmax_t value);
int						pf_write_padding(t_fmt *fc, int clen, \
							t_buffer **buffer);

int						pf_numeric_handler(t_fmt *fc, va_list ap, \
							t_buffer **buffer);
void					pf_numeric_conv(char conv, uintmax_t value, int prec, \
							t_buffer **buffer);
int						pf_numeric_len(char conv, int prec, uintmax_t value);
uintmax_t				pf_signed_mod(int lmod, va_list ap);
uintmax_t				pf_unsigned_mod(int lmod, va_list ap);

int						pf_string_handler(t_fmt *fc, va_list ap, \
							t_buffer **buffer);
int						pf_string_conv(t_fmt *fc, va_list ap, \
							t_buffer **buffer);
int						pf_wstring_conv(t_fmt *fc, va_list ap, \
							t_buffer **buffer);
int						pf_invalid_conv(t_fmt *fc, char c, t_buffer **buffer);

void					pfdbg_printfc(t_fmt *fc);
void					pfdbg_printbuffer(t_buffer *buffer);
#endif
