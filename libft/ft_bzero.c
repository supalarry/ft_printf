/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 12:00:37 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/12 12:00:40 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *address;

	address = (unsigned char *)s;
	while (n)
	{
		*address = 0;
		address++;
		n--;
	}
}
