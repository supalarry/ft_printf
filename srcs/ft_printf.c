/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/16 13:04:35 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/02/16 13:04:36 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

/*
** @desc Based on conversion character, call specific function
** @desc to print formatted data
** @param t_node *node - structure of a conversion specifier
** @param va_list ap - access point to variable arguments
** @return bytes written by individual function
*/

static int	ft_conversion(t_node *node, va_list ap)
{
	if (node->CS == 'c' || node->CS == 'C')
		return (ft_print_char(node, va_arg(ap, int)));
	else if (node->CS == 's' && ft_strcmp("l", node->length) != 0)
		return (ft_print_str(node, va_arg(ap, char *)));
	else if (node->CS == 'S'
	|| (node->CS == 's' && ft_strcmp("l", node->length) == 0))
		return (ft_print_wide_str(node, va_arg(ap, wchar_t*)));
	else if (node->CS == 'p' || node->CS == 'P')
		return (ft_print_ptr(node, va_arg(ap, void *)));
	else if (node->CS == 'd' || (node->CS == 'i')
	|| node->CS == 'D')
		return (ft_print_num(node, va_arg(ap, long long)));
	else if (node->CS == 'o' || node->CS == 'O')
		return (ft_print_oct(node, va_arg(ap, unsigned long long)));
	else if (node->CS == 'u' || node->CS == 'U')
		return (ft_print_unum(node, va_arg(ap, unsigned long long)));
	else if (node->CS == 'x')
		return (ft_print_hex(node, va_arg(ap, unsigned long long), 0));
	else if (node->CS == 'X')
		return (ft_print_hex(node, va_arg(ap, unsigned long long), 1));
	else if (node->CS == 'f' || node->CS == 'F')
		return (ft_print_f(node, va_arg(ap, double), node->precision));
	else if (node->CS == '%')
		return (ft_print_percent(node));
	return (ft_print_invalid(node));
}

/*
** @desc Skip invalid format specifier and move to next format specifier
** @desc in linked list
** @param const char *format - string to be formatted
** @param const char *i - address of current index in format string
** @param t_node **head - address of current link's address in ft_printf
** @return void
*/

static void	ft_invalid(const char *format, int *i, t_node **head)
{
	*head = (*head)->next;
	while (format[*i] == '#' || format[*i] == '0' || format[*i] == '-' ||
	format[*i] == '+' || format[*i] == ' ' || format[*i] == '%')
		(*i)++;
}

/*
** @desc Output valid format specifier
** @param const char *format - string to be formatted
** @param const char *i - address of current index in format string
** @param t_node **head - address of current link's address in ft_printf
** @param va_list ap - access point to variable arguments
** @return printed - bytes written to standard output
*/

static int	ft_valid(const char *format, int *i, t_node **head, va_list ap)
{
	int	printed;

	printed = ft_conversion(*head, ap);
	(*i)++;
	while (format[*i] != (*head)->conversion_specifier)
		(*i)++;
	(*i)++;
	*head = (*head)->next;
	return (printed);
}

/*
** @desc Output characters from format string that don't require formatting
** @param const char *format - string to be formatted
** @param const char *i - address of current index in format string
** @param const char *i - address of variable counting printed characters
** @return void
*/

static void	ft_char(const char *format, int *i, int *printed)
{
	ft_putchar(format[*i]);
	(*printed)++;
	(*i)++;
}

/*
** @desc Replication of C's printf function
** @param const char *format - string to be formatted
** @param ... - variable parameters containing conversion character's data
** @return printed - bytes written to standard output
*/

/*
** First, from format string all information about each conversion specifier is
** collected. Then, simple characters are written or formatted data is written
** or invalid cases are handled. Based on conversion character,
** a seperate function is launched.
*/

int			ft_printf(const char *format, ...)
{
	int		i;
	int		printed;
	t_node	*head;
	t_node	*head_copy;
	va_list	ap;

	i = 0;
	printed = 0;
	va_start(ap, format);
	head = ft_extract(format, ap);
	head_copy = head;
	while (format[i] != '\0')
	{
		if (format[i] != '\0' && format[i] != '%')
			ft_char(format, &i, &printed);
		else if (head != NULL && ((format[i] == '%' && head->error == 0)
		|| (format[i] == '%' && head->error != 0 && head->field_width != -2)))
			printed = printed + ft_valid(format, &i, &head, ap);
		else
			ft_invalid(format, &i, &head);
	}
	va_end(ap);
	ft_free_list(head_copy);
	return (printed);
}
