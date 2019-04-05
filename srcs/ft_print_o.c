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
** @desc Determine number of characters in decimal number as octal
** @param t_node *node - address of node for specific conversion
** @param unsigned long long num - decimal number
** @return len - number of characters in octal number
*/

static int	ft_oct_len(t_node *node, unsigned long long num)
{
	int len;

	len = 0;
	if (num == 0 && node->precision != 0 && !ft_strchr(node->flags, '#'))
		len++;
	while (num != 0)
	{
		len++;
		num = num / 8;
	}
	if (ft_strchr(node->flags, '#'))
		len++;
	return (len);
}

/*
** @desc If '#' is present or precision is bigger than octal, output '0's
** @param t_node *node - address of node for specific conversion
** @param int *len - characters in octal number
** @return void
*/

static void	ft_prepend_sign(t_node *node, int *len)
{
	if (ft_strchr(node->flags, '#'))
		ft_putchar('0');
	if (*len < node->precision)
	{
		while (*len != node->precision)
		{
			ft_putchar('0');
			(*len)++;
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
	int field_width;

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
** @desc Typecast unsigned number according to flags
** @param t_node *node - address of node for specific conversion
** @param unsigned long *num - address of unsigned number to be formatted
** @return void
*/

static void	ft_typecast(t_node *node, unsigned long long *num)
{
	if (node->conversion_specifier == 'O')
		*num = (unsigned long)*num;
	else if (ft_strlen(node->length) == 0)
		*num = (unsigned int)*num;
	else if (ft_strcmp(node->length, "hh") == 0)
		*num = (unsigned char)*num;
	else if (ft_strcmp(node->length, "h") == 0)
		*num = (unsigned short)*num;
	else if (ft_strcmp(node->length, "ll") == 0)
		*num = (unsigned long long)*num;
	else if (ft_strcmp(node->length, "l") == 0)
		*num = (unsigned long)*num;
	else if (ft_strcmp(node->length, "z") == 0)
		*num = (size_t)*num;
}

/*
** @desc Outputs formatted octal number
** @param t_node *node - address of node for specific conversion
** @param long long num - number to be formatted as octal
** @return biggest between characters in the number, precision and field width
*/

int			ft_print_oct(t_node *node, unsigned long long num)
{
	int		len;
	char	fill;

	ft_typecast(node, &num);
	len = ft_oct_len(node, num);
	fill = ft_fill_oct(node);
	if (node->field_width == -1 || ft_strchr(node->flags, '-'))
	{
		ft_prepend_sign(node, &len);
		ft_putoct(node, num);
		ft_field_width_fill(node, len, fill);
	}
	else if (fill == '0')
	{
		ft_prepend_sign(node, &len);
		ft_field_width_fill(node, len, fill);
		ft_putoct(node, num);
	}
	else if (fill == ' ')
	{
		ft_field_width_fill(node, len, fill);
		ft_prepend_sign(node, &len);
		ft_putoct(node, num);
	}
	return (ft_return_oct(len, node));
}
