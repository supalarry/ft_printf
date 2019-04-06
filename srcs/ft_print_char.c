/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_char.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/05 14:32:57 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/03/05 14:32:59 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

/*
** @desc Outputs formatted single or multibyte character
** @param t_node *node - address of node for specific conversion
** @param int c - character to be printed
** @return bytes in a character or field width
*/

int	ft_print_char(t_node *node, int c) 
{
	int		field_width;
	char	fill;

	fill = (ft_strchr(node->flags, '0')
	&& !ft_strchr(node->flags, '-') ? '0' : ' ');
	field_width = node->field_width;
	if (node->field_width == -1 || node->field_width == 0)
	{
		return (ft_wchar(node, c));
	}
	else
	{
		if (ft_strchr(node->flags, '-'))
			ft_wchar(node, c);
		while (field_width > 1)
		{
			ft_putchar(fill);
			field_width--;
		}
		if (!ft_strchr(node->flags, '-'))
			ft_wchar(node, c);
	}
	return (node->field_width);
}
