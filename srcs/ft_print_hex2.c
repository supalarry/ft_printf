/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_hex2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/05 17:06:34 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/03/05 17:06:35 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

/*
** @desc Determine return value for hexadecimal output function
** @param int len - length of a hexadecimal number
** @param t_node *node - address of node for specific conversion
** @return biggest between characters in the number and field width
*/

int		ft_return_hex(int len, t_node *node)
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

char	ft_fill_hex(t_node *node)
{
	if (ft_strchr(node->flags, '0') && !ft_strchr(node->flags, '-')
	&& node->precision == -1)
		return ('0');
	else
		return (' ');
}
