/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_format_fields.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/17 13:37:21 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/02/17 13:37:22 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

/*
** @desc Extract flags if there are any
** @param t_node *node - address of node for specific conversion
** @param const char *format - string to be formatted
** @param const char *i - address of current index in format string
** @param va_list ap - access point to variable arguments
** @return 1 if flag was found or if it was not found, field width,
** @return precision, length or character specifier owns the symbol/symbols
** @return 0 if no flags were found, and characters are invalid also
** @return for field width, precision, length and character specifier
*/

int			ft_flags(t_node *node, const char *format, int *i, va_list ap)
{
	int j;

	j = 0;
	while (format[*i] == '#' || format[*i] == '0' || format[*i] == '-' ||
	format[*i] == '+' || format[*i] == ' ')
	{
		node->flags[j] = format[*i];
		j++;
		(*i)++;
	}
	node->flags[j] = '\0';
	node->flag_pos = j;
	if (ft_field_width(node, ap, i, 1) != 1)
	{
		node->error = (char *)format + (*i);
		return (0);
	}
	return (1);
}

/*
** @desc Extract field width if it is specified
** @param t_node *node - address of node for specific conversion
** @param va_list ap - access point to variable arguments
** @param const char *i - address of current index in format string
** @param int check - 1 if this function is called from previous function,
** @param to check if characters are valid, 0 if call is made seperately
** @return 1 if field width was found or if it was not found,
** @return precision, length or chracter specifier owns the symbols
** @return 0 if no field width was found, and characters are invalid also
** @return for precision, length and character specifier
*/

int			ft_field_width(t_node *node, va_list ap, int *i, int check)
{
	int pos;

	pos = 0;
	if (ft_isdigit(node->format[*i]) || node->format[*i] == '*')
	{
		if (check == 1)
			return (1);
		ft_field_width2(node, ap, i, &pos);
		while (ft_isdigit(node->format[*i]) || node->format[*i] == '*')
			(*i)++;
	}
	else if (ft_precision(node, ap, i, 1) != 1)
	{
		node->error = (char *)node->format + (*i);
		node->field_width = -2;
		return (0);
	}
	else
		node->field_width = -1;
	return (1);
}

/*
** @desc Extract precision if it is specified
** @param t_node *node - address of node for specific conversion
** @param va_list ap - access point to variable arguments
** @param const char *i - address of current index in format string
** @param int check - 1 if this function is called from previous function,
** @param to check if characters are valid, 0 if call is made seperately
** @return 1 if precision was found or if it was not found,
** @return length or chracter specifier owns the symbols
** @return 0 if no precision was found, and characters are invalid also
** @return for length and chracter specifier
*/

int			ft_precision(t_node *node, va_list ap, int *i, int check)
{
	if (node->format[*i] == '.'
	&& (ft_isdigit(node->format[*i + 1]) || node->format[*i + 1] == '*'))
	{
		if (check == 1)
			return (1);
		(*i)++;
		ft_precision2(node, ap, i);
		while (ft_isdigit(node->format[*i]) || node->format[*i] == '*')
			(*i)++;
	}
	else if (node->format[*i] == '.')
	{
		if (check == 1)
			return (1);
		(*i)++;
		node->precision = 0;
	}
	else if (ft_length(node, node->format, i, 1) != 1)
	{
		node->error = (char *)node->format + (*i);
		return (0);
	}
	else
		node->precision = -1;
	return (1);
}

/*
** @desc Extract length if it is specified
** @param t_node *node - address of node for specific conversion
** @param const char *f - string to be formatted
** @param const char *i - address of current index in format string
** @param int check - 1 if this function is called from previous function,
** @param to check if characters are valid, 0 if call is made seperately
** @return 1 if length was found or if it was not found,
** @return character specifier owns the symbols
** @return 0 if no length was found, and characters are invalid also
** @return for character specifier.
*/

int			ft_length(t_node *node, const char *f, int *i, int check)
{
	ft_bzero(node->length, 3);
	if ((f[*i] == 'h' && f[*i + 1] == 'h')
	|| (f[*i] == 'l' && f[*i + 1] == 'l'))
	{
		if (check == 1)
			return (1);
		ft_memcpy(node->length, &f[*i], 2);
		(*i) = (*i) + 2;
		node->length[2] = '\0';
	}
	else if (f[*i] == 'h' || f[*i] == 'l' || f[*i] == 'L' || f[*i] == 'j'
	|| f[*i] == 'z')
	{
		if (check == 1)
			return (1);
		ft_memcpy(node->length, &f[*i], 1);
		(*i) = (*i) + 1;
		node->length[1] = '\0';
	}
	else if (ft_conversion_specifier(node, f, i) != 1)
		return (0);
	else
		node->length[0] = '\0';
	return (1);
}

/*
** @desc Extract conversion specifier
** @param t_node *node - address of node for specific conversion
** @param const char *format - string to be formatted
** @param const char *i - address of current index in format string
** @return 1 if a valid character specifier was found
** @return 0 if an invalid conversion specifier was found
*/

int			ft_conversion_specifier(t_node *node, const char *format, int *i)
{
	if (format[*i] == 'c' || format[*i] == 'C'
	|| format[*i] == 's' || format[*i] == 'S'
	|| format[*i] == 'p' || format[*i] == 'P'
	|| format[*i] == 'd' || format[*i] == 'D'
	|| format[*i] == 'i' || format[*i] == 'I'
	|| format[*i] == 'o' || format[*i] == 'O'
	|| format[*i] == 'u' || format[*i] == 'U'
	|| format[*i] == 'f' || format[*i] == 'F'
	|| format[*i] == '%')
		node->conversion_specifier = format[*i];
	else if (format[*i] == 'x')
		node->conversion_specifier = 'x';
	else if (format[*i] == 'X')
		node->conversion_specifier = 'X';
	else
	{
		node->error = (char *)format + (*i);
		node->conversion_specifier = format[*i];
		return (0);
	}
	return (1);
}
