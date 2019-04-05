/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 17:23:42 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/02/19 17:23:43 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

/*
** @desc Determine number of characters in decimal number as hexadecimal
** @param t_node *node - address of node for specific conversion
** @param unsigned long long num - decimal number
** @return len - number of characters in hexadecimal number
*/

static int	ft_hex_len(t_node *node, unsigned long long num)
{
	int					len;
	unsigned long long	num_copy;

	len = 0;
	num_copy = num;
	if (num == 0 && node->precision != 0)
		len++;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	if (ft_strchr(node->flags, '#') && num_copy != 0)
		len = len + 2;
	return (len);
}

/*
** @desc Prepend characters before hexadecimal based on conversion requirement
** @param t_node *node - address of node for specific conversion
** @param unsigned long long num - decimal number
** @param int capital - determines upper or lower case of output
** @param int *l - characters in octal number
** @return void
*/

static void	ft_prepend(t_node *n, unsigned long long num, int capital, int *l)
{
	if (*l < n->precision && !(ft_strchr(n->flags, '#') && n->precision != -1))
	{
		while (*l != n->precision)
		{
			ft_putchar('0');
			(*l)++;
		}
	}
	if (ft_strchr(n->flags, '#') && num != 0)
	{
		ft_putchar('0');
		if (capital == 1)
			ft_putchar('X');
		else
			ft_putchar('x');
	}
	if (*l < n->precision && (ft_strchr(n->flags, '#') && n->precision != -1))
	{
		while (*l - 2 != n->precision)
		{
			ft_putchar('0');
			(*l)++;
		}
	}
}

/*
** @desc Output characters to fill field width
** @param t_node *node - address of node for specific conversion
** @param int len - length of number
** @param char fill - character to fill field width
** @return void
*/

static void	ft_field_width_fill(t_node *node, int len, char fill)
{
	int	field_width;

	field_width = node->field_width;
	if (node->precision > len)
		field_width = field_width - (node->precision - len);
	while (field_width > len)
	{
		ft_putchar(fill);
		field_width--;
	}
}

/*
** @desc Typecast number according to flags
** @param t_node *node - address of node for specific conversion
** @param unsigned long long *num - address of unsigned number to be formatted
** @return void
*/

static void	ft_typecast(t_node *node, unsigned long long *num)
{
	if (ft_strlen(node->length) == 0)
		*num = (unsigned int)*num;
	else if (ft_strcmp(node->length, "hh") == 0)
		*num = (unsigned char)*num;
	else if (ft_strcmp(node->length, "h") == 0)
		*num = (unsigned short)*num;
	else if (ft_strcmp(node->length, "ll") == 0)
		*num = (unsigned long long)*num;
	else if (ft_strcmp(node->length, "l") == 0)
		*num = (unsigned long)*num;
	else if (ft_strcmp(node->length, "j") == 0)
		*num = (uintmax_t) * num;
	else if (ft_strcmp(node->length, "z") == 0)
		*num = (size_t)*num;
}

/*
** @desc Outputs formatted hexadecimal number
** @param t_node *node - address of node for specific conversion
** @param unsigned long long num - number to be formatted as octal
** @param int capital - determines upper or lower case of output
** @return biggest between characters in the number and field width
*/

int			ft_print_hex(t_node *node, unsigned long long num, int capital)
{
	int		len;
	char	fill;

	ft_typecast(node, &num);
	len = ft_hex_len(node, num);
	fill = ft_fill_hex(node);
	if (node->field_width == -1 || ft_strchr(node->flags, '-'))
	{
		ft_prepend(node, num, capital, &len);
		ft_puthex(node, num, capital);
		ft_field_width_fill(node, len, fill);
	}
	else if (fill == '0')
	{
		ft_prepend(node, num, capital, &len);
		ft_field_width_fill(node, len, fill);
		ft_puthex(node, num, capital);
	}
	else if (fill == ' ')
	{
		ft_field_width_fill(node, len, fill);
		ft_prepend(node, num, capital, &len);
		ft_puthex(node, num, capital);
	}
	return (ft_return_hex(len, node));
}
