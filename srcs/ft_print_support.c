/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_support.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 19:16:04 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/02/20 19:16:06 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

/*
** @desc Output hexadecimal number from decimal
** @param t_node *node - address of node for specific conversion
** @param unsigned long long n - decimal for conversion
** @param int capital - 1 to output capital letters, 0 for small
** @return void
*/

void	ft_puthex(t_node *node, unsigned long long n, int capital)
{
	int		a;

	if (n == 0 && node->precision == 0)
		return ;
	a = (capital == 1 ? 'A' : 'a');
	if (n % 16 == n)
	{
		if (n <= 9)
			n = n + 48;
		else
			n = n - 10 + a;
		ft_putchar(n);
	}
	else
	{
		ft_puthex(node, n / 16, capital);
		n = n % 16;
		if (n <= 9)
			n = n + 48;
		else
			n = n - 10 + a;
		ft_putchar(n);
	}
}

/*
** @desc Output octal number from decimal
** @param t_node *node - address of node for specific conversion
** @param unsigned long long n - decimal for conversion
** @return void
*/

void	ft_putoct(t_node *node, unsigned long long n)
{
	if (n == 0 && (node->precision == 0 || ft_strchr(node->flags, '#')))
		return ;
	if (n % 8 == n)
	{
		n = n + 48;
		ft_putchar(n);
	}
	else
	{
		ft_putoct(node, n / 8);
		n = n % 8 + 48;
		ft_putchar(n);
	}
}

/*
** @desc Output decimal number
** @param t_node *node - address of node for specific conversion
** @param long long n - decimal for conversion
** @return void
*/

void	ft_putdi(t_node *node, long long n)
{
	if (n == 0 && node->precision == 0)
		return ;
	if (n % 10 == n)
	{
		if (n > 0)
			n = n + 48;
		else
			n = n * -1 + 48;
		ft_putchar(n);
	}
	else
	{
		ft_putdi(node, n / 10);
		if (n > 0)
			n = n % 10 + 48;
		else
			n = n % 10 * -1 + 48;
		ft_putchar(n);
	}
}

/*
** @desc Output unsigned decimal number
** @param t_node *node - address of node for specific conversion
** @param unsigned long long n - unsigned number for conversion
** @return void
*/

void	ft_putunum(t_node *node, unsigned long long n)
{
	if (n == 0 && node->precision == 0)
		return ;
	if (n % 10 == n)
	{
		n = n + 48;
		ft_putchar(n);
	}
	else
	{
		ft_putunum(node, n / 10);
		n = n % 10 + 48;
		ft_putchar(n);
	}
}
