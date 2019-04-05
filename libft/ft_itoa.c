/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 13:15:52 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/19 13:15:53 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int n)
{
	size_t len;

	len = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
	{
		len++;
	}
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void		ft_fill(char *number, int j, int n)
{
	static int		i;

	i = j;
	if (n % 10 == n)
	{
		number[i] = n + 48;
		i++;
	}
	else
	{
		ft_fill(number, i, n / 10);
		number[i] = (n % 10) + 48;
		i++;
	}
}

char			*ft_itoa(int n)
{
	int				i;
	size_t			len;
	char			*number;

	i = 0;
	if (n == -0)
		n = 0;
	len = ft_len(n);
	number = (char *)malloc(len + 1);
	if (number != NULL)
	{
		if (n < 0)
		{
			number[i++] = '-';
			if (n == -2147483648)
			{
				number[10] = '8';
				n = n / 10;
			}
			n = -n;
		}
		ft_fill(number, i, n);
		number[len] = '\0';
	}
	return (number);
}
