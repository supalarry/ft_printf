/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_di.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/21 19:50:10 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/02/21 19:50:12 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

/*
** @desc Based on flags, output a preceding sign
** @param t_node *node - address of node for specific conversion
** @param double *num - address of a double for formatting
** @return void
*/

static void	ft_prepend_sign(t_node *node, long long *num)
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
** @desc Typecast digit according to flags
** @param t_node *node - address of node for specific conversion
** @param double *num - address of a digit for formatting
** @return void
*/

static void	ft_typecast(t_node *node, long long *num)
{
	if (node->conversion_specifier == 'D')
		*num = (long)*num;
	else if (ft_strlen(node->length) == 0)
		*num = (int)*num;
	else if (ft_strcmp(node->length, "hh") == 0)
		*num = (char)*num;
	else if (ft_strcmp(node->length, "h") == 0)
		*num = (short)*num;
	else if (ft_strcmp(node->length, "ll") == 0)
		*num = (long long)*num;
	else if (ft_strcmp(node->length, "l") == 0)
		*num = (long)*num;
	else if (ft_strcmp(node->length, "z") == 0)
		*num = (ssize_t) * num;
}

/*
** @desc Lauches functions based on field width and fill
** @param t_node *node - address of node for specific conversion
** @param long long num - digit for formatting
** @param int len - length of a digit
** @param char fill - character used for filling field width
** @return void
*/

static void	ft_exe_di(t_node *node, long long *num, int len, char fill)
{
	ft_typecast(node, num);
	if (node->field_width == -1 || ft_strchr(node->flags, '-'))
	{
		ft_prepend_sign(node, num);
		ft_compensate_num(node, *num);
		ft_putdi(node, *num);
		ft_field_width_fill(node, len, fill);
	}
	else if (fill == '0')
	{
		ft_prepend_sign(node, num);
		ft_field_width_fill(node, len, fill);
		ft_compensate_num(node, *num);
		ft_putdi(node, *num);
	}
	else if (fill == ' ')
	{
		ft_field_width_fill(node, len, fill);
		ft_prepend_sign(node, num);
		ft_compensate_num(node, *num);
		ft_putdi(node, *num);
	}
}

/*
** @desc Outputs formatted digit
** @param t_node *node - address of node for specific conversion
** @param long long num - digit for formatting
** @return biggest between characters in the digit, precision and field width
*/

int			ft_print_num(t_node *node, long long num)
{
	int		len;
	char	fill;

	ft_typecast(node, &num);
	len = ft_num_len(node, num);
	fill = ft_fill_di(node);
	ft_exe_di(node, &num, len, fill);
	return (ft_return_di(len, node));
}
