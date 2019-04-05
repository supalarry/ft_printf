/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 16:38:03 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/12 16:38:05 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst_address;
	unsigned char	*src_address;

	i = 0;
	dst_address = (unsigned char *)dst;
	src_address = (unsigned char *)src;
	if (src_address < dst_address)
	{
		while (i < len)
		{
			len--;
			dst_address[len] = src_address[len];
		}
	}
	else
	{
		while (i < len)
		{
			dst_address[i] = src_address[i];
			i++;
		}
	}
	return (dst);
}
