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
** @desc Outputs formatted '%' sign
** @param t_node *node - address of node for specific conversion
** @return 1 if only '%' was written to standard output
** @return field width if it as specified
*/

int	ft_print_percent(t_node *node)
{
	int		field_width;
	char	fill;

	fill = (ft_strchr(node->flags, '0')
	&& !ft_strchr(node->flags, '-') ? '0' : ' ');
	field_width = node->field_width;
	if (node->field_width == -1)
	{
		ft_putchar('%');
		return (1);
	}
	else
	{
		if (ft_strchr(node->flags, '-'))
			ft_putchar('%');
		while (field_width > 1)
		{
			ft_putchar(fill);
			field_width--;
		}
		if (!ft_strchr(node->flags, '-'))
			ft_putchar('%');
	}
	return (node->field_width);
}

/*
** @desc Outputs invalid format specifier and width if specified
** @param t_node *node - address of node for specific conversion
** @return 1 if only invalid character specifier was written to standard output
** @return field width if it as specified
*/

int	ft_print_invalid(t_node *node)
{
	int		field_width;
	char	fill;
	int		i;

	i = 0;
	fill = (ft_strchr(node->flags, '0')
	&& !ft_strchr(node->flags, '-') ? '0' : ' ');
	field_width = node->field_width;
	if (node->field_width == -1)
	{
		ft_putchar(node->conversion_specifier);
		return (1);
	}
	if (ft_strchr(node->flags, '-'))
		ft_putchar(node->conversion_specifier);
	while (field_width > 1)
	{
		ft_putchar(fill);
		field_width--;
	}
	if (!ft_strchr(node->flags, '-'))
		ft_putchar(node->conversion_specifier);
	return (node->field_width);
}
