/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_wstr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/05 14:34:37 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/03/05 14:34:39 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

/*
** @desc In case, if field width is not specified
** @param t_node *node - address of node for specific conversion
** @param wchar_t *str - multibyte string
** @param int len - number of characters to be printed
** @return bytes printed
** @return 6 for displaying (null) if precision is 0 and str is NULL
** @return 0 if invalid case occured
*/

static int	ft_negative_field_width(t_node *node, wchar_t *str, int len)
{
	if (str != NULL)
		return (ft_wchar_putnstr(node, str, len));
	else if (node->precision != 0)
	{
		ft_putstr("(null)");
		return (6);
	}
	return (0);
}

/*
** @desc In case, if field width is specified
** @param t_node *n - address of node for specific conversion
** @param wchar_t *str - multibyte string
** @param int len - number of characters to be printed
** @param int *ret - address of integer storing bytes printed
** @return void
*/

static void	ft_positive_field_width(t_node *n, wchar_t *str, int len, int *ret)
{
	if (str != NULL)
	{
		*ret = *ret + ft_wchar_putnstr(n, str, len);
	}
	else if (n->precision != 0)
	{
		ft_putstr("(null)");
		*ret = *ret + 6;
	}
}

/*
** @desc Output characters specified by precision or whole multibyte string
** @param t_node *node - address of node for specific conversion
** @param wchar_t *str - multibyte string
** @return count - number of charactes printed
*/

static int	ft_print_count(t_node *node, wchar_t *str)
{
	int	count;
	int size;

	count = 0;
	size = 0;
	if (node->precision != -1 && node->precision < (int)ft_wchar_bytes(str))
	{
		while (size + (int)ft_wchar_size(str[count]) <= node->precision)
		{
			size = size + (int)ft_wchar_size(str[count]);
			count++;
		}
	}
	else
	{
		if (str != NULL)
		{
			while (str[count] != '\0')
				count++;
		}
	}
	return (count);
}

/*
** @desc Determine size in bytes for len amount of characters
** @param wchar_t *str - multibyte string
** @param int len - number of characters to be measured
** @return size - size in bytes of len characters
*/

static int	ft_count_size(wchar_t *s, int len)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	if (s != NULL)
	{
		while (i < len)
		{
			if (s[i] > 0x0 && s[i] <= 0x7F)
				size = size + 1;
			else if (s[i] >= 0x80 && s[i] <= 0x7FF)
				size = size + 2;
			else if (s[i] >= 0x800 && s[i] <= 0xFFFF)
				size = size + 3;
			else if (s[i] >= 0x10000 && s[i] <= 0x10FFFF)
				size = size + 4;
			i++;
		}
	}
	return (size);
}

/*
** @desc Outputs multibyte string
** @param t_node *node - address of node for specific conversion
** @param wchar_t *str - multibyte string
** @return ret - bytes written to standard output
*/

int			ft_print_wide_str(t_node *node, wchar_t *str)
{
	int		field_width;
	char	fill;
	int		ret;
	int		len;
	int		size;

	ret = 0;
	len = ft_print_count(node, str);
	size = ft_count_size(str, len);
	fill = (ft_strchr(node->flags, '0')
	&& !ft_strchr(node->flags, '-') ? '0' : ' ');
	field_width = node->field_width;
	if (node->field_width == -1)
		return (ft_negative_field_width(node, str, len));
	if (ft_strchr(node->flags, '-'))
		ft_positive_field_width(node, str, len, &ret);
	while (field_width > size)
	{
		ft_putchar(fill);
		field_width--;
		ret++;
	}
	if (!ft_strchr(node->flags, '-'))
		ft_positive_field_width(node, str, len, &ret);
	return (ret);
}
