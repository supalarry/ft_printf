/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_header.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/16 13:05:05 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/02/16 13:05:06 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_HEADER_H
# define FT_PRINTF_HEADER_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# define CS	conversion_specifier

union				u_val
{
	char			character;
	char			*string;
	void			*address;
	int				number;
	unsigned int	u_number;
	float			floating;
};

typedef	struct		s_node
{
	union u_val		values;
	char			flags[6];
	int				field_width;
	int				precision;
	char			length[3];
	char			conversion_specifier;
	char			*error;
	const char		*format;
	int				flag_pos;
	struct s_node	*next;
}					t_node;

int					ft_printf(const char *format, ...);
int					ft_flags(t_node *node, const char *format, int *i,
					va_list ap);
int					ft_field_width(t_node *node, va_list ap,
					int *i, int check);
int					ft_precision(t_node *node, va_list ap, int *i,
					int check);
int					ft_length(t_node *node, const char *f, int *i, int check);
int					ft_conversion_specifier(t_node *node, const char *format,
					int *i);
t_node				*ft_origin_node(const char *format, int *i, va_list ap);
int					ft_add_node(t_node *head, const char *format, int *i,
					va_list ap);
t_node				*ft_extract(const char *format, va_list ap);
void				ft_info_node(t_node *head);
int					ft_print_char(t_node *node, int c);
int					ft_print_str(t_node *node, char *str);
int					ft_print_ptr(t_node *node, void *address);
int					ft_print_num(t_node *node, long long num);
int					ft_print_oct(t_node *node, unsigned long long num);
int					ft_print_unum(t_node *node, unsigned long long num);
int					ft_print_hex(t_node *node, unsigned long long num,
					int capital);
int					ft_print_f(t_node *node, double num, int leftover);
void				ft_puthex(t_node *node, unsigned long long n,
					int capital);
void				ft_putoct(t_node *node, unsigned long long n);
void				ft_putunum(t_node *node, unsigned long long n);
void				ft_putdi(t_node *node, long long n);
void				ft_putfloat(t_node *node, double n, int leftover);
int					ft_print_percent(t_node *node);
int					ft_print_invalid(t_node *node);
int					ft_print_wide_str(t_node *node, wchar_t *str);
int					ft_wchar(t_node *node, unsigned int c);
size_t				ft_wchar_strlen(wchar_t *s);
int					ft_wchar_putnstr(t_node *node, const wchar_t *s1,
					int wlen);
size_t				ft_wchar_bytes(wchar_t *s);
void				ft_free_list(t_node *head);
int					ft_return_hex(int len, t_node *node);
char				ft_fill_hex(t_node *node);
char				ft_fill_float(t_node *node);
int					ft_return_float(int len, t_node *node);
int					ft_return_oct(int len, t_node *node);
char				ft_fill_oct(t_node *node);
char				ft_fill_di(t_node *node);
int					ft_return_di(int len, t_node *node);
void				ft_compensate_num(t_node *node, long long num);
int					ft_num_len(t_node *node, long long num);
size_t				ft_wchar_size(wchar_t c);
int					ft_num_width(int num);
void				ft_field_width2(t_node *node, va_list ap, int *i,
					int *pos);
void				ft_precision2(t_node *node, va_list ap, int *i);
#endif
