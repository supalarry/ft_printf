/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 20:09:12 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/12 20:09:14 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	val;
	unsigned char	*address;

	i = 0;
	val = (unsigned char)c;
	address = (unsigned char *)s;
	while (n)
	{
		if (address[i] == val)
		{
			return (address + i);
		}
		i++;
		n--;
	}
	return (NULL);
}
