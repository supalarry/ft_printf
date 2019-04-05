/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 20:35:07 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/11 20:35:13 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	value;
	unsigned char	*address;

	value = (unsigned char)c;
	address = (unsigned char *)b;
	while (len)
	{
		*address = value;
		address++;
		len--;
	}
	return (b);
}
