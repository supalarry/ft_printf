/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 11:40:03 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/01/18 11:40:05 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*strnew;

	i = 0;
	strnew = (char *)malloc(++size);
	if (strnew != NULL)
	{
		while (i < size)
		{
			strnew[i] = '\0';
			i++;
		}
	}
	return (strnew);
}
