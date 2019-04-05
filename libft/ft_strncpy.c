/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 11:07:54 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/13 11:07:55 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned char	*dst_address;
	unsigned char	*src_address;
	size_t			i;

	dst_address = (unsigned char *)dst;
	src_address = (unsigned char *)src;
	i = 0;
	while (i < len && src_address[i] != '\0')
	{
		dst_address[i] = src_address[i];
		i++;
	}
	while (i < len)
	{
		dst_address[i] = '\0';
		i++;
	}
	return (dst);
}
