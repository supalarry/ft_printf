/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 15:22:34 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/16 16:54:21 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	j = 0;
	while (i < size - 1 && src[j] != '\0' && size > 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (size != 0)
	{
		dst[i] = '\0';
	}
	if (size < dst_len)
		return (src_len + size);
	else
		return (src_len + dst_len);
}
