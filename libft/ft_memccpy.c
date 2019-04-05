/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 14:37:51 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/12 14:37:52 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	val;
	unsigned char	*dst_address;
	unsigned char	*src_address;

	i = 0;
	val = (unsigned char)c;
	dst_address = (unsigned char *)dst;
	src_address = (unsigned char *)src;
	while (n)
	{
		dst_address[i] = src_address[i];
		if (dst_address[i] == val)
		{
			return (dst_address + i + 1);
		}
		i++;
		n--;
	}
	return (NULL);
}
