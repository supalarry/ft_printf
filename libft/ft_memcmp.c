/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 09:51:12 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/13 09:51:13 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_address;
	unsigned char	*s2_address;

	i = 0;
	s1_address = (unsigned char *)s1;
	s2_address = (unsigned char *)s2;
	while (i < n)
	{
		if (s1_address[i] != s2_address[i])
		{
			return (s1_address[i] - s2_address[i]);
		}
		i++;
	}
	return (0);
}
