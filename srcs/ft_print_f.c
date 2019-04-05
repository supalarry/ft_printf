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
** @desc Determine characters in a float number
** @param t_node *node - address of node for specific conversion
** @param long long num - whole decimal number
** @return len - number of characters in a float
*/

static int	ft_f_len(t_node *node, long long num)
{
	int len;

	len = 0;
	if (num < 0)
		len++;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	if (ft_strchr(node->flags, '+') || ft_strchr(node->flags, ' '))
		len++;
	if (node->precision > 0)
		len = len + node->precision + 1;
	else if (node->precision != 0)
		len = len + 6 + 1;
	else if (node->precision == 0 && ft_strchr(node->flags, '#'))
		len++;
	return (len);
}

/*
** @desc Based on flags, output a preceding sign
** @param t_node *node - address of node for specific conversion
** @param double *num - address of a double for formatting
** @return void
*/

static void	ft_prepend_sign(t_node *node, double *num)
{
	if (ft_strchr(node->flags, '+') && *num < 0)
		ft_putchar('-');
	else if (ft_strchr(node->flags, '+') && *num >= 0)
		ft_putchar('+');
	if (ft_strchr(node->flags, ' ') && !ft_strchr(node->flags, '+') && *num < 0)
		ft_putchar('-');
	else if (ft_strchr(node->flags, ' ')
	&& !ft_strchr(node->flags, '+') && *num >= 0)
		ft_putchar(' ');
	else if (*num < 0 && !ft_strchr(node->flags, '+'))
		ft_putchar('-');
	*num = (*num > 0 ? *num : -(*num));
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
	while (field_width > len)
	{
		ft_putchar(fill);
		field_width--;
	}
}

/*
** @desc Typecast double according to flags
** @param t_node *node - address of node for specific conversion
** @param double *num - address of a double for formatting
** @return void
*/

static void	ft_typecast(t_node *node, double *num)
{
	if (ft_strlen(node->length) == 0 || ft_strcmp(node->length, "l") == 0)
		*num = (double)*num;
	else if (ft_strcmp(node->length, "L") == 0)
		*num = (long double)*num;
}

/*
** @desc Outputs formatted float number
** @param t_node *node - address of node for specific conversion
** @param double num - double for formatting
** @param int leftover - digits after comma
** @return biggest between characters in the float and field width
*/

int			ft_print_f(t_node *node, double num, int leftover)
{
	int		len;
	char	fill;

	ft_typecast(node, &num);
	len = ft_f_len(node, (long long)num);
	fill = ft_fill_float(node);
	if (node->field_width == -1 || ft_strchr(node->flags, '-'))
	{
		ft_prepend_sign(node, &num);
		ft_putfloat(node, num, leftover);
		ft_field_width_fill(node, len, fill);
	}
	else if (fill == '0')
	{
		ft_prepend_sign(node, &num);
		ft_field_width_fill(node, len, fill);
		ft_putfloat(node, num, leftover);
	}
	else if (fill == ' ')
	{
		ft_field_width_fill(node, len, fill);
		ft_prepend_sign(node, &num);
		ft_putfloat(node, num, leftover);
	}
	return (ft_return_float(len, node));
}
