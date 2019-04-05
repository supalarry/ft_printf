/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 12:26:07 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/12 12:26:09 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_address;
	unsigned char	*src_address;

	i = 0;
	dst_address = (unsigned char *)dst;
	src_address = (unsigned char *)src;
	while (i < n)
	{
		dst_address[i] = src_address[i];
		i++;
	}
	return (dst);
}
