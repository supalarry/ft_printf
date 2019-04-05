/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_ptr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 20:12:17 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/02/28 20:12:19 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

/*
** @desc Determine length of an address
** @param t_node *node - structure of a conversion specifier
** @param long num - address in hexadecimal
** @return void
*/

static int	ft_ptr_len(t_node *node, long num)
{
	int len;

	len = 2;
	if (num == 0 && node->precision != 0)
		len++;
	while (num != 0)
	{
		len++;
		num = num / 16;
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
** @desc Outputs '0's if precision is bigger than number's length
** @param t_node *node - address of node for specific conversion
** @param unsigned long long num - unsigned number to be formatted
** @return void
*/

static void	ft_compensate(t_node *node, long num)
{
	int			num_len;
	long long	num_copy;
	int			compensate;

	num_len = 0;
	num_copy = num;
	compensate = 0;
	ft_putstr("0x");
	if (num == 0)
		num_len++;
	while (num_copy != 0)
	{
		num_len++;
		num_copy = num_copy / 16;
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
** @desc Determine character for fill
** @param t_node *node - address of node for specific conversion
** @return character for fill
*/

static char	ft_fill_ptr(t_node *node)
{
	if (ft_strchr(node->flags, '0') && !ft_strchr(node->flags, '-')
	&& node->precision == -1)
		return ('0');
	else
		return (' ');
}

/*
** @desc Output an address
** @param t_node *node - address of node for specific conversion
** @param void *address - address of an item
** @return biggest between characters in the number, precision and field width
*/

int			ft_print_ptr(t_node *node, void *address)
{
	int		len;
	char	fill;
	long	transformer;

	fill = ft_fill_ptr(node);
	transformer = (long)address;
	len = ft_ptr_len(node, transformer);
	if (node->field_width == -1 || ft_strchr(node->flags, '-')
	|| (address == 0 && fill == '0'))
	{
		ft_compensate(node, transformer);
		ft_puthex(node, transformer, 0);
		ft_field_width_fill(node, len, fill);
	}
	else if (!ft_strchr(node->flags, '-'))
	{
		ft_field_width_fill(node, len, fill);
		ft_compensate(node, transformer);
		ft_puthex(node, transformer, 0);
	}
	if (len >= node->field_width && len >= node->precision)
		return (len);
	else if (node->precision > node->field_width)
		return (node->precision + 2);
	return (node->field_width);
}
