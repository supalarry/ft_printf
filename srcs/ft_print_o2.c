/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_o2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/05 18:29:15 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/03/05 18:29:16 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

/*
** @desc Determine return value for octal output function
** @param int len - length of an octet
** @param t_node *node - address of node for specific conversion
** @return biggest between characters in the number, precision and field width
*/

int		ft_return_oct(int len, t_node *node)
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

char	ft_fill_oct(t_node *node)
{
	if (ft_strchr(node->flags, '0') && !ft_strchr(node->flags, '-')
	&& node->precision == -1)
		return ('0');
	else
		return (' ');
}
