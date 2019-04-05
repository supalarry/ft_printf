/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_str.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/05 14:35:20 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/03/05 14:35:21 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

/*
** @desc Output len characters from single byte character string
** @param char *str - string to be written
** @param int len - number of characters to output
** @return void
*/

static void	ft_putnstr(char *str, int len)
{
	int i;

	i = 0;
	while (str != NULL && i < len)
	{
		write(1, &str[i], 1);
		i++;
	}
}

/*
** @desc In case no field width is provided launch ft_putnstr
** @param char *str - string to be written
** @param int len - number of characters to output
** @return number of characters written
*/

static int	ft_negative_field_width(char *str, int len)
{
	ft_putnstr(str, len);
	return (len);
}

/*
** @desc In case field width is provided launch ft_putnstr
** @desc and store amount written, because field width has to be still written
** @param char *str - string to be written
** @param int len - number of characters to output
** @param int *ret - address of integer storing total characters printed
** @return void
*/

static void	ft_positive_field_width(char *str, int len, int *ret)
{
	ft_putnstr(str, len);
	*ret = *ret + len;
}

/*
** @desc Output a single byte character string
** @param t_node *node - structure of a conversion specifier
** @param char *str - string to be written
** @return number of characters written
*/

int			ft_print_str(t_node *node, char *str)
{
	int		field_width;
	char	fill;
	int		ret;
	int		len;

	ret = 0;
	str = (str == 0 ? "(null)" : str);
	len = (node->precision < (int)ft_strlen(str) && node->precision != -1
	? node->precision : (int)ft_strlen(str));
	fill = (ft_strchr(node->flags, '0')
	&& !ft_strchr(node->flags, '-') ? '0' : ' ');
	field_width = node->field_width;
	if (node->field_width == -1)
		return (ft_negative_field_width(str, len));
	if (ft_strchr(node->flags, '-'))
		ft_positive_field_width(str, len, &ret);
	while (field_width > len)
	{
		ft_putchar(fill);
		field_width--;
		ret++;
	}
	if (!ft_strchr(node->flags, '-'))
		ft_positive_field_width(str, len, &ret);
	return (ret);
}
