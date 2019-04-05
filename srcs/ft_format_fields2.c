/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_format_fields2.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/07 14:50:38 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/03/07 14:50:39 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

/*
** @desc Determine number width to find if '*' follows field width
** @param int num - field width in conversion specifier
** @return i - length of a number
*/

int		ft_num_width(int num)
{
	int i;

	i = 0;
	if (num == 0)
		i++;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

/*
** @desc Extract field width and handle wildcard '*' character
** @param t_node *node - address of node for specific conversion
** @param va_list ap - access point for variable arguments
** @param int *i - index of current position in format string
** @param int *pos - address of integer storing digit's width
** @return void
*/

void	ft_field_width2(t_node *node, va_list ap, int *i, int *pos)
{
	if (ft_isdigit(node->format[*i]))
	{
		*pos = ft_num_width(ft_atoi(&(node->format[*i])));
		if (node->format[*i + *pos] != '*')
			node->field_width = ft_atoi(&(node->format[*i]));
		else
			node->field_width = va_arg(ap, int);
	}
	else if (node->format[*i] == '*' && !ft_isdigit(node->format[*i + 1])
	&& node->field_width == -3)
	{
		node->field_width = va_arg(ap, int);
		if (node->field_width < 0)
		{
			node->flags[node->flag_pos] = '-';
			node->flags[node->flag_pos + 1] = '\0';
			node->field_width = node->field_width * -1;
		}
	}
	else if (node->format[*i] == '*' && ft_isdigit(node->format[*i + 1]))
	{
		(*i)++;
		va_arg(ap, int);
		node->field_width = ft_atoi(&(node->format[*i]));
	}
}

/*
** @desc Extract precision and handle wildcard '*' character
** @param t_node *node - address of node for specific conversion
** @param va_list ap - access point for variable arguments
** @param int *i - index of current position in format string
** @return void
*/

void	ft_precision2(t_node *node, va_list ap, int *i)
{
	if (ft_isdigit(node->format[*i]))
		node->precision = ft_atoi(&(node->format[*i]));
	else if (node->format[*i] == '*')
	{
		node->precision = va_arg(ap, int);
		if (node->precision < 0)
			node->precision = -1;
	}
}
