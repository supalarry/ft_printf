/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 16:53:16 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/19 16:53:17 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n % 10 == n)
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		n = n + 48;
		write(1, &n, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		if (n < 0)
		{
			if (n == -2147483648)
			{
				write(1, "8", 1);
				return ;
			}
			n = -n;
		}
		n = n % 10 + 48;
		write(1, &n, 1);
	}
}
