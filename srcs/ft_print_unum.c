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
** @desc Determine number of characters in unsigned number
** @param t_node *node - address of node for specific conversion
** @param unsigned long num - unsigned number to be formatted
** @return len - number of characters in unsigned number
*/

static int	ft_unum_len(t_node *node, unsigned long long num)
{
	int len;

	len = 0;
	if (num == 0 && node->precision != 0)
		len++;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
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
	if (node->conversion_specifier == 'U')
		*num = (unsigned long long)*num;
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
}

/*
** @desc Outputs '0's if precision is bigger than number's length
** @param t_node *node - address of node for specific conversion
** @param unsigned long long num - unsigned number to be formatted
** @return void
*/

static void	ft_compensate_unum(t_node *node, unsigned long long num)
{
	int			num_len;
	long long	num_copy;
	int			compensate;

	num_len = 0;
	num_copy = num;
	compensate = 0;
	if (num == 0)
		num_len++;
	while (num_copy != 0)
	{
		num_len++;
		num_copy = num_copy / 10;
	}
	if (num_len < node->precision)
	{
		compensate = node->precision - num_len;
		while (compensate)
		{
			ft_putchar('0');
			compensate--;
		}
	}
}

/*
** @desc Outputs formatted unsigned number
** @param t_node *node - address of node for specific conversion
** @param long long num - unsigned number to be formatted
** @return biggest between characters in the number, precision and field width
*/

int			ft_print_unum(t_node *node, unsigned long long num)
{
	int		len;
	char	fill;

	ft_typecast(node, &num);
	len = ft_unum_len(node, num);
	fill = (ft_strchr(node->flags, '0') && !ft_strchr(node->flags, '-')
	&& node->precision == -1 ? '0' : ' ');
	if (node->field_width == -1 || ft_strchr(node->flags, '-'))
	{
		ft_compensate_unum(node, num);
		ft_putunum(node, num);
		ft_field_width_fill(node, len, fill);
	}
	else if (fill == '0' || fill == ' ')
	{
		ft_field_width_fill(node, len, fill);
		ft_compensate_unum(node, num);
		ft_putunum(node, num);
	}
	if (len >= node->field_width && len >= node->precision)
		return (len);
	else if (node->precision > node->field_width)
		return (node->precision);
	return (node->field_width);
}
