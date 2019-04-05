/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_f2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/05 17:19:31 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/03/05 17:19:33 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

/*
** @desc Determine return value for float output function
** @param int len - length of a float
** @param t_node *node - address of node for specific conversion
** @return biggest between characters in the float and field width
*/

int			ft_return_float(int len, t_node *node)
{
	if (len > node->field_width)
		return (len);
	return (node->field_width);
}

/*
** @desc Determine character for fill
** @param t_node *node - address of node for specific conversion
** @return character for fill
*/

char		ft_fill_float(t_node *node)
{
	if (ft_strchr(node->flags, '0') && !ft_strchr(node->flags, '-')
	&& node->precision == -1)
		return ('0');
	else
		return (' ');
}

/*
** @desc Turn numbers after comma into a whole number
** @param double *num - number smaller than 1
** @param int leftover - digits required after comma
** @return void
*/

static void	ft_multiply(double *num, int leftover)
{
	while (leftover)
	{
		*num = *num * 10;
		leftover--;
	}
}

/*
** @desc Output '0's after comma if number is 0 but has specific width required
** @param int leftover - digits required after comma
** @return void
*/

static void	ft_compensate(int leftover)
{
	while (leftover)
	{
		ft_putchar('0');
		leftover--;
	}
}

/*
** @desc Outputs float number
** @param t_node *node - address of node for specific conversion
** @param double num - double to be written to standard output
** @return void
*/

void		ft_putfloat(t_node *node, double num, int leftover)
{
	long long	base;
	long int	decimal;

	if (leftover == -1)
		leftover = 6;
	base = (long long)num;
	ft_putdi(node, base);
	if (ft_strchr(node->flags, '#') || node->precision != 0)
		ft_putchar('.');
	num -= base;
	if (num != 0)
		ft_multiply(&num, leftover);
	else
		ft_compensate(leftover);
	decimal = (long int)(num + 0.5);
	if (node->precision != 0 && num != 0)
		ft_putnbr(decimal);
}
