/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_di2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/05 18:39:11 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/03/05 18:39:13 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

/*
** @desc Determine return value for digit output function
** @param int len - length of a digit
** @param t_node *node - address of node for specific conversion
** @return biggest between characters in the number, precision and field width
*/

int			ft_return_di(int len, t_node *node)
{
	if (len >= node->field_width && len >= node->precision)
		return (len);
	else if (node->precision > node->field_width)
		return (node->precision);
	else
		return (node->field_width);
}

/*
** @desc Determine character for fill
** @param t_node *node - address of node for specific conversion
** @return character for fill
*/

char		ft_fill_di(t_node *node)
{
	if (ft_strchr(node->flags, '0') && !ft_strchr(node->flags, '-')
	&& node->precision == -1)
		return ('0');
	else
		return (' ');
}

/*
** @desc If precision is higher than length of number, output '0's
** @param t_node *node - address of node for specific conversion
** @param long long num - decimal number
** @return void
*/

void		ft_compensate_num(t_node *node, long long num)
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
** @desc Determine characters in a digit
** @param t_node *node - address of node for specific conversion
** @param long long num - decimal number
** @return len - number of characters in a number
*/

int			ft_num_len(t_node *node, long long num)
{
	int			len;
	long long	num_copy;

	len = 0;
	if (num == 0 && node->precision != 0)
		len++;
	num_copy = num;
	if (num < 0)
		len++;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	if (len <= node->precision && num_copy < 0)
		len = len + (node->precision - len + 1);
	else if (len < node->precision && num_copy >= 0)
		len = len + (node->precision - len);
	if ((ft_strchr(node->flags, '+')
	|| ft_strchr(node->flags, ' ')) && num_copy >= 0)
		len++;
	return (len);
}
