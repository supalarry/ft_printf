/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 19:11:05 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/19 19:11:07 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n % 10 == n)
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		n = n + 48;
		write(fd, &n, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		if (n < 0)
		{
			if (n == -2147483648)
			{
				write(fd, "8", 1);
				return ;
			}
			n = -n;
		}
		n = n % 10 + 48;
		write(fd, &n, 1);
	}
}
